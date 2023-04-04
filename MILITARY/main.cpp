#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define pii pair<int, int>
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

const int NM = 4e3 + 10;
int n;
int id[NM];
bool cx[NM];

struct Point {
    int x, y;
} a[NM], poly[NM];


void operator -= (Point &A, Point B) {
    A.x -= B.x; A.y -= B.y;
}
bool CCW(Point A, Point B, Point C) {
    C -= B; B -= A;
    return B.x * C.y > B.y * C.x;
}

bool cmp(const Point A, const Point B){
    return (A.x == B.x ? A.y < B.y : A.x < B.x);
}
void ConvexHull() {
    int i, k, t;
    k = 1;
    for(i = 1; i <= n; i++) {
        while (k > 2 && CCW(a[id[k - 2]], a[id[k - 1]], a[i])) k--;
        id[k++] = i;
    }
    for(i = n, t = k + 1; i; i--) {
        while (k > t && CCW(a[id[k - 2]], a[id[k - 1]], a[i])) k--;
        id[k++] = i;
    }

    for(i = 1; i <= n; i++) cx[i] = false;
    for(i = 1; i < k; i++) cx[id[i]] = true;
    int m = 0;
    for(i = 1; i <= n ; i++) if (!cx[i])
        a[++m] = a[i];
    n = m;
}
void xuli(){
    sort(a + 1, a + n + 1, cmp);
    int res = 0;
    while(n > 2){
        res++;
        ConvexHull();
    }
    cout << res;
}
int32_t main()
{
    FastIO
    freopen("MILITARY.INP", "r", stdin);
    freopen("MILITARY.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i].x >> a[i].y;

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
