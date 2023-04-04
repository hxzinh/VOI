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

const int NM = 5e3 + 10;
int n, T, numEdges;
vector<int> edges[NM];
bool cx[NM];

struct Data {
    int u, v, cost;
};

Data e[NM];

struct Dijointset {
    int n;
    vector<int> lab;

    Dijointset(int _n = 0) {
        n = _n;
        lab.assign(n + 7, -1);
    }

    void init() {
        lab = vector<int>(n + 7, -1);
    }

    int root(int x) {
        if(lab[x] < 0) return x;
        return lab[x] = root(lab[x]);
    }

    bool join(int u, int v) {
        u = root(u); v = root(v);
        if(u == v) return false;

        if(lab[u] > lab[v]) swap(u, v);
        lab[u] += lab[v];
        lab[v] = u;

        return true;
    }
};

void sub1() {
    Dijointset dsu(2 * n);
    int res = INF;
    for(int mask = 0; mask < MASK(numEdges); mask++) {
        dsu.init();
        int ans = 0, curCnt = 0;
        for(int i = 1; i <= numEdges; i++) if(BIT(mask, i - 1)) {
            ans += e[i].cost;
            if(dsu.join(e[i].u, e[i].v)) curCnt++;
        }

        if(curCnt == 2 * n - 1 && ans % 2 == 0) minimize(res, ans);
    }

    cout << res << '\n';
}
void xuli() {
    sort(e + 1, e + numEdges + 1, [](const Data &A, const Data &B){
        return A.cost < B.cost;
    });

    Dijointset dsu(2 * n);

    int cntEdges = 0, res = 0, tmp = INF;
    vector<int> vec, odd, even;
    for(int i = 1; i <= numEdges; i++) {
        if(dsu.join(e[i].u, e[i].v)) {
            res += e[i].cost;
            cntEdges++;
            vec.push_back(i);
        }

        if(cntEdges == 2 * n - 1) break;
    }

    for(int i = 1; i <= numEdges; i++) {
        if(e[i].cost & 1) odd.push_back(i);
        else even.push_back(i);
    }

    if(res % 2 == 0) {
        cout << res << '\n';
        return;
    }

    int ans = INF;
    Dijointset tsu(2 * n);
    for(int cur : vec) {
        tsu.init();
        int curCost = 0;
        for(int i : vec) if(i != cur) {
            tsu.join(e[i].u, e[i].v);
            curCost += e[i].cost;
        }

        if(e[cur].cost & 1) {
            for(int i : even) {
                int u = tsu.root(e[i].u), v = tsu.root(e[i].v);
                if(u != v) {
                    minimize(ans, res - e[cur].cost + e[i].cost);
                    break;
                }
            }
        }
        else {
            for(int i : odd) {
                int u = tsu.root(e[i].u), v = tsu.root(e[i].v);
                if(u != v) {
                    minimize(ans, res - e[cur].cost + e[i].cost);
                    break;
                }
            }
        }
    }

    cout << ans << '\n';
}
int32_t main()
{
    FastIO
    freopen("NET2LINE.INP", "r", stdin);
    freopen("NET2LINE.OUT", "w", stdout);
    cin >> T;
    while(T--) {
        cin >> n;
        numEdges = 0;
        for(int i = 1; i <= 2 * n; i++) edges[i].clear();
        for(int i = 1; i < n; i++) {
            int u; cin >> u;
            e[++numEdges] = {i, i + 1, u};
            edges[i].push_back(numEdges);
            edges[i + 1].push_back(numEdges);
        }
        for(int i = n + 1; i < 2 * n; i++) {
            int u; cin >> u;
            e[++numEdges] = {i, i + 1, u};
            edges[i].push_back(numEdges);
            edges[i + 1].push_back(numEdges);
        }
        for(int i = 1; i <= n; i++) {
            int u; cin >> u;
            e[++numEdges] = {i, i + n, u};
            edges[i].push_back(numEdges);
            edges[i + n].push_back(numEdges);
        }

        xuli();
    }
    return 0;
}

/* Author: hxzinh */


