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

int main()
{
    FastIO
    cin >> n;

    ll res = n;
    for(ll i = 2; i * i <= n; i++) if(n % i == 0) {
        res = res - res / i;
        while(n % i == 0) n /= i;
    }
    if(n > 1) res -= res / n;
    cout << res;
    return 0;
}
