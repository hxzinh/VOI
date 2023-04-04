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

const int NM = 1e6 + 10;
const ll MOD = 1e9 + 19972207;
int n, m;
string sL, sR;
int L[NM], R[NM];
ll f[NM][2][2];

void add(ll &a, ll b) {
    if(a + b >= MOD) a += b - MOD;
    else a += b;
}
void solve() {
    n = max(sR.size(), sL.size());
    if(sL.size() < sR.size()) sL = string(sR.size() - sL.size(), '0') + sL;
    if(sR.size() < sL.size()) sR = string(sL.size() - sR.size(), '0') + sR;
    sL = '#' + sL; sR = '#' + sR;

    for(int i = 1; i <= n; i++) {
        L[i] = (sL[i] == '?' ? -1 : sL[i] - '0');
        R[i] = (sR[i] == '?' ? -1 : sR[i] - '0');
    }

    f[0][0][0] = 1;
    for(int i = 0; i < n; i++){
        for(int okL = 0; okL < 2; okL++) {
            for(int okR = 0; okR < 2; okR++) if(f[i][okL][okR]) {
                if(L[i + 1] == -1 && R[i + 1] == -1) {
                    for(int u = 0; u < 10; u++) {
                        for(int v = 0; v < 10; v++)
                            add(f[i + 1][okL | (u > v)][okR | (v > u)], f[i][okL][okR]);
                    }
                } else if(L[i + 1] == -1) {
                    for(int u = 0; u < 10; u++) add(f[i + 1][okL | (u > R[i + 1])][okR | (u < R[i + 1])], f[i][okL][okR]);
                } else if(R[i + 1] == -1) {
                    for(int u = 0; u < 10; u++) add(f[i + 1][okL | (u < L[i + 1])][okR | (u > L[i + 1])], f[i][okL][okR]);
                } else add(f[i + 1][okL | (L[i + 1] > R[i + 1])][okR | (R[i + 1] > L[i + 1])], f[i][okL][okR]);
            }
        }
    }

    cout << f[n][1][1];
}
int32_t main()
{
    FastIO
    freopen("BRENTFORD40MU.INP", "r", stdin);
    freopen("BRENTFORD40MU.OUT", "w", stdout);
    cin >> sL >> sR;

    solve();
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
