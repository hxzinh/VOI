#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e5 + 10;
int n, m, r, t, c, start;
int a[55][55], g[55][55][55], dist[100][55][55];
int s[55][55];

void readfile(){
    freopen("INP", "r", stdin);
    freopen("OUT", "w", stdout);
    cin >> n >> m >> r;
}
void sub1(){
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(i == j) s[i][j] = 0;
            else s[i][j] = INF;
    while(m--){
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++){
                cin >> a[i][j];
                minimize(s[i][j], a[i][j]);
            }
        for(int k = 1; k <= n; k++)
            for(int i = 1; i <= n; i++)
                for(int j = 1; j <= n; j++)
                    if(a[i][j] > a[i][k] + a[k][j]){
                        a[i][j] = a[i][k] + a[k][j];
                        minimize(s[i][j], a[i][j]);
                    }
    }
    while(r--){
        cin >> start >> t >> c;
        cout << s[start][t] << '\n';
    }
}
void sub3(){
    for(int i = 0; i <= n; i++)
        for(int j = 1; j <= n; j++)
            for(int k = 1; k <= n; k++) dist[i][j][k] = INF;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            for(int k = 1; k <= n; k++) g[i][j][k] = INF;

    for(int cnt = 1; cnt <= m; cnt++){
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++){
                cin >> a[i][j];
                g[cnt][i][j] = a[i][j];
            }
        for(int k = 1; k <= n; k++)
            for(int i = 1; i <= n; i++)
                for(int j = 1; j <= n; j++)
                    if(g[cnt][i][j] > g[cnt][i][k] + g[cnt][k][j]){
                        g[cnt][i][j] = g[cnt][i][k] + g[cnt][k][j];
                    }
    }

    for(int cnt = 1; cnt <= m; cnt++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                minimize(dist[0][i][j], g[cnt][i][j]);

    for(int cnt = 1; cnt <= n; cnt++){
        for(int k = 1; k <= n; k++)
            for(int i = 1; i <= n; i++)
                for(int j = 1; j <= n; j++)
                    minimize(dist[cnt][i][j], dist[cnt - 1][i][k] + dist[0][k][j]);
    }

    while(r--){
        cin >> start >> t >> c;
        c = min(c, n - 1);
        int res = INF;
        for(int i = 0; i <= c; i++) minimize(res, dist[i][start][t]);
        cout << res << '\n';
    }
}
int main()
{
    FastIO
    readfile();
    if(m == 1) sub1();
    else sub3();
    return 0;
}
