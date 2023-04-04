#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

ll x, y, z, n;

int main()
{
    FastIO
    cin >> x >> y >> z >> n;

    ll bcnn = (x * y) / __gcd(x, y);
    bcnn = (bcnn * z) / __gcd(bcnn, z);

    ll tmp = 1, res = bcnn;
    for(int i = 1; i < n; i++) tmp *= 10;

    if(res >= tmp * 10){
        cout << -1;
        return 0;
    }

    while(res < tmp) {
        res += bcnn;
        if(res >= tmp * 10){
            cout << -1;
            return 0;
        }
    }
    cout << res;
    return 0;
}
