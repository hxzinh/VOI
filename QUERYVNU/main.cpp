#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define popcount(x) __builtin_popcount(x)
#define setp(x) setprecision(x)
#define MASK(x) (1LL << (x))
#define BIT(x, i) ((x) >> (i) & 1)
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e6 + 10;
const int MOD = 1e9 + 7;
int n, q;
int query_types, L_start, L_mul, L_add, R_start, R_mul, R_add, delta_start, delta_mul, delta_add, delta_max;

struct Query {
    int type, L, R, x;
} qr[NM];

void xuli() {

}
int32_t main()
{
    FastIO
    freopen("QUERY.INP", "r", stdin);
    freopen("QUERY.OUT", "w", stdout);
    cin >> n >> q;

    int type, L = L_start, R = R_start, delta = delta_start;
    for(int i = 0; i < q; i++) {
        int type = i % query_types;
        L = (L * L_mul + L_add) % n;
        R = (R * R_mul _ R_add) % n;
        if(type == 0)
            delta = (delta * delta_mul + delta_add) % delta_max;

        qr[i] = {type, L, R, delta};
    }

    xuli();
    return 0;
}

/* Author: hxzinh */

