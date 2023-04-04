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

const int NM = 1e4 + 10;
int n, m;
int par[NM];

struct Data {
    int u, v, w;
} a[NM];

int root(int x) {
    if(par[x] < 0) return x;
    return par[x] = root(par[x]);
}
void join(int u, int v){
    if(par[u] > par[v]) swap(u, v);
    par[u] += par[v];
    par[v] = u;
}
bool cmp(const Data A, const Data B) {
    return A.w < B.w;
}
void xuli() {
    sort(a + 1, a + m + 1, cmp);
    int sMin = -INF, sMax = INF;
    for(int i = 1; i <= m; i++) {
        int cnt = 0;
        memset(par, -1, sizeof(int) * (n + 7));
        int curMin = a[i].w, curMax = -1;
        for(int j = i; j <= m; j++) {
            int u = root(a[j].u), v = root(a[j].v);
            if(u == v) continue;
            join(u, v);
            cnt++;
            if(cnt == n - 1) {
                maximize(curMax, a[j].w);
                break;
            }
        }
        if(cnt < n - 1) break;
        if(sMax - sMin > curMax - curMin) {
            sMax = curMax;
            sMin = curMin;
        }
    }

    cout << sMin << " " << sMax;
}
int32_t main()
{
    FastIO
    freopen("SPEED.INP", "r", stdin);
    freopen("SPEED.OUT", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        a[i] = {u, v, w};
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
