#include<bits/stdc++.h>
using namespace std;

#define inf 0x3f3f3f3f
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define fi first
#define se second
typedef long long ll;
typedef pair<int, int> ii;

ll m;

ll mult(ll a, ll b) {
    if(b <= 1) {
        return (!b) ? 0 : a;
    }

    ll s = mult(a, b >> 1);
    return (b % 2) ? (s + s + a) % m : (s + s) % m;
}

ll solve(ll d, ll r) {
    if(r == 1) {
        return 1;
    }

    if(r % 2) {
        return 1 + mult(d, solve(d, r - 1)) % m;
    } else {
        ll x = solve(d, r / 2);
        return mult((mult(d - 1, x) % m + 2), x) % m;
    }
}

void process() {
    int t;
    cin >> t;

    for (int q = 0; q < t; ++q) {
        ll x, n;
        cin >> x >> n >> m;

        ll a(1), y(x);
        while(y) {
            y /= 10;
            a *= 10;
        }
        x %= m;

        cout << mult(solve(a, n), x) % m << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    freopen("REMAINDER.inp", "r", stdin);
    freopen("REMAINDER.out", "w", stdout);

    process();
    return 0;
}
