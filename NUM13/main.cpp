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
int a[] = {0, 2, 4, 5, 6, 7, 8, 9};
int n;
ll f[NM][15];

void add(ll &a, ll b){
    if(a + b >= MOD) a += b - MOD;
    else a += b;
}
void xuli(){
    memset(f, 0, sizeof f);
    f[0][0] = 1;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < 13; j++) if(f[i][j]) {
            for(int k = 0; k < 8; k++){
                int u = a[k];
                if(u == 0 && i == 0) continue;
                add(f[i + 1][(j * 10 + u) % 13], f[i][j]);
            }
        }
    }

    cout << f[n][0];
}
int32_t main()
{
    FastIO
    freopen("NUM13.INP", "r", stdin);
    freopen("NUM13.OUT", "w", stdout);
    cin >> n;

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
