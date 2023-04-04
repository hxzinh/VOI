#include <bits/stdc++.h>
#define int long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

int T;
int x, n, m;

int mult(int u, int v){
    if(v <= 1) return (v == 0) ? 0 : u;
    int s = mult(u, v / 2);
    if(v % 2 == 0) return (s + s) % m;
    else return (s + s + u) % m;
}
int solve(int u, int k){
    if(k == 1) return 1;
    if(k % 2 != 0) return 1 + mult(u, solve(u, k - 1)) % m;
    else {
        int tmp = solve(u, k / 2);
        return mult((mult(u - 1, x), x) % m + 2, x) % m;
    }
}
void xuli(){
    int u = 1, v = x;
    while(v != 0){
        u *= 10;
        v /= 10;
    }

    x %= m;
    cout << mult(solve(u, n), x) % m << '\n';
}
int32_t main()
{
    FastIO
    freopen("REMAINDER.INP", "r", stdin);
    freopen("REMAINDER.OUT", "w", stdout);
    cin >> T;
    while(T--){
        cin >> x >> n >> m;
        xuli();
    }
    return 0;
}
