#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define popcount(x) __builtin_popcount(x)
#define setp(x) setprecision(x)
#define MASK(x) (1LL << (x))
#define BIT(x, i) ((x) >> (i) & 1)
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

/**
//PRAGMA
#pragma GCC target("popcnt")
**/

/**
//ordered_set
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<pii,
             null_type,
             less<pii>,
             rb_tree_tag,
             tree_order_statistics_node_update> ordered_set;
**/

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 3e5 + 10;
const int MOD = 1e9 + 7;
ll n, k, stt, T;
ll a[NM], frac[NM], finv[NM];
int ans[NM];
bool ok[NM];

void add(int &a, int b){
    if(a + b >= MOD) a += b - MOD;
    else a += b;
}
int pw(int x, int k) {
    if(k <= 1) return k ? x : 1;
    int u = pw(x, k >> 1);
    if(k & 1) return 1LL * u * u % MOD * x % MOD;
    else return 1LL * u * u % MOD;
}
int comb(int k, int n) {
	return k > n ? 0 : (1LL * frac[n] * finv[k] % MOD) * finv[n - k] % MOD;
}
void init() {
    n = 300000;
    frac[0] = 1;
    for(int i = 1; i <= n; i++) frac[i] = (1LL * frac[i - 1] * i) % MOD;
    finv[n] = pw(frac[n], MOD - 2) % MOD;
    for (int i = n; i >= 1; i--) finv[i - 1] = (1LL * finv[i] * i) % MOD;
}
void sub1() {
    vector<int> vec;
    int cntRes = 0;
    for(int i = 1; i <= n; i++) {
        vector<int> curAns;
        memset(ok, false, sizeof ok);
        ok[0] = true;
        curAns.push_back(i); ok[i] = true;
        for(int j = 1; j <= n - k + 1; j++) {
            int u = a[j] - curAns.back();
            if(u <= n && !ok[u]) curAns.push_back(u);
            else break;
        }

        if(curAns.size() == n) cntRes++;
        if(cntRes == stt) {
            for(int u : curAns) cout << u << " ";
            cout << '\n';
            return;
        }
    }

    cout << -1 << '\n';
}
int32_t main()
{
    FastIO
    freopen("COMPRESS.INP", "r", stdin);
    freopen("COMPRESS.OUT", "w", stdout);
    cin >> T;
    while(T--) {
        cin >> n >> k >> stt;
        for(int i = 1; i <= n - k + 1; i++) cin >> a[i];

        sub1();
    }
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
