
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
int n, m, T;
int Low[NM], Num[NM], Time = 0, numComp = 0;
vector<pii> edges[NM];
vector<int> comp[NM];
stack<int> st;

void init() {
    while(st.size()) st.pop();
    for(int i = 1; i <= n; i++) {
        Low[i] = Num[i] = 0;
    }

    for(int i = 1; i <= numComp; i++) comp[i].clear();
    numComp = Time = 0;
}
void dfs(int u, int p) {
    Low[u] = Num[u] = ++Time;
    st.push(u);
    for(pii v : edges[u]) if(v.fi != p) {
        if(Num[v.fi]) minimize(Low[u], Num[v.fi]);
        else {
            dfs(v.fi, u);
            minimize(Low[u], Low[v.fi]);
        }
    }

    if(Num[u] != Low[u]) {
        numComp++;
        int v;
        do {
            v = st.top();
            st.pop();
            comp[numComp].push_back(v);
            Num[v] = Low[v] = INF;
        } while(v != u);
    }
}
void xuli() {
    init();
    for(int i = 1; i <= n; i++) if(!Num[i]) dfs(i, 0);

    cout << numComp << '\n';
    for(int i = 1; i <= numComp; i++) {
        for(int u : comp[i]) cout << u << " ";
        cout << '\n';
    }
}
int32_t main()
{
    FastIO
    freopen("BICONNECTED.INP", "r", stdin);
    freopen("BICONNECTED.OUT", "w", stdout);
    cin >> T;
    while(T--) {
        cin >> n >> m;
        for(int i = 1; i <= m; i++) {
            int u, v;
            cin >> u >> v;
            edges[u].push_back({v, i});
            edges[v].push_back({u, i});
        }

        xuli();
        cout << '\n';
    }
    return 0;
}

/* Author: hxzinh */
