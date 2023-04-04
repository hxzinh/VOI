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

int32_t main()
{
    FastIO
    ll n, k;
    cin >> n >> k;

    queue<int> res;
    while(n > 1){
        if(n % k == 0){
            n /= k;
            res.push(1);
        } else {
            n++;
            res.push(2);
        }
    }
    cout << res.size() << '\n';
    while(res.size()){
        cout << res.front() << " ";
        res.pop();
    }
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
