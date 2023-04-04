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
int n;
ll a[1005];

int main()
{
    FastIO
    cin >> n;
    ll res = 1;
    for(int i = 1; i <= n; i++){
        ll u; cin >> u;
        res = res * u % MOD;
    }
    cout << res;
    return 0;
}
