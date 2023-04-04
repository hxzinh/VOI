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

ll sL, sR;
int n, result = 0;
bool isPrime[1005];

void backtrack(int x, ll cur, int sum){
    bool ok = (cur >= sL && cur <= sR && !isPrime[sum]);
    if(ok)
    for(int i = 2; i * i <= cur; i++) if(cur % i == 0){
        ok = false;
        break;
    }
    if(ok) result++;

    if(x > n) return;

    if(x < n) backtrack(x + 1, cur * 10 + 2, sum + 2);
    if(x < n) backtrack(x + 1, cur * 10 + 5, sum + 5);
    backtrack(x + 1, cur * 10 + 3, sum + 3);
    backtrack(x + 1, cur * 10 + 7, sum + 7);
}
void xuli(){
    ll tmp = sR;
    while(tmp != 0){
        n++;
        tmp /= 10;
    }
    backtrack(1, 0, 0);
    cout << result;
}
int32_t main()
{
    FastIO
    freopen("ORIPRIME.INP", "r", stdin);
    freopen("ORIPRIME.OUT", "w", stdout);
    cin >> sL >> sR;

    isPrime[1] = isPrime[0] = true;
    for(ll i = 2; i * i <= 1000; i++) if(!isPrime[i]) {
        for(ll j = i * i; j <= 1000; j += i) isPrime[j] = true;
    }

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
