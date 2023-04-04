#include <bits/stdc++.h>
#define ll long long
#define int long long
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

const int NM = 4e5 + 10;
int n, q;
int a[NM], high[NM];
vector<int> edges[NM];
bool cx[NM];

void prepare(int u, int p) {
    for(int v : edges[u]) if(v != p) {
        high[v] = high[u] + 1;
        prepare(v, u);
    }
}
pii add(pii A, pii B) {
    return {A.fi + B.fi, A.se + B.se};
}
pii solve(int u, int p, bool Odd, bool Even) {
    pii res = {0, 0};

    bool nxtOdd = Odd | (cx[u] && (high[u] & 1));
    bool nxtEven = Even | (cx[u] && !(high[u] & 1));

    for(int v : edges[u]) if(v != p) {
        res = add(res, solve(v, u, nxtOdd, nxtEven));
    }

    int tmp = a[u];

    if(cx[u])
        if(high[u] & 1) a[u] += res.fi;
        else a[u] += res.se;


    if(Odd && (high[u] & 1)) {
        a[u] = 0;
        res.fi += tmp;
    }
    if(Even && !(high[u] & 1)) {
        a[u] = 0;
        res.se += tmp;
    }
    return res;
}
void xuli() {
    prepare(1, -1);
    solve(1, -1, 0, 0);

    for(int i = 1; i <= n; i++) cout << a[i] << " ";
}
int32_t main()
{
    FastIO
    freopen("A.INP", "r", stdin);
    freopen("A.OUT", "w", stdout);
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    for(int i = 1; i <= q; i++) {
        int u; cin >> u;
        cx[u] = true;
    }

    xuli();
    return 0;
}
