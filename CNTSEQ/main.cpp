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
const int MOD = 998244353;
int Sub, result = 0;
int n, a[NM], b[NM];
ll f[305][50005];

void add(ll &a, ll b){
    if(a + b >= MOD) a += b - MOD;
    else a += b;
}
void backtrack(int x, int Max, int Lcm){
    if(x > n){
        result += (Max == Lcm);
        return;
    }

    for(int i = a[x]; i <= b[x]; i++){
        backtrack(x + 1, max(Max, i), (Lcm == 1 ? i : (i * Lcm) / __gcd(i, Lcm)));
    }
}
void sub1(){
    result = 0;
    backtrack(1, 1, 1);
    cout << result << '\n';
}
void sub23(){
    memset(f, 0, sizeof f);
    for(int i = a[1]; i <= b[1]; i++) f[1][i] = 1;

    for(int i = 1; i < n; i++){
        for(int j = a[i]; j <= b[i]; j++) if(f[i][j]){
            for(int u = j; u <= b[i + 1]; u += j) add(f[i + 1][u], f[i][j]);
        }
    }

    ll res = 0;
    for(int i = a[n]; i <= b[n]; i++) add(res, f[n][i]);
    cout << res << '\n';
}
int32_t main()
{
    FastIO
    freopen("CNTSEQ.INP", "r", stdin);
    freopen("CNTSEQ.OUT", "w", stdout);
    cin >> Sub;
    while(Sub--){
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> a[i] >> b[i];

        sub23();
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
