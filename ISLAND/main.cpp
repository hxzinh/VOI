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

const int NM = 505;
const int MAX = 1e6 + 10;
int n, m, numEdges = 0, numNode = 0;
int par[MAX];
string a[NM];
set<int> row[NM], col[NM];

struct Data {
    int u, v, w;
} edges[MAX];

int root(int x) {
    if(par[x] < 0) return x;
    return par[x] = root(par[x]);
}
void join(int x, int y) {
    int u = root(x), v = root(y);
    if(u == v) return;

    if(par[v] < par[u]) swap(u, v);

    par[u] += par[v];
    par[v] = u;
}
void xuli() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) if(a[i][j] == '1') {
            row[i].insert(j);
            col[j].insert(i);
            numNode++;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) if(a[i][j] == '1') {
            auto itRow = row[i].find(j);
            if(itRow != row[i].end()) {
                auto nxtIt = itRow;
                nxtIt++;
                if(nxtIt != row[i].end()) {
                    int u = *nxtIt;
                    int cost = u - j - 1;
                    edges[++numEdges] = {m * i + j, m * i + u, cost};
                }
            }

            auto itCol = col[j].find(i);
            int tmp = *itCol;
            if(itCol != col[j].end()) {
                auto nxtIt = itCol;
                nxtIt++;
                if(nxtIt != col[j].end()) {
                    int u = *nxtIt;
                    int cost = u - i - 1;
                    edges[++numEdges] = {m * i + j, m * u + j, cost};
                }
            }
        }
    }

    sort(edges + 1, edges + numEdges + 1, [](const Data A, const Data B){
         return A.w < B.w;
    });

    memset(par, -1, sizeof par);

    //for(int i = 1; i <= numEdges; i++) cout << edges[i].u << " " << edges[i].v << " " << edges[i].w << '\n';

    ll res = 0, cnt = 0;
    for(int i = 1; i <= numEdges; i++) {
        int u = root(edges[i].u), v = root(edges[i].v), cost = edges[i].w;
        if(u != v) {
            res += cost;
            cnt++;
            join(u, v);
        }
        if(cnt == numNode - 1) break;
    }

    if(cnt >= numNode - 1) cout << res;
    else cout << -1;
}
int32_t main()
{
    FastIO
    freopen("ISLAND.INP", "r", stdin);
    freopen("ISLAND.OUT", "w", stdout);
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];

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
