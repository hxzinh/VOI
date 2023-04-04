#include <bits/stdc++.h>
#define int long long
#define INF 1e18
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e5 + 10;
int n, m, k;
int f[NM][20];

struct Data {
    int v, cost;
};
vector<Data> edges[NM];

struct Meow {
    int u, cost, ticket;

    bool inline operator < (const Meow &A) const {
        return cost > A.cost;
    }
};

void readfile(){
    freopen("SHORTESTDK.INP", "r", stdin);
    freopen("SHORTESTDK.OUT", "w", stdout);
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        edges[u].push_back({v, w});
        edges[v].push_back({u, w});
    }
}
void xuli(){
    for(int i = 1; i <= n; i++)
        for(int j = 0; j <= k; j++) f[i][j] = INF;

    f[1][0] = 0;
    priority_queue<Meow> pq;
    pq.push({1, 0, 0});
    while(!pq.empty()){
        Meow u = pq.top();
        pq.pop();
        if(f[u.u][u.ticket] != u.cost) continue;
        for(Data v : edges[u.u]){
            if(minimize(f[v.v][u.ticket], u.cost + v.cost))
                pq.push({v.v, f[v.v][u.ticket], u.ticket});
            if(u.ticket < k && minimize(f[v.v][u.ticket + 1], f[u.u][u.ticket]))
                pq.push({v.v, u.cost, u.ticket + 1});
        }
    }
    for(int i = 1; i <= n; i++){
        int res = INF;
        for(int j = 0; j <= k; j++) minimize(res, f[i][j]);
        cout << res << " ";
    }
}
int32_t main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
