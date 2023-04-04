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
const int MAX = 2;
const int MOD = 1e9 + 7;
int n, m, T;
string sL, sR;
int pw[11], L[NM], R[NM];
ll f[NM][11], g[NM][11][2][2];

void add(ll &a, ll b){
    a = (a + b) % MOD;
    if(a < 0) a += MOD;
}
ll solve(int x, int p, int sum, bool okL, bool okR) {
    ll res = g[x][p][okL][okR];
    if(x >= m) return sum;
}
void sub1(){
    memset(g, -1, sizeof g);
    m = sR.size();
    sL = string(sR.size() - sL.size(), '0') + sL;

    m = sR.size();
    for(int i = 0; i <= m; i++){
        L[i] = sL[i] - '0';
        R[i] = sR[i] - '0';
    }
    cout << dp(0, 10, 0) << '\n';
}
ll dp(int x, int p, ll sum){
    ll &res = f[x][p];
    if(res > -1) return res;
    if(x >= MAX) return res = sum;

    res = 0;
    for(int i = 0; i < 10; i++){
        if(i != p) add(res, dp(x + 1, (p == 10 && i == 0) ? 10 : i, (sum * 10 + i) % MOD));
        else add(res, dp(x + 1, (p == 10 && i == 0) ? 10 : i, (sum * 10) % MOD));
    }
    return res;
}
void xuli(){
    memset(f, -1, sizeof f);
    m = sR.size();
    sL = string(MAX - sL.size(), '0') + sL;
    sR = string(MAX - sR.size(), '0') + sR;

    for(int i = 0; i <= m; i++){
        L[i] = sL[i] - '0';
        R[i] = sR[i] - '0';
    }
    cout << dp(0, 10, 0) << '\n';
}
void trau() {
    int res = 0;
    for(int i = 1; i < 1000; i++){
        int sum = 0, tmp = i, p = 10, cur = 1;
        int coso = i;
        while(coso > 10){
            cur *= 10;
            coso /= 10;
        }
        while(cur != 0){
            int u = tmp / cur;
            if(p != u) {
                sum = sum * 10 + u;
                p = u;
            } else sum = sum * 10;
            tmp = tmp % cur;
            cur /= 10;
        }
        cout << i << " " << sum << '\n';
        res += sum;
    }
    cout << res << '\n';
}
int32_t main()
{
    FastIO
    freopen("ENCODE.INP", "r", stdin);
    freopen("ENCODE.OUT", "w", stdout);
    cin >> T;
    while(T--){
        cin >> sL >> sR;

        trau();
        xuli();
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
