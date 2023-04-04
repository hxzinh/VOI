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

const int NM = 2e5 + 10;
const int BLOCK = 40;
int n, q;
int a[NM];

struct FenwickTree {
    int n;
    vector<ll> sum;

    FenwickTree(int _n = 0){
        n = _n;
        sum.assign(n + 7, 0);
    }

    void update(int u, int x){
        for(; u <= n; u += u & -u) sum[u] += x;
    }

    ll getSum(int u){
        ll res = 0;
        for(; u > 0; u -= u & -u) res += sum[u];
        return res;
    }

    ll getSum(int u, int v){
        return getSum(v) - getSum(u - 1);
    }
} tree[45][45];

ll solve(int p, int k){
    ll res = 0;

    if(k > BLOCK) {
        for(int i = p; i <= n; i += k) res += a[i];
    } else res = tree[k][p % k].getSum(p / k + 1, n / k + 1);

    return res;
}
void xuli(){
    for(int i = 1; i <= BLOCK; i++)
        for(int j = 0; j <= BLOCK; j++) tree[i][j] = FenwickTree(n / i + 10);

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= BLOCK; j++) tree[j][i % j].update(i / j + 1, a[i]);
    }

    while(q--){
        int type, u, v;
        cin >> type >> u >> v;
        if(type == 2) cout << solve(u, v) << '\n';
        else {
            for(int i = 1; i <= BLOCK; i++) tree[i][u % i].update(u / i + 1, v - a[u]);
            a[u] = v;
        }
    }
}
void sub1(){
    while(q--){
        int type, u, v;
        cin >> type >> u >> v;
        if(type == 1) a[u] = v;
        else {
            ll res = 0;
            for(int i = u; i <= n; i += v) res += a[i];
            cout << res << '\n';
        }
    }
}
int32_t main()
{
    FastIO
    freopen("CSCQUERIES.INP", "r", stdin);
    freopen("CSCQUERIES.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    cin >> q;

    if(n <= 5000) sub1();
    else xuli();
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
