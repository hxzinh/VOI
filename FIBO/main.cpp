#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int MOD = 1e9 + 7;
int n;

int main()
{
    FastIO
    cin >> n;

    if(n == 1){cout << 0; return 0;}
    if(n == 2){cout << 1; return 0;}
    ll cur = 0, a = 0, b = 1;
    for(int i = 3; i <= n; i++){
        cur = (a + b) % MOD;
        a = b;
        b = cur;
    }
    cout << cur;
    return 0;
}
