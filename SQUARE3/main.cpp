#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

ll n, m;

int main()
{
    FastIO
    cin >> n >> m;

    ll u = sqrt(n), v = sqrt(m);
    if(u * u < n) u++;
    ll res = max(v - u + 1, 0LL);
    cout << res;
    return 0;
}
