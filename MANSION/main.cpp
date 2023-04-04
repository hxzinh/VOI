#include <bits/stdc++.h>
#define ll long long
#define oo 99999999999
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
int dxt[] = {1, -1};
int dyt[] = {0, 0};
int dxf[] = {0, 0};
int dyf[] = {1, -1};
const int NM = 2e5 + 10;
int n, m, k;
vector<int> a[NM];

struct Data {
    int row, col, cost;
    int preRow, preCol;
    bool status;

    Data(int _row = 0, int _col = 0, int _pr = 0, int _pc = 0,  int _cost = 0, bool _status = 0){
        row = _row; preRow = _pr;
        col = _col; preCol = _pc;
        cost = _cost;
        status = _status;
    }

    bool inline operator < (const Data &A) const {
        return cost < A.cost;
    }
};

int add(int x, int y){return abs(x - y) + 1;}
void readfile(){
    freopen("MANSION.INP", "r", stdin);
    freopen("MANSION.OUT", "w", stdout);
    cin >> m >> n >> k;
    for(int i = 1; i <= n; i++) a[i].assign(m + 5, 0);
    for(int i = 1; i <= k; i++){
        int r, c; cin >> r >> c;
        a[r][add(c, n)] = 1;
    }
}
void bfs(int x, int y, bool stat){

}
void xuli(){
    queue<Data> q;
    q.push(Data(n, 1, -1, -1, 0, true));
    while(!q.empty()){
        int r = q.front().row, preRow = q.front().preRow;
        int c = q.front().col, preCol = q.front().preCol;
        int cost = q.front().cost;
        bool status = q.front().status;
        q.pop();
        if(r == n && c == m){
            cout << cost;
            break;
        }
        if(status){
            for(int i = 0; i < 2; i++){
                int newRow = r + dxt[i];
                int newCol = c + dyt[i];
                if(newRow > n || newRow <= 0) continue;
                if(newRow == preRow && newCol == preCol) continue;
                if(a[newRow][newCol] == 1){
                    q.push(Data(newRow, newCol, r, c, cost + 2, status ^ 1));
                    q.push(Data(newRow, newCol, r, c, cost + 1, status));
                } else q.push(Data(newRow, newCol, r, c, cost + 1, status));
            }
        } else {
            for(int i = 0; i < 2; i++){
                int newRow = r + dxf[i];
                int newCol = c + dyf[i];
                if(newCol > m || newCol <= 0) continue;
                if(newRow == preRow && newCol == preCol) continue;
                if(a[newRow][newCol] == 1){
                    q.push(Data(newRow, newCol, r, c, cost + 2, status ^ 1));
                    q.push(Data(newRow, newCol, r, c, cost + 1, status));
                } else q.push(Data(newRow, newCol, r, c, cost + 1, status));
            }
        }
    }
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
