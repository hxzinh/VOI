#include <bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define popcount(x) __builtin_popcount(x)
#define set(x) setprecision(x)
#define MASK(x) (1LL << (x))
#define BIT(x, i) ((x) >> (i) & 1)
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e5 + 10;
int n, m, T;
int result = -1;
int a[NM], b[NM], c[NM];
vector<int> trace;
bool cx[NM];

struct EDGE {
    int u, v, id;
};
vector<EDGE> Adges, Bdges;

struct DSU {
    vector<int> par, Rank;

    DSU(int _n = 0){
        par.assign(n + 7, 0);
        Rank.assign(n + 7, 0);
        for(int i = 1; i <= n; i++) par[i] = i;
    }

    int root(int x){
        if(par[x] != x) return par[x] = root(par[x]);
        else return par[x];
    }

    bool join(int u, int v){
        u = root(u), v = root(v);
        if(u == v) return false;
        if(Rank[u] == Rank[v]) Rank[u]++;
        if(Rank[u] > Rank[v]) par[v] = u;
        else par[u] = v;
        return true;
    }

    void rollback(){
        for(int i = 1; i <= n; i++){
            par[i] = i;
            Rank[i] = 0;
        }
    }
};

void sub2(){
    for(int i = 1; i < n; i++) c[i] = a[i] + b[n - 1 - i];

    int res = INF;
    for(int i = 0; i < Bdges.size(); i++){
        int u = Bdges[i].u, v = Bdges[i].v;
        if(!cx[u] || !cx[v]) cx[u] = cx[v] = true;
    }
    vector<int> taked;
    for(int i = 0; i < Adges.size(); i++){
        int u = Bdges[i].u, v = Bdges[i].v;
        if(!cx[u] || !cx[v]){
            cx[u] = cx[v] = true;
            taked.push_back(Adges[i].id);
        }
    }


}
void Renew(){
    Adges.clear();
    Bdges.clear();
    memset(cx, false, sizeof cx);
}
void xuli(){
    for(int i = 0; i < n; i++) c[i] = a[i] + b[n - 1 - i];

    DSU dsu(n);
    int maxAdges = 0, maxBdges = 0;
    for(auto &u : Adges) if(dsu.join(u.u, u.v)) maxAdges++;
    dsu.rollback();
    for(auto &u : Bdges) if(dsu.join(u.u, u.v)) maxBdges++;

    int res = INF;
    int minAdges = n - 1 - maxBdges, t = -1;
    for(int i = minAdges; i <= maxAdges; i++){
        if(minimize(res, c[i])) t = i;
    }

    for(auto u : Adges) cx[u.id] = dsu.join(u.u, u.v);
    dsu.rollback();
    for(auto u : Adges) if(cx[u.id]){
        dsu.join(u.u, u.v);
        t--;
    }
    if(t)
    for(auto &u : Adges) if(dsu.join(u.u, u.v)){
        cx[u.id] = true;
        t--;
        if(t == 0) break;
    }
    for(auto &u : Bdges) if(dsu.join(u.u, u.v)) cx[u.id] = true;

    for(int i = 1; i <= m; i++) if(cx[i]) cout << i << " ";
    cout << '\n';
}
int32_t main()
{
    FastIO
    freopen("AZNET.INP", "r", stdin);
    freopen("AZNET.OUT", "w", stdout);
    cin >> T;
    while(T--){
        cin >> n >> m;
        Renew();
        for(int i = 1; i < n; i++) cin >> a[i];
        for(int i = 1; i < n; i++) cin >> b[i];
        for(int i = 1; i <= m; i++){
            int u, v, type;
            cin >> u >> v >> type;
            if(type == 1) Adges.push_back({u, v, i});
            else Bdges.push_back({u, v, i});
        }

        xuli();
    }
    return 0;
}
