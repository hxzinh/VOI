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
int n, m;
int Low[NM], Num[NM], id[NM], Time = 0, Count = 0, result = 0, numLeaf = 0;
vector<int> edges[NM], Node[NM], adj[NM];
stack<int> st;
bool visited[NM];

void dfs(int u, int p) {
    Low[u] = Num[u] = ++Time;
    st.push(u);
    for(int v : edges[u]) if(v != p) {
        if(Num[v]) minimize(Low[u], Num[v]);
        else {
            dfs(v, u);
            minimize(Low[u], Low[v]);
        }
    }

    if(Num[u] == Low[u]) {
        Count++;
        int v;
        do {
            v = st.top();
            st.pop();
            Num[v] = Low[v] = INF;
            id[v] = Count;
            Node[Count].push_back(v);
        } while(v != u);
    }
}
void dfs2(int u, int p) {
    visited[u] = true;
    for(int v : adj[u]) if(v != p && v != u) {
        dfs2(v, u);
    }
    int cur = adj[u].size();
    if(adj[u].size() < 2) numLeaf++;
}
void xuli() {
    for(int i = 1; i <= n; i++) if(!Num[i]) dfs(i, -1);

    /**
    cout << Count << '\n';
    for(int i = 1; i <= Count; i++) {
        for(int u : Node[i]) cout << u << " ";
        cout << '\n';
    }
    for(int i = 1; i <= n; i++) cout << id[i] << " ";
    cout << '\n';
    **/


    if(Count <= 2) {
        cout << Count - 1;
        return;
    }

    for(int i = 1; i <= Count; i++) {
        for(int u : Node[i]) {
            for(int v : edges[u]) if(id[v] != i) {
                adj[i].push_back(id[v]);
                adj[id[v]].push_back(i);
            }
        }
    }

    for(int i = 1; i <= Count; i++) {
        sort(ALL(adj[i]));
        adj[i].resize(unique(ALL(adj[i])) - adj[i].begin());
    }

    int aloneNode = 0;
    for(int i = 1; i <= Count; i++) {
        if(!visited[i]) {
            numLeaf = 0;
            dfs2(i, -1);
            if(numLeaf >= 2) result += (numLeaf + 1) / 2 - 1;
            aloneNode++;
        }
    }

    result += aloneNode;

    cout << result;
}
int32_t main()
{
    FastIO
    freopen("NEXT.INP", "r", stdin);
    freopen("NEXT.OUT", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
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
