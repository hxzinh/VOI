#include <bits/stdc++.h>
#define ll long long
#define int long long
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

/**
//PRAGMA
#pragma GCC target("popcnt")
**/

/**
//ordered_set
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<pii,
             null_type,
             less<pii>,
             rb_tree_tag,
             tree_order_statistics_node_update> ordered_set;
**/

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 4e3 + 10;
const int MOD = 1e9 + 7;
int n, numNode;
ll frac[NM], finv[NM];

struct Point {
    long long x, y;

    bool operator<(const Point &v) const { return x == v.x ? y < v.y : x < v.x; }
    long long cross(const Point &p, const Point &q) const { return (p.x - x) * (q.y - y) - (p.y - y) * (q.x - x); }

} a[NM], b[NM], poly[NM];

void add(ll &a, ll b){
    if(a + b >= MOD) a += b - MOD;
    else a += b;
}
ll pw(ll x, ll k) {
    if(k <= 1) return k ? x : 1;
    ll tmp = pw(x, k >> 1);
    if(k & 1) return 1LL * tmp * tmp % MOD * x % MOD;
    else return 1LL * tmp * tmp % MOD;
}
ll comb(ll k, ll n) {
	return k > n ? 0 : (1LL * frac[n] * finv[k] % MOD) * finv[n - k] % MOD;
}
ll ccw(Point A, Point B, Point C) {
    return A.x * (B.y - C.y) + B.x * (C.y - A.y) + C.x * (A.y - B.y);
}
bool isRight(Point A, Point B) {
    return (A.x != B.x) ? A.x > B.x : A.y > B.y;
}
bool cmp(const Point A, const Point B) {
    if(isRight(A, b[1]) != isRight(B, b[1]))
        return (isRight(A, b[1])) < (isRight(B, b[1]));

    ll cur = ccw(b[1], A, B);
    if(cur == 0) return A.x < B.x;
    return cur > 0;
}
void convexHull() {
    sort(a + 1, a + n + 1);
    int k = 0;
    for(int i = 1; i <= n; i++) {
        while(k >= 2 && poly[k - 2].cross(poly[k - 1], a[i]) <= 0) k--;
        poly[k++] = a[i];
    }
    for(int i = n - 1, t = k + 1; i > 0; i--) {
        while(k >= t && poly[k - 2].cross(poly[k - 1], a[i]) <= 0) k--;
        poly[k++] = a[i];
    }
    numNode = k;
}
void xuli() {
    ll res = 0;
    for(int i = 1; i <= n; i++) {
        b[1] = a[i];
        int id = 2;
        for(int j = 1; j <= n; j++)
            if(j != i) b[id++] = a[j];

        sort(b + 2, b + n + 1, cmp);
        for(int i = 2; i <= n; i++) b[i + n - 1] = b[i];

        //for(int j = 1; j < 2 * n; j++) cout << b[j].x << " " << b[j].y << '\n';

        int last = 2;

        for(int j = 2; j <= n; j++) {
            maximize(last, j);
            while(ccw(b[1], b[j], b[last + 1]) > 0 && last < 2 * n) last++;
            res += comb(2, last - j) * comb(2, n - last + j - 2);
        }
        //cout << res << '\n';
        //cout << '\n';
    }

    cout << res / 2;
}
int32_t main()
{
    FastIO
    freopen("BUILDING.INP", "r", stdin);
    freopen("BUILDING.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        a[i] = {x, y};
    }

    frac[0] = 1;
    for(int i = 1; i <= n; i++) frac[i] = (1LL * frac[i - 1] * i) % MOD;
    finv[n] = pw(frac[n], MOD - 2);
    for (int i = n; i >= 1; i--) finv[i - 1] = (1LL * finv[i] * i) % MOD;

    xuli();
    return 0;
}

/* Author: hxzinh */


