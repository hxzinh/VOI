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

ll n, m, t;
ll numLength = 0;

void xuli(){
    ll numCnt = 1, cntPlus = (numCnt - n + 1) / m;;
    for(int i = 1; i <= numLength; i++) numCnt *= 10;
    ///cout << numLength << " " << cntPlus;

    while(true){
        cntPlus = (numCnt - n + m - 1) / m;
        if(t <= cntPlus * numLength) break;
        t -= cntPlus * numLength;
        numLength++;
        n += cntPlus * m;
        numCnt = numCnt  * 10;
    }

    n -= m;
    cntPlus = (t + numLength - 1) / numLength;
    n += cntPlus * m;
    if(n == 0){cout << n; return;}

    vector<int> ans;
    while(n != 0) {
        ans.push_back(n % 10);
        n /= 10;
    }
    reverse(ans.begin(), ans.end());
    for(int i = 0; i < ((t - 1) % numLength + 1); i++) cout << ans[i];
}
void readfile(){
    freopen("DIGITS.INP", "r", stdin);
    freopen("DIGITS.OUT", "w", stdout);
    cin >> n >> m >> t;

    int tam = n;
    if(n == 0) numLength++;
    while(tam > 0){
        numLength++;
        tam /= 10;
    }
}
int32_t main()
{
    FastIO
    readfile();
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

