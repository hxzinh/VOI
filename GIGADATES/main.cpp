#include <bits/stdc++.h>
#define int long long
#define ll long long
#define fi first
#define se second
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int MAX = 1500010;
const int NM = 3e5 + 10;
int n, sub;
int a[NM], id[MAX], cntRoad[MAX];
vector<pair<int, int>> edges[MAX];

struct DijoinsetUnion {
    int n;
    vector<int> par;

    DijoinsetUnion(int _n = 0){
        n = _n;
        par.assign(n + 7, -1);
    }

    int root(int x){
        return par[x] < 0 ? x : (par[x] = root(par[x]));
    }

    long long mergee(ll u, ll v){
        int x = root(u);
        int y = root(v);
        if(x == y) return 0;
        if(par[x] > par[y]) swap(x, y);
        ll res = 1LL * par[x] * par[y];
        par[x] += par[y];
        par[y] = x;
        return res;
    }
};

long long getNumRoad(int x){
    int cnt = 0;
    for(int i = x; i <= MAX; i += x){
        for(auto j : edges[i]){
            id[j.fi] = ++cnt;
            id[j.se] = ++cnt;
        }
    }
    if(cnt == 0) return 0;

    DijoinsetUnion dsu(cnt);
    long long res = 0;
    for(int i = x; i <= MAX; i += x){
        for(auto j : edges[i]){
            res += dsu.mergee(id[j.fi], id[j.se]);
        }
    }
    for(int i = x; i <= MAX; i += x)
        for(auto j : edges[i]) id[j.fi] = id[j.se] = 0;
    return res;
};

void readfile(){
    freopen("GCDPATH.INP", "r", stdin);
    freopen("GCDPATH.OUT", "w", stdout);
    cin >> sub >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        edges[__gcd(a[u], a[v])].push_back({u, v});
    }
}
void prepare(){
    for(int i = 1; i < MAX; i++)
        cntRoad[i] = getNumRoad(i);
    for(int i = MAX - 1; i >= 1; i--)
        for(int j = 2 * i; j < MAX; j += i) cntRoad[i] -= cntRoad[j];
    long long res = 0;
    for(int i = 1; i < MAX; i++) res += i * cntRoad[i];
    cout << res;
}
int32_t main()
{
    FastIO
    readfile();
    prepare();
    return 0;
}
