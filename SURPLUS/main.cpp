#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

ll MOD;
ll a, b, c, m;

ll pw(ll x, ll k){
    if(k == 1) return x;
    if(k == 0) return 1;
    ll tmp = pw(x, k / 2);
    if(k % 2 == 0) return tmp * tmp % MOD;
    else return (tmp * x) % MOD * tmp % MOD;
}
int main()
{
    FastIO
    cin >> a >> b >> c >> MOD;

    ll res = pw(a, b) * pw(c, MOD - 2) % MOD;
    cout << res;
    return 0;
}
