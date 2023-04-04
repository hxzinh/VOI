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
ll result = 0;
ll a[NM], f[NM][15], dp[2][MASK(10)];
vector<int> edges[NM], edgesBack[NM];

void backtrack(int x, int sum, int mask = 0) {
    if(x > n) {
        maximize(result, sum);
        return;
    }

    bool ok = true;
    for(int u : edgesBack[x]) {
        if(!BIT(mask, u - 1)) {
            ok = false;
            break;
        }
    }

    if(ok) backtrack(x + 1, sum + a[x], mask | MASK(x - 1));
    backtrack(x + 1, sum, mask);
}
void sub1() {
    backtrack(1, 0, 0);
    cout << result;
}
void sub2() {
    memset(f, -INF, sizeof f);
    f[0][0] = 0;

    for(int i = 0; i < n; i++) {
        if(edgesBack[i + 1].size()) maximize(f[i + 1][1], f[i][1] + a[i + 1]);
        else {
            maximize(f[i + 1][1], f[i][0] + a[i + 1]);
            maximize(f[i + 1][1], f[i][1] + a[i + 1]);
        }

        maximize(f[i + 1][0], f[i][0]);
        maximize(f[i + 1][0], f[i][1]);
    }

    ll res = max(f[n][0], f[n][1]);
    cout << res;
}
int32_t main()
{
    FastIO
    freopen("KHAOSAT.INP", "r", stdin);
    freopen("KHAOSAT.OUT", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >>  v;
        edges[u].push_back(v);
        edgesBack[v].push_back(u);
    }

    if(n <= 15) sub1();
    else  sub2();
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
