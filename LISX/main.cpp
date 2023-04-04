#include <bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define mp(x, y) make_pair(x, y)
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

const int NM = 15;
int T, n, m;
string sL, sR;
int L[NM], R[NM];
pii f[NM][11][2][2];

pii dp(int x, int p, bool okL, bool okR){
    if(x >= n) return mp(0, 1);
    pii &res = f[x][p][okL][okR];
    if(res.fi > -1) return res;

    res = mp(0, 0);
    for(int i = 0; i < 10; i++){
        if((okL || i >= L[x])
        && (okR || i <= R[x])){
            if(p == 10 || i > p){
                pii ans = dp(x + 1, i, okL || i > L[x], okR || i < R[x]);
                if(maximize(res.fi, ans.fi + 1)) res.se = ans.se;
                else if(res.fi == ans.fi + 1) res.se += ans.se;
            }
            pii tmp = dp(x + 1, p, okL || i > L[x], okR || i < R[x]);
            if(maximize(res.fi, tmp.fi)) res.se = tmp.se;
            else if(res.fi == tmp.fi) res.se += tmp.se;
        }
    }
    return res;
}
void sub12(){
    n = sR.size();

    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= 10; j++)
            for(int okL = 0; okL < 2; okL++)
                for(int okR = 0; okR < 2; okR++) f[i][j][okL][okR] = mp(-1, 0);

    sL = string(sR.size() - sL.size(), '0') + sL;

    for(int i = 0; i < n; i++){
        L[i] = sL[i] - '0';
        R[i] = sR[i] - '0';
    }

    pii res = dp(0, 10, 0, 0);
    cout << res.fi << " " << res.se << '\n';
}
int32_t main()
{
    FastIO
    freopen("LISX.INP", "r", stdin);
    freopen("LISX.OUT", "w", stdout);
    cin >> T;
    while(T--){
        cin >> sL >> sR;
        sub12();
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
