#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int MOD = 1e9 + 7;
ll n, k;

ll pw(ll x, ll k) {
    if(k == 0) return 1LL;
    if(k == 1) return x;
    ll tmp = pw(x, k / 2);
    if(k % 2 == 0) return (tmp % MOD) * (tmp % MOD) % MOD;
    else return (tmp * x) % MOD * (tmp % MOD) % MOD;
}
int main()
{
    FastIO
    cin >> n >> k;
    n % MOD;
    cout << pw(n, k);
    return 0;
}
