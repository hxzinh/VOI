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

ll n;

int32_t main()
{
    FastIO
    cin >> n;

    ll sum = 0, tmp = n;
    while(tmp != 0){
        sum += tmp % 10;
        tmp /= 10;
    }

    ll dem = 0, sumDiv = 0;
    tmp = n;
    for(ll i = 2; i * i <= n; i++){
        if(n % i == 0) dem++;
        while(n % i == 0){
            int cur = i;
            while(cur != 0){
                sumDiv += cur % 10;
                cur /= 10;
            }
            n /= i;
        }
    }
    if(n != 1){
        int cur = n;
        while(cur != 0){
            sumDiv += cur % 10;
            cur /= 10;
        }
    }

    if(dem > 0 && sum == sumDiv) cout << "YES";
    else cout << "NO";

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
