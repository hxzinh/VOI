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

const int NM = 1e5 + 10;
int n;

struct Point {
    long long x, y;

    bool operator < (const Point &v) const { return x == v.x ? y < v.y : x < v.x; }
    long long cross(const Point &p, const Point &q) const { return (p.x - x) * (q.y - y) - (p.y - y) * (q.x - x); }
} a[NM], poly[NM];

long long size(Point poly[], int k) {
    long long S = (poly[k - 1].x - poly[0].x) * (poly[k - 1].y + poly[0].y);
    for (int i = 1; i < k; ++i)
        S += poly[i - 1].x * poly[i].y + poly[i - 1].y * poly[i].x;
    return S;
}
double getDist(Point A, Point B) {
    return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}
void xuli() {
    sort(a, a + n);
    int k = 0;
    for(int i = 0; i < n; i++) {
        while(k >= 2 && poly[k - 2].cross(poly[k - 1], a[i]) <= 0) k--;
        poly[k++] = a[i];
    }
    for(int i = n - 2, t = k + 1; i >= 0; i--) {
        while(k >= t && poly[k - 2].cross(poly[k - 1], a[i]) <= 0) k--;
        poly[k++] = a[i];
    }

    //for(int i = 0; i < k; i++) cout << poly[i].x << " " << poly[i].y << '\n';

    ll res = size(poly, k);
    double ans = 0;

    for(int i = 1; i < k; i++) ans += getDist(poly[i], poly[i - 1]);
    cout << fixed << setprecision(6) << ans << '\n';
    cout << fixed << setprecision(6) << 0.5 * res << '\n';
}
int32_t main()
{
    FastIO
    freopen("SMALLESTPOLYGON.INP", "r", stdin);
    freopen("SMALLESTPOLYGON.OUT", "w", stdout);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i].x >> a[i].y;

    xuli();
    return 0;
}

/* Author: hxzinh */

/*
-----code ko bug-----code ko bug-----code ko bug--------------

          _.-/`)
         // / / )
      .=// / / / )
     //`/ / / / /
    // /     ` /
   ||         /
    \\       /
     ))    .'
    //    /
         /
*/
