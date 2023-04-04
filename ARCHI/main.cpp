#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
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
const int MAX = 4e6 + 10;
int n, q;
int par[NM], high[NM], P[NM][22], idx[NM];
vector<int> edges[NM];

struct Archi {
    int x, y, u, v;
} a[NM];

struct Storage {
    int x, down, up, id, type;

    bool inline operator < (const Storage &A) const {
        return (x == A.x ? type > A.type : x > A.x);
    }

} b[MAX];

struct Data {
    int down, up, id;

    bool operator < (const Data &A) const {
        return (up < A.up || (up == A.up && down > A.down || (down == A.down && id < A.id)));
    }
};

void dfs(int u, int p){
    for(int v : edges[u]) if(v != p){
        high[v] = high[u] + 1;
        dfs(v, u);
        par[v] = u;
    }
}
void makeLca(){
    for(int i = 1; i <= n; i++) P[i][0] = par[i];

    for(int k = 1; k <= 20; k++)
        for(int i = 1; i <= n; i++) P[i][k] = P[P[i][k - 1]][k - 1];
}
int getLCA(int u, int v){
    if(high[u] < high[v]) swap(u, v);

    for(int i = 20; i >= 0; i--)
        if(high[P[u][i]] >= high[v]) u = P[u][i];

    if(u == v) return u;

    for(int i = 20; i >= 0; i--)
        if(P[u][i] != P[v][i]){
            u = P[u][i];
            v = P[v][i];
        }

    return par[u];
}
void full(){
    int cnt = 0;
    priority_queue<Storage> pq;
    for(int i = 1; i <= n; i++){
        pq.push({a[i].x, a[i].y, a[i].v, i, 1});
        pq.push({a[i].u, a[i].y, a[i].v, i, -1});
    }
    for(int i = 1; i <= q; i++){
        int x, y, u, v;
        cin >> x >> y >> u >> v;
        pq.push({x, y, y, 2 * i, 0});
        pq.push({u, v, v, 2 * i + 1, 0});
    }

    set<Data> S;
    while(!pq.empty()){
        Storage u = pq.top();
        pq.pop();

        if(S.empty()){
            S.insert({u.down, u.up, u.id});
            continue;
        }

        if(u.type == 1){
            auto it = S.upper_bound({u.down, u.up, u.id});
            edges[it->id].push_back(u.id);
            Data rec = {it->down, it->up, it->id};
            S.insert({u.down, u.up, u.id});
            S.insert({u.up, rec.up, rec.id});
            S.insert({rec.down, u.down, rec.id});
            pq.push({a[u.id].u, u.up, rec.up, rec.id, -1});
            pq.push({a[u.id].u, rec.down, u.down, rec.id, -1});
        }

        if(u.type == 0){
            auto it = S.upper_bound({u.down, u.up, u.id});
            idx[u.id] = it->id;
            continue;
        }

        if(u.type == -1){
            auto it = S.lower_bound({u.down, u.up, u.id});
            S.erase(it);
        }



        //for(auto u : S) cout << u.down << " " << u.up << " " << u.id << '\n';
        //cout << '\n';
    }

    dfs(1, 0);
    makeLca();

    for(int i = 1; i <= q; i++){
        int u = idx[2 * i], v = idx[2 * i + 1];
        int tmp = getLCA(u, v);
        int res = high[u] + high[v] - 2 * high[tmp];
        cout << res << '\n';
    }
}
int32_t main()
{
    FastIO
    freopen("ARCHI.INP", "r", stdin);
    freopen("ARCHI.OUT", "w", stdout);
    cin >> n >> q;
    a[1] = {-INF, -INF, INF, INF};
    n++;
    for(int i = 2; i <= n; i++){
        int x, y, u, v;
        cin >> x >> y >> u >> v;
        a[i] = {x, y, u, v};
    }

    full();
    return 0;
}

/* Author: hxzinh */

/*

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
