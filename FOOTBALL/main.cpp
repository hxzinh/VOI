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

const int NM = 1e3 + 10;
int n, m, T;
int a[NM], deg[NM];
pii d[NM];
vector<int> edges[NM], trace;
bool ok[NM], visited[NM][NM];

void Euler(int u) {
    for(int v : edges[u]) if(!visited[u][v] && a[u] && a[v]) {
        a[u]--; a[v]--;
        visited[u][v] = visited[v][u] = true;
        cout << u << " " << v << " ";

        if(ok[v]) {
            ok[v] = false;
            throw 1;
        }
        Euler(v);
    }
}
void xuli() {
    for(int i = 1; i <= n; i++) d[i] = mp(a[i], i);

    for(int i = 1; i <= n; i++) {
        sort(d + i, d + n + 1, greater<pii>());
        for(int j = i + 1; j <= i + d[i].fi; j++) {
            if(j > n || !d[j].fi) {
                cout << -1 << '\n';
                return;
            }
            d[j].fi--;
            edges[d[i].se].push_back(d[j].se);
            edges[d[j].se].push_back(d[i].se);
        }
    }

    for(int i = 1; i <= n; i++) ok[i] = (a[i] % 2 != 0);

    for(int i = 1; i <= n; i++) {
        if(ok[i]) {
            ok[i] = false;
            try {
                Euler(i);
            } catch(...) {}
        }
    }

    for(int i = 1; i <= n; i++) Euler(i);
    cout << '\n';
}
void init() {
    for(int i = 1; i <= n; i++) edges[i].clear();
    memset(visited, false, sizeof visited);
    memset(ok, true, sizeof ok);
}
int32_t main()
{
    FastIO
    freopen("FOOTBALL.INP", "r", stdin);
    freopen("FOOTBALL.OUT", "w", stdout);
    cin >> T;
    while(T--) {
        cin >> n;
        init();
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            deg[i] = a[i];
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
