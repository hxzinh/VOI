#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

int32_t main() {
    long long n;
    cin >> n;

    cout << 0 << endl;
    for (long long i = 2 ; i <= n ; i++) {
      cout << (i * i) * (i * i - 1) / 2 - (4 * (i - 2) * (i - 1)) << endl;
    }

    return 0;
}
