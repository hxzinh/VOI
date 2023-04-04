#include <bits/stdc++.h>
#define ll long long
#define oo 99999999999
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
const int NM = 2e3 + 10;
int n, m, q;
char a[NM][NM];
bool cx[NM][NM];

struct Data {
    int cnt;
    pair<int, int> head, last;
};
Data s[NM][NM];

void dfs(int x, int y){
    cx[x][y] = false;
    for(int i = 0; i < 4; i++){
        int r = x + dx[i];
        int c = y + dy[i];
        if(cx[r][c]){
            dfs(r, c);
            s[x][y].cnt += s[r][c].cnt;
        }
    }
}
void readfile(){
    freopen("CCC.INP", "r", stdin);
    freopen("CCC.OUT", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
            s[i][j].cnt = 1;
        }
}
void getDfs(int x, int y){
    cx[x][y] = false;
    for(int i = 0; i < 4; i++){
        int r = x + dx[i];
        int c = y + dy[i];
        if(cx[r][c] && a[x][y] == a[r][c]) getDfs(r, c);
    }
}
void xuli(){
    cin >> q;
    while(q--){
        int x, y, u, v;
        int res = 0;
        cin >> x >> y >> u >> v;
        memset(cx, true, sizeof cx);
        for(int i = x; i <= u; i++)
            for(int j = y; j <= v; j++) if(cx[i][j]){
                res++;
                getDfs(i, j);
            }
        cout << res << '\n';
    }
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
