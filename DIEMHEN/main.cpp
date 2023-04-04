#include <bits/stdc++.h>
#define int unsigned long long
#define INF 1e18
#define ii pair<int, int>
#define fi first
#define se second
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e5 + 10;
int n, m, q, k, k1, k2;
int dist[NM], s[NM];

struct Data {
    int v, cost;
    bool inline operator < (const Data &A) const {
        return cost > A.cost;
    }
};
vector<Data> edges[NM];

void readfile(){
    freopen("DIEMHEN.INP", "r", stdin);
    freopen("DIEMHEN.OUT", "w", stdout);
    cin >> n >> m >> q;
    for(int i = 1; i <= m; i++){
        int u, v, cost;
        cin >> u >> v >> cost;
        edges[u].push_back({v, cost});
    }
}
void sub2(){
    for(int i = 1; i <= n; i++) dist[i] = s[i] = INF;

    priority_queue<Data> pq;
    dist[1] = 0;
    pq.push({1, 0});
    while(!pq.empty()){
        int u = pq.top().v, cost = pq.top().cost;
        pq.pop();
        if(dist[u] != cost) continue;
        for(auto v : edges[u]){
            if(dist[v.v] > dist[u] + v.cost){
                dist[v.v] = dist[u] +v.cost;
                pq.push({v.v, dist[v.v]});
            }
        }
    }
    while(!pq.empty()) pq.pop();
    s[n] = 0;
    pq.push({n, 0});
    while(!pq.empty()){
        int u = pq.top().v, cost = pq.top().cost;
        pq.pop();
        if(s[u] != cost) continue;
        for(auto v : edges[u]){
            if(s[v.v] > s[u] + v.cost){
                s[v.v] = s[u] +v.cost;
                pq.push({v.v, s[v.v]});
            }
        }
    }

    vector<int> place;
    for(int i = 1; i <= n; i++){
        if(dist[i] < INF && s[i] < INF) place.push_back(i);
    }
    while(q--){
        int res = INF;
        cin >> k1 >> k2;
        for(int u : place){
            int tam = dist[u] * k1 + s[u] * k2;
            minimize(res, tam);
        }
        cout << res << '\n';
    }
}
int32_t main()
{
    FastIO
    readfile();
    sub2();
    return 0;
}
