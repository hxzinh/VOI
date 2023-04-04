#include <bits/stdc++.h>
#define int long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

int dp(int n){
    int res = 0;
    for (int x = 2; x <= n; x *= 2)
        res += n / x;

    return res;
}
int32_t main()
{
    FastIO
    int L, R;
    cin >> L >> R;
    cout << dp(R) - dp(L - 1);
    return 0;
}
