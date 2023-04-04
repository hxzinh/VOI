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

const int NM = 1e4 + 10;
const int MOD = 1e9 + 7;
string sL, sR;
int n, m;
ll f[NM][11][20][2][2];
int L[NM], R[NM];

ll dp(int x, int p, int u, int okL, int okR){
    if(x >= m) return (u == 0);
    ll &res = f[x][p][u][okL][okR];

    if(res > -1) return res;
    res = 0;
    for(int i = 0; i < 10; i++){
        if((okL || i >= L[x]) && (okR || i <= R[x]) && (p == 10 || i != p))
            res += dp(x + 1, (p == 10 && i == 0) ? 10 : i, (u * 10 + i) % 17, (okL || i > L[x]), (okR || i < R[x]));
            res %= MOD;
    }
    return res;
}
void xuli(){
    memset(f, -1, sizeof f);
    sL = string(sR.size() - sL.size(), '0') + sL;
    for(int i = 0; i < sR.size(); i++){
        L[i] = sL[i] - '0';
        R[i] = sR[i] - '0';
    }
    cout << dp(0, 10, 0, 0, 0);
}
int32_t main()
{
    FastIO
    freopen("NUM17.INP", "r", stdin);
    freopen("NUM17.OUT", "w", stdout);
    cin >> sL >> sR;
    n = sL.size(); m = sR.size();

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
