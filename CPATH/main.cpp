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

const int NM = 3e5 + 10;
int numNode, m, k, n1, n2;
ll par[NM], cnt1[NM], cnt2[NM];
vector<int> node1, node2;

struct Data {
    ll u, v, w;
} a[NM];


int root(int x) {
    if(par[x] < 0) return x;
    return par[x] = root(par[x]);
}
bool join(int u, int v) {
    if ((u = root(u)) == (v = root(v))) return false;

    if (par[u] > par[v]) swap(u, v);
    par[u] += par[v];
    par[v] = u;
    return true;
}

void xuli() {
    sort(a + 1, a + m + 1, [](const Data A, const Data B){
        return A.w < B.w;
    });

    memset(par, -1, sizeof par);
    ll res = 0, ans = 0;
    for(int i = 1; i <= m; i++) {
        if(a[i].w < k) join(a[i].u, a[i].v);
    }

    for(int u : node1) cnt1[root(u)]++;
    for(int u : node2) ans += cnt1[root(u)];

    for(int i = 1; i <= m; i++) {
        if(a[i].w == k) join(a[i].u, a[i].v);
    }

    for(int u : node1) cnt2[root(u)]++;
    for(int u : node2) res += cnt2[root(u)];

    cout << res - ans;
}
int32_t main()
{
    FastIO
    freopen("CPATH.INP", "r", stdin);
    freopen("CPATH.OUT", "w", stdout);
    cin >> numNode >> m >> k >> n1 >> n2;
    for(int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        a[i] = {u, v, w};
    }
    for(int i = 1; i <= n1; i++) {
        int u; cin >> u;
        node1.push_back(u);
    }
    for(int i = 1; i <= n2; i++) {
        int u; cin >> u;
        node2.push_back(u);
    }

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
