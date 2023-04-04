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

const int NM = 1e5 + 10;
const int MOD = 1e9 + 7;
int n;
int a[NM], d[NM], s[NM];

struct FenwickTree {
    int n;
    vector<int> cnt;

    FenwickTree(int _n = 0){
        n = _n;
        cnt.assign(n + 7, 0);
    }

    void update(int u, int x){
        for(; u <= n; u += u & -u) cnt[u] += x;
    }

    int getSum(int u){
        int res = 0;
        for(; u > 0; u -= u & -u) res += cnt[u];
        return res;
    }
};

int frac[NM], finv[NM];

int pw(int x, int t){
    if(t == 0) return 1;
    if(t == 1) return x;
    int w = pw(x, t >> 1);
    if(t % 2 == 0) return (1LL * w * w) % MOD;
    else return (1LL * w * w % MOD) * 1LL * x % MOD;
}
void add(int &a, int b){
    if(a + b >= MOD) a += b - MOD;
    else a += b;
}
void sub1(){
    for(int x = 1; x <= n; x++){
        FenwickTree tree(n + 1);
        int res = 0;
        for(int i = n; i > 0; i--){
            res += tree.getSum(min(x, a[i]) - 1);
            tree.update(min(x, a[i]), 1);
        }
        cout << res << '\n';
    }
}
int comb(int k, int n) {
	return k > n ? 0 : (1LL * frac[n] * finv[k] % MOD) * finv[n - k] % MOD;
}
void full(){
    frac[0] = 1;
    for(int i = 1; i <= n; i++) frac[i] = (1LL * frac[i - 1] * i) % MOD;
    finv[n] = pw(frac[n], MOD - 2) % MOD;
    for (int i = n; i >= 1; i--) finv[i - 1] = (1LL * finv[i] * i) % MOD;

    int res = 0;
    FenwickTree tree(n);

    for(int i = 1; i <= n; i++) d[a[i]]++;
    for(int i = n; i > 0; i--){
        res += tree.getSum(a[i] - 1);
        tree.update(a[i], 1);
    }

    int cnt = d[n + 1];
    for(int x = n; x > 0; x--){
        int ans = res - comb(2, cnt);
        cnt += d[x];
        cout << ans << '\n';
    }
}
int32_t main()
{
    FastIO
    freopen("HAIRCUT.INP", "r", stdin);
    freopen("HAIRCUT.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) a[i]++;

    full();
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
