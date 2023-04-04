#include <bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f3f
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 230;
int n;
int a[NM][NM];
int r[NM][NM];

struct EDGE {
    int v, cost;
};
vector<EDGE> edges[NM];

struct Data {
    int u, v, cost;

    bool inline operator < (const Data &A) const {
        return cost > A.cost;
    }
};
vector<Data> ans;

void Karuskal(){
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++) if(i != j) if(r[i][j] > r[i][k] + r[k][j])
                r[i][j] = r[i][k] + r[k][j];
        }
    }
}
void sub1(){
    priority_queue<Data> pq;
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++) pq.push({i, j, a[i][j]});
    }

    memset(r, INF, sizeof r);
    while(pq.size()){
        int u = pq.top().u, v = pq.top().v, cost = pq.top().cost;
        pq.pop();
        if(r[u][v] > cost) r[u][v] = r[v][u] = cost;
        else continue;
        ans.push_back({u, v, cost});
        Karuskal();
    }

    cout << ans.size() << '\n';
    for(auto road : ans){
        cout << road.u << " " << road.v << " " << road.cost << '\n';
    }
}
void xuli(){
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            bool ok = true;
            for(int k = 1; k <= n; k++) if(k != i && k != j) {
                if(a[i][j] >= a[i][k] + a[k][j]){
                    ok = false;
                    break;
                }
            }
            if(ok) ans.push_back({i, j, a[i][j]});
        }
    }

    cout << ans.size() << '\n';
    for(auto road : ans){
        cout << road.u << " " << road.v << " " << road.cost << '\n';
    }
}
int32_t main()
{
    FastIO
    freopen("SHORTEST.INP", "r", stdin);
    freopen("SHORTEST.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
            if(i != j) edges[i].push_back({j, a[i][j]});
        }
    }

    if(n <= 6) sub1();
    else xuli();
    return 0;
}
