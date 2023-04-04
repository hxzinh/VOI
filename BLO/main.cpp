#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define mp make_pair
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

const int NM = 1e5 + 10;
int n, m;
int Low[NM], Num[NM], child[NM], Time = 0;
vector<int> edges[NM], node;
bool criticalNode[NM], visited[NM];

void dfs(int u, int p) {
    int numChild = 0;
    Low[u] = Num[u] = ++Time;
    for(int v : edges[u]) if(v != p) {
        if(Num[v] != 0) minimize(Low[u], Num[v]);
        else {
            dfs(v, u);
            numChild++;
            minimize(Low[u], Low[v]);

            if(u == p) {
                if(numChild >= 2) criticalNode[u] = true;
            } else {
                if(Low[v] >= Num[u]) criticalNode[u] = true;
            }
        }
    }
}
int dfs2(int u, int p) {
    visited[u] = true;
    int numChild = 1;
    for(int v : edges[u]) if(v != p) {
        if(visited[v]) continue;
        numChild += dfs2(v, u);
    }
    return numChild;
}
void xuli() {
    for(int i = 1; i <= n; i++) if(!Num[i]) dfs(i, i);
    for(int i = 1; i <= n; i++) if(criticalNode[i]) {
        node.push_back(i);
    }

    int res = 1;
    for(int i = 1; i <= n; i++) {
        if(!criticalNode[i]) {
            visited[i] = true;
            for(int v : edges[i]) res = res * dfs2(v, i);
            res *= 2;
            break;
        }
    }

    for(int i = 1; i <= n; i++) {
        if(criticalNode[i]) {
            memset(visited, false, sizeof visited);
            int ans = 1, cnt = 0;
            visited[i] = true;
            for(int v : edges[i]) if(!visited[v]) {
                int cur = dfs2(v, i);
                cnt += cur;
                ans = ans * cur;
            }
            ans += cnt;
            ans *= 2;
            cout << ans << " ";
        } else cout << res << " ";
    }
}
int32_t main()
{
    FastIO
    freopen("BLO.INP", "r", stdin);
    freopen("BLO.OUT", "w", stdout);
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
