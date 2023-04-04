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

const int NM = 2e5 + 10;
int n, m;
set<int> edges[NM], S;
vector<int> res;

void xuli() {
    for(int i = 1; i <= n; i++) S.insert(i);

    while(S.size()) {
        int ans = 0;
        queue<int> q;
        q.push(*S.begin());
        S.erase(S.begin());
        while(q.size()) {
            int u = q.front();
            q.pop();

            ans++;

            vector<int> visited;
            for(int v : S) if(edges[u].find(v) == edges[u].end()) {
                q.push(v);
                visited.push_back(v);
            }
            for(int v : visited) S.erase(v);
        }
        res.push_back(ans);
    }

    cout << res.size() << '\n';
    sort(ALL(res));
    for(int u : res) cout << u << " ";
}
int32_t main()
{
    FastIO
    freopen("CONNECTED.INP", "r", stdin);
    freopen("CONNECTED.OUT", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        edges[u].insert(v);
        edges[v].insert(u);
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
