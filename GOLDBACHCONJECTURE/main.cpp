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
int n, T;
bool isPrime[NM];
vector<int> prime;

int32_t main()
{
    FastIO
    freopen("INP", "r", stdin);
    freopen("OUT", "w", stdout);
    cin >> T;

    isPrime[1] = isPrime[0] = true;
    for(ll i = 2; i * i <= 1000000; i++) if(!isPrime[i]) {
        for(ll j = i * i; j <= 1000000; j += i) isPrime[j] = true;
    }
    for(int i = 2; i <= 1000000; i++) if(!isPrime[i]) prime.push_back(i);

    while(T--){
        cin >> n;
        for(int u : prime){
            if(u > n - u) break;
            if(!isPrime[n - u]){
                cout << u << " " << n - u << '\n';
            }
        }
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
