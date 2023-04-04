#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e4 + 10;
int n, k, m, T;
int f[105][NM];

struct Road {
    int v, len, w;
};
vector<Road> edges[105];

struct Data {
    int u, len, cost;

    bool inline operator < (const Data &A) const {
        return (cost == A.cost ? len > A.len : cost > A.cost);
    }
};

void init(){
    for(int i = 1; i <= n; i++) edges[i].clear();
}
void xuli(){
    memset(f, INF, sizeof f);
    priority_queue<Data> pq;
    f[1][0] = 0;
    pq.push({1, 0, 0});

    while(!pq.empty()){
        int u = pq.top().u, len = pq.top().len, cost = pq.top().cost;
        pq.pop();

        if(len != f[u][cost]) continue;
        for(auto v : edges[u]) if(cost + v.w <= k) {
            if(minimize(f[v.v][cost + v.w], f[u][cost] + v.len))
                pq.push({v.v, f[v.v][cost + v.w], cost + v.w});
        }
    }

    int res = INF;
    for(int i = 0; i <= k; i++) minimize(res, f[n][i]);
    cout << (res < INF ? res : -1) << '\n';
}
int main()
{
    FastIO
    freopen("ROADS.INP", "r", stdin);
    freopen("ROADS.OUT", "w", stdout);
    cin >> T;
    while(T--){
        init();
        cin >> k >> n >> m;
        for(int i = 1; i <= m; i++){
            int x, y, len, cost;
            cin >> x >> y >> len >> cost;
            edges[x].push_back({y, len, cost});
        }

        xuli();
    }
    return 0;
}
