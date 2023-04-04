#include <bits/stdc++.h>
#define ll long long
#define INF 1e18
#define pii pair<int, int>
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define popcount(x) __builtin_popcount(x)
#define setp(x) setprecision(x)
#define MASK(x) (1LL << (x))
#define BIT(x, i) ((x) >> (i) & 1)
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e6 + 10;
const int MOD = 998244353;
int numNode, numCity, m, numCheck;
ll f[10][NM], ans[NM];

struct Data {
    int v;
    ll cost;

    Data(int _v = 0, ll _cost = 0){
        v = _v; cost = _cost;
    }
};
vector<Data> edges[NM];

struct Road {
    int u;
    ll cost;

    Road(int _u = 0, ll _cost = 0){
        u = _u; cost = _cost;
    }

    bool inline operator < (const Road &A) const {
        return cost > A.cost;
    }
};

void Dijkstra(int x) {
    for(int i = 1; i <= numNode; i++) f[x][i] = INF;
    priority_queue<Road> pq;
    f[x][x] = 0;
    pq.push(Road(x, 0));

    while(!pq.empty()){
        int u = pq.top().u;
        ll cost = pq.top().cost;

        pq.pop();
        if(cost != f[x][u]) continue;

        for(Data v : edges[u]){
            if(minimize(f[x][v.v], cost + v.cost))
                pq.push(Road(v.v, cost + v.cost));
        }
    }
}
ll pw(int x, int k){
    if(k == 1) return x;
    if(k == 0) return 0;
    ll tmp = pw(x, k / 2);
    if(k % 2 == 0) return tmp * tmp % MOD;
    else return tmp * tmp % MOD * x % MOD;
}
void xuli(){
    for(int i = 1; i <= numCheck; i++) Dijkstra(i);

    for(int i = 1; i <= numCheck; i++){
        for(int j = 1; j <= numNode - numCity; j++) {
            ll cost = (f[i][j] < INF ? f[i][j] / 2 : -1) % MOD;
            ans[j] = (ans[j] + (cost * pw(i, i) % MOD + MOD) % MOD) % MOD;
            while(ans[j] < 0) ans[j] += MOD;
        }
    }
    for(int i = 1; i <= numNode - numCity; i++) cout << ans[i] << " ";
}
int32_t main()
{
    FastIO
    freopen("HANOICITY.INP", "r", stdin);
    freopen("HANOICITY.OUT", "w", stdout);
    cin >> numNode >> numCity >> m;
    for(int i = 1; i <= numCity; i++){
        int newCity = numNode + i;
        ll t, w; cin >> t >> w;
        for(int j = 1; j <= t; j++){
            int u; cin >> u;
            edges[u].push_back(Data(newCity, w));
            edges[newCity].push_back(Data(u, w));
        }
    }
    for(int i = 1; i <= m; i++){
        ll u, v, w;
        cin >> u >> v >> w;
        edges[u].push_back(Data(v, 2 * w));
        edges[v].push_back(Data(u, 2 * w));
    }
    cin >> numCheck;
    numNode += numCity;

    xuli();
    return 0;
}

/* Author: hxzinh */

/*
-----code ko bug-----code ko bug-----code ko bug--------------

          _.-/`)
         // / / )
      .=// / / / )
     //`/ / / / /
    // /     ` /
   ||         /
    \\       /
     ))    .'
    //    /
         /
*/
