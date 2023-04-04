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

const int NM = 2e3 + 10;
int n, k;
int result = 0;
int a[NM], M[NM][20], f[205][205][205];

void sub1(){
    int res = 0;
    for(int i = 1; i <= n; i++) res += (!a[i]);

    int ans = 0, tmp = -1;
    for(int i = 1; i <= n; i++){
        if(a[i] == 1) ans++;
        else {
            maximize(tmp, ans);
            ans = 0;
        }
    }
    maximize(tmp, ans);
    cout << res + tmp;
}
void sub3(){
    int res = 0;
    memset(f, -1, sizeof f);
    f[0][0][0] = 0;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= k; j++){
            for(int t = 0; t <= k; t++) if(f[i][j][t] > -1) {
                maximize(res, f[i][j][t]);
                if(a[i + 1] <= t) maximize(f[i + 1][j][a[i + 1]], f[i][j][t] + 1);
                else {
                    maximize(f[i + 1][j][t], f[i][j][t]);
                    if(j + (a[i + 1] - t) <= k) maximize(f[i + 1][j + (a[i + 1] - t)][a[i + 1]], f[i][j][t] + 1);
                }
            }
        }
    }

    cout << res;
}
int32_t main()
{
    FastIO
    freopen("GAME.INP", "r", stdin);
    freopen("GAME.OUT", "w", stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];

    if(k == 1) sub1();
    else sub3();
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
