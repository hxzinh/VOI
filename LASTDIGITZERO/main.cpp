#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

int d[] = {1, 1, 2, 6, 4, 2, 2, 4, 2, 8};
ll n;

ll D(ll n) {
    if(n < 10) return d[n];
    return (n % 100 / 10 % 2 ? 4 : 6) * D(n / 5) * D(n % 10) % 10;
}
int main()
{
    FastIO
    cin >> n;
    cout << D(n);
    return 0;
}
