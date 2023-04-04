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

int main()
{
    FastIO
    cin >> n;

    bool ok = true;
    while(n != 0){
        ll u = n % 10;
        n /= 10;
        if(u != 6 && u != 0 && u != 8){
            ok = false;
            break;
        }
    }
    cout << ok;
    return 0;
}
