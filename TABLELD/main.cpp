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

const int NM = 5e3 + 10;
int n, m;
ll k;
int a[NM][NM];
ll s[NM][NM];

bool check(int x){
    bool ok = false;
    for(int i = x; i <= n; i++){
        for(int j = x; j <= m; j++){
            ll sum = s[i][j] - s[i - x][j] - s[i][j - x] + s[i - x][j - x];
            if(sum <= k){
                //cout << x << " " << i << " " << j << " " << sum << '\n';
                return true;
            }
        }
    }
    return false;
}
void xuli(){
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];

    int l = 1, r = min(n, m), res = 0;
    while(l <= r){
        int m = (l + r) >> 1;
        if(check(m)){
            res = m;
            l = m + 1;
        } else r = m - 1;
    }

    cout << res;
}
int32_t main()
{
    FastIO
    freopen("TABLE.INP", "r", stdin);
    freopen("TABLE.OUT", "w", stdout);
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) cin >> a[i][j];

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
