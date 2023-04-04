#include<bits/stdc++.h>
#define INF 1e9
#define ii pair<int, int>
#define fi first
#define se second
#define FASTIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM = 1E4 + 10;
int dx[] = {1, -1, -1, 1};
int dy[] = {1, 1, -1, -1};
int tx[] = {1, -1, 0, 0};
int ty[] = {0, 0, 1, -1};
int n, T;
int res = INF, sum = 0;
int a[NM][NM];
bool r[NM], c[NM];

void readfile(){
    freopen("GAME.INP", "r", stdin);
    freopen("GAME.OUT", "w", stdout);
    cin >> T;
}
void dp(int u, int v, int cnt){
    if(cnt == n){
        res = min(res, sum);
        return;
    }
    if(u > n || u <= 0 || v > n || v <= 0) return;
    if(!r[u] || !c[v]) return;
    r[u] = false; c[v] = false;
    sum += a[u][v];
    for(int i = 0; i < 4; i++){
        int r = u + dx[i];
        int c = v + dy[i];
        dp(r, c, cnt + 1);
    }
    sum -= a[u][v];
    r[u] = true; c[v] = true;
    for(int i = 0; i < 4; i++){
        int r = u + tx[i];
        int c = v + ty[i];
        dp(r, c, cnt);
    }
    return;
}
void xuli(){
    while(T--){
        cin >> n;
        memset(r, true, (n + 1) * sizeof(bool));
        memset(c, true, (n + 1) * sizeof(bool));
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++) cin >> a[i][j];
        res = INF; sum = 0;
        dp(1, 1, 0);
        cout << res << '\n';
    }
}
int main()
{
    FASTIO
    readfile();
    xuli();
    return 0;
}
