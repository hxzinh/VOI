#include <bits/stdc++.h>
#define int long long
#define INF 1e18
#define ii pair<int, int>
#define fi first
#define se second
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 5e2 + 10;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, m, q;
int a[8][NM], f[8][NM], g[3][NM][3][NM];

struct Data {
    int r, c, cost;
};

void readfile(){
    freopen("ROADS.INP", "r", stdin);
    freopen("ROADS.OUT", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++) cin >> a[i][j];
    }
    cin >> q;
}
void sub1(){
    queue<ii> pq;

    while(q--){
        int x, y, u, v;
        cin >> x >> y >> u >> v;

        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++) f[i][j] = INF;

        while(!pq.empty()) pq.pop();
        pq.push({x, y});

        f[x][y] = a[x][y];
        while(pq.size()){
            int r = pq.front().fi;
            int c = pq.front().se;
            pq.pop();
            if(r == u && c == v) continue;
            for(int i = 0; i < 4; i++){
                int newR = r + dx[i];
                int newC = c + dy[i];
                if(newR > n || newC > m || newR <= 0 || newC <= 0) continue;
                if(minimize(f[newR][newC], f[r][c] + a[newR][newC]))
                    pq.push({newR, newC});
            }
        }
        cout << f[u][v] << '\n';
    }
}
void sub2(){
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            for(int u = 1; u <= n; u++)
                for(int v = 1; v <= m; v++) g[i][j][u][v] = INF;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) g[i][j][i][j] = a[i][j];

    queue<ii> pq;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            while(!pq.empty()) pq.pop();
            pq.push({i, j});

            while(!pq.empty()){
                int u = pq.front().fi, v = pq.front().se;
                pq.pop();
                for(int k = 0; k < 4; k++){
                    int r = u + dx[k];
                    int c = v + dy[k];
                    if(r <= 0 || r > n || c <= 0 || c > m) continue;
                    if(minimize(g[i][j][r][c], g[i][j][u][v] + a[r][c]))
                        pq.push({r, c});
                }
            }
        }
    }

    while(q--){
        int x, y, u, v;
        cin >> x >> y >> u >> v;
        cout << g[x][y][u][v] << '\n';
    }
}
int32_t main()
{
    FastIO
    readfile();
    if(m == 2) sub2();
    else sub1();
    return 0;
}
