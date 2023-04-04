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

const int NM = 3e5 + 10;
int n, m;

struct Data {
    int x, y;
} horse[NM], a[NM];

void sub2() {
    for(int i = 1; i <= m; i++) {
        pii Ox = {0, a[i].x}, Oy = {0, a[i].y};
        for(int j = 1; j < i; j++) {
            if(a[i].x < a[j].x) minimize(Ox.se, a[j].x);
            else maximize(Ox.fi, a[j].x);
            if(a[i].y < a[j].y) minimize(Oy.se, a[j].y);
            else maximize(Oy.fi, a[j].y);
        }
        if(Ox.se == INF) Ox.se = a[i].x;
        if(Oy.se == INF) Oy.se = a[i].y;

        //cout << Ox.fi << " " << Ox.se << " " << Oy.fi << " " << Oy.se << '\n';

        int res = 0;
        for(int j = 1; j <= n; j++) {
            pii u = {horse[j].x, horse[j].y};
            if(Ox.fi < horse[j].x && Ox.se >= horse[j].x && Oy.fi < horse[j].y && Oy.se >= horse[j].y)
                res++;
        }
        cout << res << '\n';
    }
}
void sub1() {
    vector<int> vecx, vecy;

}
int32_t main()
{
    FastIO
    freopen("COWBOY.INP", "r", stdin);
    freopen("COWBOY.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int u, v;
        cin >> u >> v;
        horse[i] = {u, v};
    }
    cin >> m;
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        a[i] = {u, v};
    }

    sub2();
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
