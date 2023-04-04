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
int T, n, m;
int Num[NM], Low[NM], Time = 0;
vector<int> edges[NM];
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
void init() {
    for(int i = 1; i <= n; i++) {
        Low[i] = Num[i] = 0;
        edges[i].clear();
    }
}
void xuli() {
    bool ok = true;
    for(int i = 1; i <= n; i++) if(!Num[i]) {
        if(ok) ok = false;
        else {
            cout << "NO" << '\n';
            return;
        }
        dfs(i, i);
    }
    cout << "YES" << '\n';
}
int32_t main()
{
    FastIO
    freopen("SPERFECT.INP", "r", stdin);
    freopen("SPERFECT.OUT", "w", stdout);
    cin >> T;
    while(T--) {
        cin >> n >> m;
        init();
        for(int i = 1; i <= m; i++) {
            int u, v;
            cin >> u >> v;
            edges[u].push_back(v);
        }

        xuli();
    }

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
