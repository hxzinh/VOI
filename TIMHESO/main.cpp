#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

ll n, m, p;

ll gcd(ll u, ll v, ll &x, ll &y){
    if(v == 0){
        x = 1;
        y = 0;
        return u;
    }
    ll x1, y1;
    ll tmp = gcd(v, u % v, x1, y1);
    x = y1;
    y = x1 - y1 * (u / v);
    return tmp;
}
int main()
{
    FastIO
    cin >> n >> m >> p;

    ll x, y;
    ll tmp = gcd(n, m, x, y);
    if((x + y) % 2 == 0) cout << "YES";
    else cout << "NO";
    return 0;
}
