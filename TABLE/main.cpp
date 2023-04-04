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
const int BLSIZE = 320;
int n, m, q;
ll a[NM][NM], s[NM][NM], d[NM][NM];

struct Data {
    int type, x, y, u, v, w;
} query[100005];

void xuli(){
    for(int u = 1; u <= n; u++)
        for(int v = 1; v <= m; v++)
            s[u][v] = s[u - 1][v] + s[u][v - 1] - s[u - 1][v - 1] + a[u][v];

    for(int i = 1; i <= q; i++){
        int type, x, y, u, v, w;
        cin >> type >> x >> y >> u >> v;
        query[i] = {type, x, y, u, v, 0};

        int t = i / BLSIZE + (i % BLSIZE != 0);
        if(type == 1){
            cin >> w;
            query[i].w = w;
            d[x][y] += w;
            d[x][v + 1] -= 1LL * w;
            d[u + 1][y] -= 1LL * w;
            d[u + 1][v + 1] += 1LL * w;
        }

        if(type == 2){
            ll res = s[u][v] - s[u][y - 1] - s[x - 1][v] + s[x - 1][y - 1];
            for(int j = BLSIZE * (t - 1) + 1; j <= i; j++) if(query[j].type == 1){
                int r = max(0, min(u, query[j].u) - max(x, query[j].x) + 1) * max(0, (min(v, query[j].v) - max(y, query[j].y) + 1));
                res += 1LL * query[j].w * r;
            }

            cout << res << '\n';
        }

        if(i % BLSIZE == 0){
            for (int x = 1; x <= n; x++) {
                for (int y = 1; y <= m; y++)
                    d[x][y] = d[x - 1][y] + d[x][y - 1] - d[x - 1][y - 1] + d[x][y];
            }

            for (int x = 1; x <= n; x++) {
                for (int y = 1; y <= m; y++) {
                    a[x][y] += d[x][y];
                    d[x][y] = 0;
                    s[x][y] = s[x - 1][y] + s[x][y - 1] - s[x - 1][y - 1] + a[x][y];
                }
            }
        }
    }
}
int32_t main()
{
    FastIO
    freopen("TABLE.INP", "r", stdin);
    freopen("TABLE.OUT", "w", stdout);
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) cin >> a[i][j];

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
