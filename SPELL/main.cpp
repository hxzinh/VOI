#include <bits/stdc++.h>
#define ll long long
#define INF 1e8;
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM = 3e2 + 10;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, m, k;
int res = INF;
int dist[NM][NM][NM];
char a[NM][NM], t[NM];

struct Data{
    int posX, posY, step, numWord;

    Data(int _x = 0, int _y = 0, int _step = 0, int _numWord = 0){
        posX = _x;
        posY = _y;
        step = _step;
        numWord = _numWord;
    }
};
queue<Data> q;

void minimize(int &a, int b){
    if(a > b){a == b; return;}
    else return;
}
void readfile(){
    freopen("SPELL.INP", "r", stdin);
    freopen("SPELL.OUT", "w", stdout);
    cin >> n >> m >> k;
    for(int i = 1; i <= k; i++) cin >> t[i];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) cin >> a[i][j];
    memset(dist, -1, sizeof(dist));
}
void bfs(){
    while(!q.empty()){
        int r = q.front().posX;
        int c = q.front().posY;
        int step = q.front().step;
        int numWord = q.front().numWord;
        q.pop();
        if(numWord == k){
            cout << step;
            return;
        }
        for(int i = 0; i < 4; i++){
            int u = r + dx[i], v = c + dy[i];
            if(u > n || u < 1 || v > m || v < 1) continue;
            int newNum = a[u][v] == t[numWord + 1] ? numWord + 1 : numWord;
            if(dist[u][v][newNum] < 0){
                dist[u][v][newNum] = step + 1;
                q.push(Data(u, v, step + 1, newNum));
            }
        }
    }
}
void xuli(){
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            dist[i][j][0] = 0;
            q.push(Data(i, j, 0, 0));
        }
    bfs();
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
