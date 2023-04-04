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

const int NM = 505;
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
int du[] = {-1, 0, 1, 0};
int dv[] = {0, 1, 0, -1};
int n, m, T;
string a[NM];

struct Data {
    int x, y, id, cnt;

    bool inline operator < (const Data &A) const {
        return cnt > A.cnt;
    }
};

void xuli() {
    priority_queue<Data> pq;
    bool ok = false;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) if(a[i][j] == '0') {
            for(int id = 0; id < 4; id++) {
                int x = i + dx[id], y = j + dy[id];
                if(x < 0 || x >= n || y < 0 || y >= m) continue;

                int u = i + du[id], v = j + dv[id];
                if(u < 0 || u >= n || v < 0 || v >= m) continue;

                int dem = (a[x][y] == '1') + (a[u][v] == '1');
                if(dem) pq.push({i, j, id, dem});
            }
        }
    }

    if(!pq.size())
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            for(int id = 0; id < 4; id++) {
                int x = i + dx[id], y = j + dy[id];
                if(x < 0 || x >= n || y < 0 || y >= m) continue;

                int u = i + du[id], v = j + dv[id];
                if(u < 0 || u >= n || v < 0 || v >= m) continue;

                int dem = (a[x][y] == '1') + (a[u][v] == '1') + (a[i][j] == '1');
                if(dem) {
                    pq.push({i, j, id, dem});
                    break;
                }
            }
            if(pq.size()) break;
        }
        if(pq.size()) break;
    }


    int res = 0;
    while(pq.size()) {
        Data cur = pq.top();
        pq.pop();

        int id = cur.id;
        int x = cur.x + dx[id], y = cur.y + dy[id];
        int u = cur.x + du[id], v = cur.y + dv[id];

        if(a[x][y] == '0' && a[u][v] == '0') continue;
        a[x][y] = '0'; a[u][v] = '0'; a[cur.x][cur.y] = '0';
        res++;

        for(int k = 0; k < 4; k++) {
            int nx = x + dx[k], ny = y + dy[k];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            int nu = x + du[k], nv = y + dv[k];
            if(nu < 0 || nu >= n || nv < 0 || nv >= m) continue;
            int dem = (a[nx][ny] == '1') + (a[nu][nv] == '1');
            if(dem) pq.push({x, y, k, dem});

            nx = u + dx[k], ny = v + dy[k];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            nu = u + du[k], nv = v + dv[k];
            if(nu < 0 || nu >= n || nv < 0 || nv >= m) continue;
            dem = (a[nx][ny] == '1') + (a[nu][nv] == '1');
            if(dem) pq.push({u, v, k, dem});
        }
    }

    cout << res << '\n';
}
int32_t main()
{
    FastIO
    freopen("CODE.INP", "r", stdin);
    freopen("CODE.OUT", "w", stdout);
    cin >> T;
    while(T--) {
        cin >> n >> m;
        for(int i = 0; i < n; i++) cin >> a[i];

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
