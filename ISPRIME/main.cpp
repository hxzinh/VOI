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
    if(n < 2){
        cout << "NO";
        return 0;
    }
    if(n == 2){
        cout << "YES";
        return 0;
    }
    for(ll i = 2; i * i <= n; i++){
        if(n % i == 0){
            ok = false;
            break;
        }
    }
    if(ok) cout << "YES";
    else cout << "NO";
    return 0;
}
