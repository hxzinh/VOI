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

const int NM = 2e3 + 10;
int n, m;
int a[NM], b[NM],id[NM];
int dp[25][NM], tmp[25][NM], g[NM][NM];

struct FenwickTree {
    int n;
};

bool check(int x, int y, int u, int v) {
    return (x > y && u > v) || (x < y && u < v) || (x == y && u == v);
}
void sub1() {
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) g[i][j] = 1;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            for(int u = 1; u < i; u++) {
                for(int v = 1; v < j; v++) {
                    if(check(a[i], a[u], b[j], b[v])) {
                        maximize(g[i][j], g[u][v] + 1);
                    }
                }
            }
        }
    }

    int res = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) maximize(res, g[i][j]);

    cout << n + m - res * 2;
}
void sub2() {
    for(int i = 1; i <= 20; i++)
        for(int j = 1; j <= m; j++) tmp[i][j] = 1;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            for(int u = 1; u <= 20; u++) {
                for(int v = 1; v < j; v++) {
                    if(check(a[i], u, b[j], b[v])) {
                        maximize(tmp[a[i]][j], dp[u][v] + 1);
                    }
                }
            }
        }

        for(int j = 1; j <= m; j++) {
            maximize(dp[a[i]][j], tmp[a[i]][j]);
            tmp[a[i]][j] = 1;
        }
    }

    int res = 0;
    for(int i = 1; i <= 20; i++)
        for(int j = 1; j <= m; j++) maximize(res, dp[i][j]);

    cout << n + m - 2 * res;
}
void sub3() {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            for(int u = 1; u <= 20; u++) {
                for(int v = 1; v <= 20; v++) {
                    if(check(a[i], u, b[j], v)) {
                        maximize(tmp[a[i]][b[j]], dp[u][v] + 1);
                    }
                }
            }
        }

        for(int j = 1; j <= 20; j++) {
            maximize(dp[a[i]][j], tmp[a[i]][j]);
            tmp[a[i]][j] = 1;
        }
    }

    int res = 0;
    for(int i = 1; i <= 20; i++)
        for(int j = 1; j <= 20; j++) maximize(res, dp[i][j]);

    cout << n + m - 2 * res;
}
void xuli() {

}
int32_t main()
{
    FastIO
    freopen("ISUBSEQ.INP", "r", stdin);
    freopen("ISUBSEQ.OUT", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= m; i++) cin >> b[i];

    vector<int> vec;
    for(int i = 1; i <= m; i++) vec.push_back(b[i]);
    sort(ALL(vec));
    vec.resize(unique(ALL(vec)) - vec.begin());
    for(int i = 1; i <= m; i++) b[i] = lower_bound(ALL(vec), b[i]) - vec.begin() + 1;

    bool ok1 = true, ok2 = true;
    for(int i = 1; i <= n; i++)
        if(a[i] > 20) ok1 = false;
    for(int i = 1; i <= m; i++)
        if(b[i] > 20) ok2 = false;

    if(n <= 20 && m <= 20) sub1();
    else if(ok1 && ok2) sub3();
    else sub2();

    sub3();
    return 0;
}

/* Author: hxzinh */

Nguyễn Anh Phong
{
    int n;
    vector <int> tree;

    FenwickTree(int _n = 0)
    {
        n = _n;
        tree.assign(n + 5, 0);
    }

    void update(bool isLess, int x, int v)
    {
        if (isLess)
        {
            for (; x <= n; x += x & -x)
                tree[x] = max(tree[x], v);
        }
        else
        {
            for (; x >= 1; x -= x & -x)
                tree[x] = max(tree[x], v);
        }
    }

    int get(bool isLess, int x)
    {
        int res = 0;
        if (isLess)
        {
            for (; x >= 1; x -= x & -x)
                res = max(res, tree[x]);
        }
        else
        {
            for (; x <= n; x += x & -x)
                res = max(res, tree[x]);
        }
        return res;
    }
};

const int mxN = 2e3 + 5;

int n, m, a[mxN],b[mxN];

void Shiba_Read()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= m; ++i) cin >> b[i];
}

int dp[22][2020];
int l[22][2022];



int As[2020];
void Shiba_Project2()
{
    int res = 0;

    set <int> s;
    for (int i = 1; i <= m; ++i)
        s.insert(b[i]);

    vector <int> v(s.begin(), s.end());
    for (int i = 1; i <= m; ++i)
        b[i] = lower_bound(v.begin(), v.end(), b[i]) - v.begin() + 1;

    for (int i = 1; i <= n; ++i)
    {
        FenwickTree fwMore(v.size()), fwLess(v.size());
        memset(As, 0, sizeof As);

        for (int j = 1; j <= m; ++j)
        {
            /// be

            int More = fwMore.get(0, b[j] + 1);
            int Less = fwLess.get(1, b[j] - 1);

            /// bang
            l[a[i]][j] = max({l[a[i]][j], More + 1, Less + 1, 1 + As[b[j]]});
            More = Less = 0;

            for (int u = 1; u <= 20; u++)
            {
                if (u < a[i]) Less = max(Less, dp[u][j]);
                if (u == a[i]) As[b[j]] = max(As[b[j]], dp[u][j]);
                if (u > a[i]) More = max(More, dp[u][j]);
            }

            fwMore.update(0, b[j], More);
            fwLess.update(1, b[j], Less);
        }

        for (int u = 1; u <= 20; u++)
        {
            for (int j = 1; j <= m; j++)
            {
                dp[u][j] = max(dp[u][j], l[u][j]);
                l[u][j] = 0;
            }
        }
    }

    for (int u = 1; u <= 20; u++)
    {
        for (int j = 1; j <= m; j++)
            res = max(res, dp[u][j]);
    }

    cout << n + m - 2 * res;
}

void Shiba_Process()
{
    if (n <= 200 && m <= 200)
    {
        Shiba_Project1();
        return;
    }
    Shiba_Project2();
}


