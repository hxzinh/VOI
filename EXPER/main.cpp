#include <bits/stdc++.h>
#define ll long long
#define int long long
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

const int NM = 35 + 10;
int n, m;
string s;
int a[NM], b[NM], prefx[NM], prefy[NM];

void xuli() {
    vector<int> px, py;
    for(int i = 1; i <= n; i++) {
        px.push_back(a[i]);
        py.push_back(b[i]);
    }

    sort(ALL(px)); sort(ALL(py));

    prefx[0] = abs(px[0]); prefy[0] = py[0];
    for(int i = 1; i < n; i++) {
        prefx[i] = prefx[i - 1] + px[i];
        prefy[i] = prefy[i - 1] + py[i];
    }

    int x = 0, y = 0;
    for(int i = 1; i <= m; i++) {
        if(s[i] == 'N') y++;
        if(s[i] == 'S') y--;
        if(s[i] == 'E') x++;
        if(s[i] == 'W') x--;

        int res = 0;

        int idx = upper_bound(ALL(px), x) - px.begin();
        res += x * idx - prefx[idx];
        res += prefx[n - 1] - prefx[idx] - x * idx;

        int idy = upper_bound(ALL(py), y) - py.begin();
        res += y * idy - prefy[idy];
        res += prefy[n - 1] - prefy[idy] - y * idy;

        cout << res << '\n';
    }
}
int32_t main()
{
    FastIO
    freopen("EXPER.INP", "r", stdin);
    freopen("EXPER.OUT", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        int u, v;
        cin >> u >> v;
        a[i] = u ;
        b[i] = v ;
    }
    cin >> s;
    s = '#' + s;

    xuli();
    return 0;
}

/* Author: hxzinh */

