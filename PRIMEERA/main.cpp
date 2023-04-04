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

int T;
ll n;
bool ok[10000005];
vector<int> isPrime;


int32_t main()
{
    FastIO
    n = 1000000;
    ok[1] = ok[0] = true;
    for(ll i = 2; i * i <= n; i++) if(!ok[i]) {
        for(int j = i * i; j <= n; j += i) ok[j] = true;
    }

    cin >> T;
    while(T--){
        int u; cin >> u;
        if(!ok[u]) cout << "YES" << '\n';
        else cout << "NO" << '\n';
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
