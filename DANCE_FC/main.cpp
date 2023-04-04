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
int n, k, cntMale = 0, cntFemale = 0;
int a[NM], b[NM];

void xuli(){
    sort(a + 1, a + cntMale + 1);
    sort(b + 1, b + cntFemale + 1);

    int res = 0;

    for(int i = 1; i <= cntMale; i++){
        int head = n, last = -1;

        int l = 1, r = cntFemale;
        while(l <= r){
            int m = (l + r) >> 1;
            if(b[m] >= a[i] - k){
                r = m - 1;
                head = m;
            } else l = m + 1;
        }

        int L = 1, R = cntFemale;
        while(L <= R){
            int m = (L + R) >> 1;
            if(b[m] <= a[i]){
                L = m + 1;
                last = m;
            } else R = m - 1;
        }

        if(last >= head) res += (last - head + 1);
    }

    cout << res;
}
int32_t main()
{
    FastIO
    freopen("DANCE.INP", "r", stdin);
    freopen("DANCE.OUT", "w", stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        int u; cin >> u;
        if(u > 0) a[++cntMale] = u;
        else b[++cntFemale] = -u;
    }

    xuli();
    return 0;
}

/* Author: hxzinh */

/*



-=Buddha=- code ko bug | code ko bug | code ko bug

                                  _

                                ooOoo
                              o8888888o
                              88" . "88
                              (| - - |)
                              O\  =  /O
                           ___/`---'\___
                         .'  \\|     |//  `.
                        /  \\|||  :  |||//  \
                       /  ||||| -:- |||||  \
                       |   | \\\  -  /'| |   |
                       | \_|  `\`---'//  |_/ |
                       \  .-\__ `-. -'__/-.  /
                     ___. .'  /--.--\  . .'___
                  ."" '<  `.___\_<|>_/___.' _> \"".
                 | | :  - \. ;`. _/; .'/ /  .' ; |
                 \  \ -.   \_\_. _.'_/_/  -' _.' /
       ===========`-.`___`-.__\ \___  /__.-'.'.-'================
                          `=--=-'

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
