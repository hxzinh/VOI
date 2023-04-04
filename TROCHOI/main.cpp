#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define mp make_pair
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

const int NM = 1e5 + 10;
int n, m;
ll s[NM], b[NM], M[NM][23];

struct Data {
    ll u, v, val;
} a[NM];

void sub12() {
    for(int i = 1; i <= m; i++) {
        int u = a[i].u, v = a[i].v, w = a[i].val;
        s[u] += w; s[v + 1] -= w;
    }

    ll res = INF;
    for(int i = 1; i <= m; i++) {
        ll u = a[i].u, v = a[i].v, w = a[i].val;
        s[u] -= w; s[v + 1] += w;

        ll ans = -INF;
        for(int j = 1; j <= n; j++) {
            b[j] = b[j - 1] + s[j];
            maximize(ans, b[j]);
        }

        s[u] += w; s[v + 1] -= w;
        minimize(res, ans);
    }

    cout << res;
}
ll getMax(int u, int v) {
    if(v < u) return 0;
    ll k = log2(v - u + 1);
    return max(M[u][k], M[v - MASK(k) + 1][k]);
}
void xuli() {
    for(int i = 1; i <= m; i++) {
        ll u = a[i].u, v = a[i].v, w = a[i].val;
        s[u] += w; s[v + 1] -= w;
    }
    for(int i = 1; i <= n; i++) s[i] += s[i - 1];

    for(int i = 1; i <= n; i++) M[i][0] = s[i];
    for(int k = 1; MASK(k) <= n; k++) {
        for(int i = 1; i + MASK(k) - 1 <= n; i++) {
            M[i][k] = max(M[i][k - 1], M[i + MASK(k - 1)][k - 1]);
        }
    }

    ll res = INF;
    for(int i = 1; i <= m; i++) {
        ll u = a[i].u, v = a[i].v, w = a[i].val;
        ll sumL = getMax(1, u - 1);
        ll sumR = getMax(v + 1, n);
        ll ans = max(sumL, sumR);
        maximize(ans, getMax(u, v) - w);

        minimize(res, ans);
    }

    cout << res;
}
int32_t main()
{
    FastIO
    freopen("TROCHOI.INP", "r", stdin);
    freopen("TROCHOI.OUT", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        a[i] = {u, v, w};
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
