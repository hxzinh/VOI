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

const int NM = 1e7 + 10;
ll a, b;
bool prime[NM];
vector<int> inLR;

int32_t main()
{
    FastIO
    cin >> a >> b;

    prime[1] = prime[0] = true;
    for(ll i = 2; i * i <= b; i++) if(!prime[i]) {
        for(ll j = i * i; j <= b; j += i) prime[j] = true;
    }
    for(int i = 2; i <= b; i++) if(!prime[i] && i >= a && i <= b) inLR.push_back(i);

    int res = 0;
    for(int u : inLR){
        int tmp = u;
        bool ok = true;
        while(tmp != 0){
            if(prime[tmp % 10]){
                ok = false;
                break;
            }
            tmp /= 10;
        }
        if(ok) {
            res++;
        }
    }
    cout << res;
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
