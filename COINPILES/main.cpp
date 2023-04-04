#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

ll T, a, b;

int main()
{
    FastIO
    cin >> T;
    while(T--){
        cin >> a >> b;

        if(a < b) swap(a, b);

        if(b == 0 && a != 0) cout << "NO" << '\n';
        else if(a % 2 == 0 && b == a / 2) cout << "YES" << '\n';
        else if((a + b) % 3 == 0 && 2 * b >= a) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}
