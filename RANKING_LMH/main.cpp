#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f3f3f3f3f
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
typedef long double ld;

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

const int NM = 1e3 + 10;
int n, maxVal = -1;
double point[NM];
pii a[NM], ans[NM];
pair<double, int> p[NM];

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

double Random(double l, double r) {
    return uniform_real_distribution<double>(l, r)(rng);
}
void solve() {
    ld u = 0.000000001;
    vector<ld> vec;
    for(int i = 1; i <= n; i++) {
        point[i] = u * a[i].fi - a[i].se;
        vec.push_back(point[i]);
    }
    vec.push_back(INF);

    sort(ALL(vec));

    for(int i = 1; i <= n; i++) {
        int curId = upper_bound(ALL(vec), point[i]) - vec.begin();
        int Rank = n - curId + 1;
        minimize(ans[i].fi, Rank);
        maximize(ans[i].se, Rank);
    }

    vec.clear();
    u = 1e9;
    for(int i = 1; i <= n; i++) {
        point[i] = (ld) u * a[i].fi - a[i].se;
        vec.push_back(point[i]);
    }
    vec.push_back(INF);

    sort(ALL(vec));

    for(int i = 1; i <= n; i++) {
        int curId = upper_bound(ALL(vec), point[i]) - vec.begin();
        int Rank = n - curId + 1;
        minimize(ans[i].fi, Rank);
        maximize(ans[i].se, Rank);
    }
}
void MagicFunc() {
    std::srand(std::time(nullptr));

    for(int i = 1; i <= n; i++) ans[i] = {INF, -INF};

    for(int t = 1; t <= 10000; t++) {
        ld u = Random(1e-9, (ld)maxVal);

        vector<ld> vec;
        for(int i = 1; i <= n; i++) {
            point[i] = (ld) u * a[i].fi - a[i].se;
            vec.push_back(point[i]);
        }
        vec.push_back(INF);

        sort(ALL(vec));

        for(int i = 1; i <= n; i++) {
            int curId = upper_bound(ALL(vec), point[i]) - vec.begin();
            int Rank = n - curId + 1;
            minimize(ans[i].fi, Rank);
            maximize(ans[i].se, Rank);
        }
    }

    solve();

    for(int i = 1; i <= n; i++) cout << ans[i].fi << " " << ans[i].se << '\n';
}
void Try() {
    for(int i = 1; i <= n; i++) {
        int resMax = 0, resMin = 0, ansMax = 0, ansMin = 0;
        ld uMin = a[i].fi * 1e-9 - a[i].se;
        ld uMax = a[i].fi * 1e9 - a[i].se;
        for(int j = 1; j <= n; j++) if(i != j) {
            ld vMin = a[j].fi * 1e-9 - a[j].se;
            ld vMax = a[j].fi* 1e9 - a[j].se;

            if(uMin >= vMin) resMin++;
            if(uMax >= vMax) resMax++;
        }

        minimize(ans[i].fi, n - max(resMax, resMin));
        maximize(ans[i].se, n - min(resMax, resMin));
    }
}
void xuli() {
    for(int i = 1; i <= n; i++) ans[i] = {INF, -INF};

    for(int i = 1; i <= n; i++) {
        int cnt = 0, resMax = 0, resMin = INF;
        vector<pair<ld, int>> events;
        for(int j = 1; j <= n; j++) if(j != i) {
            ld u = (ld) (a[i].se - a[j].se) / (ld) (a[i].fi - a[j].fi);
            if(a[i].fi - a[j].fi > 0) {
                if(u <= 0) cnt++;
                else events.push_back({u, 1});
            }
            if(a[i].fi - a[j].fi < 0 && u >= 0) { //ai < aj && bi > bj
                events.push_back({1e-9, 1});
                events.push_back({u + 1e-9, -1});
            }
            if(a[i].fi - a[j].fi == 0) cnt += (a[i].se <= a[j].se);
        }
        sort(ALL(events), [](const pair<ld, int> A, const pair<ld, int> B){
            return A.fi < B.fi;
        });

        ld pre = -1;
        for(pair<ld, int> u : events) {
            if(u.fi != pre && pre > 0) {
                maximize(resMax, cnt);
                minimize(resMin, cnt);
            }
            cnt += u.se;
            pre = u.fi;
        }
        maximize(resMax, cnt);
        minimize(resMin, cnt);

        minimize(ans[i].fi, n - resMax);
        maximize(ans[i].se, n - resMin);
    }

    Try();

    for(int i = 1; i <= n; i++) cout << ans[i].fi << " " << ans[i].se << '\n';
}
int32_t main()
{
    FastIO
    freopen("RANKING.INP", "r", stdin);
    freopen("RANKING.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int u, v;
        cin >> u >> v;
        maximize(maxVal, max(u, v));
        a[i] = {u, v};
    }

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
