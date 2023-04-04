#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

ll n;
bool isPrime[1000005];
vector<ll> prime;

int main()
{
    FastIO
    cin >> n;

    isPrime[1] = isPrime[0] = true;
    for(ll i = 2; i * i <= 1000000; i++) if(!isPrime[i]) {
        for(ll j = i * i; j <= 1000000; j += i) isPrime[j] = true;
    }
    for(ll i = 2; i <= 1000000; i++) if(!isPrime[i]) prime.push_back(i);

    ll res = 0;
    for(ll u : prime){
        if(u * u <= n) res++;
        else break;
    }
    cout << res;
    return 0;
}
