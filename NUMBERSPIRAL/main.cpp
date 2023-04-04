#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

int T;
ll x, y;

int main()
{
    FastIO
    cin >> T;
    while(T--){
        cin >> x >> y;
        ll u = max(x, y) - 1;

        ll res = 0;
        if(u % 2 != 0) res = u * u + x + (u + 1) - y;
        else res = u * u + y + (u + 1) - x;

        cout << res << '\n';
    }
    return 0;
}
