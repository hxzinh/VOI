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
int n, m;
int deg[NM], a[NM][NM], fake[NM][NM];
vector<int> res[NM], trace;

void Euler(int u) {
    for(int v = 1; v <= n; v++) if(fake[u][v]) {
        if(fake[u][v] == 3) {
            fake[u][v] = 2;
            fake[v][u] = 2;
        } else {
            fake[u][v] = 0;
            fake[v][u] = 0;
        }

        Euler(v);
    }
    trace.push_back(u);
}
void xuli() {
    vector<int> oddNode;
    for(int i = 1; i <= n; i++) if(deg[i] % 2 != 0) oddNode.push_back(i);

    if(oddNode.size() > 2) {
        oddNode.pop_back();
        oddNode.pop_back();
        for(int i = 0; i < oddNode.size(); i += 2) {
            int u = oddNode[i], v = oddNode[i + 1];

            m++;
            deg[u]++; deg[v]++;
            a[u][v] += 2;
            a[v][u] += 2;
            fake[u][v] += 2;
            fake[v][u] += 2;
        }
    }

    for(int i = 1; i <= n; i++) if(deg[i] % 2 != 0) {
        Euler(i);
        break;
    }

    int cnt = 1;
    for(int i = 0; i < trace.size(); i++) {
        res[cnt].push_back(trace[i]);

        if(i < trace.size() - 1) {
            int u = trace[i], v = trace[i + 1];
            if(a[u][v] == 2) {
                if(res[cnt].size() == 1) res[cnt].clear();
                else cnt++;
                a[u][v] = a[v][u] = 0;
            } else  {
                a[u][v] -= 1;
                a[v][u] -= 1;
            }
        }
    }

    if(res[cnt].size() == 1) cnt--;
    cout << cnt << '\n';
    for(int  i = 1; i <= cnt; i++) {
        cout << res[i].size() << " ";
        for(int u : res[i]) cout << u << " ";
        cout << '\n';
    }
}
int32_t main()
{
    FastIO
    freopen("DRGAME.INP", "r", stdin);
    freopen("DRGAME.OUT", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        a[u][v] = a[v][u] = 1;
        fake[u][v] = fake[v][u] = 1;
        deg[u]++;
        deg[v]++;
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
