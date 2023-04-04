#include <bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define popcount(x) __builtin_popcount(x)
#define set(x) setprecision(x)
#define MASK(x) (1LL << (x))
#define BIT(x, i) ((x) >> (i) & 1)
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int MOD = 1e9 + 7;
int n;

void add(int &x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
}
void sub(int &x, int y) {
    x -= y;
    if (x < 0) x += MOD;
}

bool isPrime(int n) {
    if (n < 2 || n == 4) return false;
    if (n == 2 || n == 3 || n == 5) return true;
    if (n % 2 == 0 || n % 3 == 0 || n % 5 == 0) return false;

    for (int x = 5; 1LL * x * x <= n; x += 6)
        if (n % x == 0 || n % (x + 2) == 0)
            return false;

    return true;
}

int pw(int x, int n){
    int res = 1;
    for (; n > 0; n >>= 1){
        if (n & 1){
            if (res <= INF / x) res *= x;
            else res = +INF;
        }

        if (x <= INF / x) x *= x;
        else x = INF;
    }
    return res;
}

int32_t main() {
    cin >> n;
    for (int q = 2; q <= 60; ++q) {
        int p = pow(n, double(1.0) / q);
        while(pw(p, q) < n) p++;
        while(pw(p, q) > n) p--;
        if (pw(p, q) == n) {
            if (isPrime(p)) {
                cout << p << " " << q;
                return 0;
            }
        }
    }

    cout << 0;
    return 0;
}
