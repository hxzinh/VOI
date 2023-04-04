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

bool check(ll x){
    while(x != 0){
        if(x % 10 != 4 && x % 10 != 7) return false;
        x /= 10;
    }
    return true;
}
int main()
{
    FastIO
    cin >> n;

    bool ok = false;
    for(ll i = 1; i * i <= n; i++) if(n % i == 0) {
        ll u = n / i;
        ok |= check(i);
        if(u != i) ok |= check(u);
    }

    if(ok) cout << "YES";
    else cout << "NO";
    return 0;
}
