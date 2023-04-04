#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

int n;

int main()
{
    FastIO
    freopen("FUNCTION.INP", "r", stdin);
    freopen("FUNCTION.OUT", "w", stdout);
    cin >> n;
    if(n % 2 == 0) cout << n / 2;
    else{
        ll k = n / 2 + 1;
        cout << -k;
    }
    return 0;
}
