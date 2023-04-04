#include <bits/stdc++.h>
#define ll long long
#define INF 1e8
#define fi first
#define se second
#define MASK(x) (1LL << (x))
#define BIT(x, i) ((x) >> (i) & 1)
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM = 2e3 + 10;
short dx[] = {-1, 1, 0, 0};
short dy[] = {0, 0, -1, 1};
int n, m, k, c;
int a[NM][NM], dist[NM][NM][5];
pair<int, int> posHome, posSchool;

#define INFO(x) x.row][x.col][x.dir

struct Data {
    short row, col;
    char dir;

    Data(short _row = 0, short _col = 0, char _dir = 0){
        row = _row; col = _col; dir = _dir;
    }
};
Data trace[NM][NM][5];

bool minimize(int &a, int b){
    if(a > b){a = b; return 1;}
    else return 0;
}

int getCost(char x){
    if(x >= '0' && x <= '9') return x - '0';
    if(x >= 'A' && x <= 'Z') return x - 'A' + 10;
    if(x >= 'a' && x <= 'z') return x - 'a' + 36;
    if(x == '#') return 62;
    if(x == '$') return 63;
}

void readfile(){
    freopen("GOTOSCHOOL.INP", "r", stdin);
    freopen("GOTOSCHOOL.OUT", "w", stdout);
    cin >> n >> m >> k;
    cin >> posHome.fi >> posHome.se >> posSchool.fi >> posSchool.se;
    char u[NM];
    for(int i = 1; i <= n; i++){
        cin >> u;
        for(int j = 0; j < m; j++){
            a[i][j + 1] = BIT(getCost(u[j / 6]), j % 6);
        }
    }
    memset(dist, 0x3f, sizeof(dist));
}
bool check(int x, int y){
    return 1 <= x && x <= n && 1 <= y && y <= m && !a[x][y];
}
void xuli(){
    deque<pair<int, Data>> dq;

    for(int i = 0; i < 4; i++){
        Data s(posHome.fi + dx[i], posHome.se + dy[i], i);
        if(!check(s.row, s.col)) continue;
        dist[INFO(s)] = 0;
        dq.push_back(make_pair(dist[INFO(s)], s));
    }

    while(!dq.empty()){
        int cost = dq.front().fi;
        Data u = dq.front().se;
        dq.pop_front();
        if(cost != dist[INFO(u)]) continue;
        for(int i = 0; i < 4; i++){
            Data v(u.row + dx[i], u.col + dy[i], i);
            if(!check(v.row, v.col)) continue;
            if(minimize(dist[INFO(v)], dist[INFO(u)] + (i != u.dir))){
                trace[INFO(v)] = u;
                if(i == u.dir) dq.push_front(make_pair(dist[INFO(v)], v));
                else dq.push_back(make_pair(dist[INFO(v)], v));
            }
        }
    }

    ///Trace:
    int minDist = INF;
    Data last;
    for(int dir = 0; dir < 4; dir++){
        if(minimize(minDist, dist[posSchool.fi][posSchool.se][dir]))
            last = Data(posSchool.fi, posSchool.se, dir);
    }
    if(minDist > k){
        cout << -1;
        return;
    }
    vector<pair<int, int>> traced;

    Data pre = last;
    int cnt = 0;
    while(true){
        if(cnt == minDist) break;
        int dir = pre.dir;
        pre = trace[INFO(pre)];
        if(pre.row == 0 || pre.col == 0) break;
        if(pre.dir != dir){
            traced.push_back(make_pair(pre.row, pre.col));
            cnt++;
        }
    }
    /*
    while(true){
        Data pre = trace[INFO(last)];
        if(pre.row == 0 || pre.col == 0) break;
        if(pre.dir != last.dir) traced.push_back(make_pair(pre.row, pre.col));
        last = pre;
    }*/

    cout << traced.size() << '\n';
    cout << posHome.fi << " " << posHome.se << '\n';
    for(int i = traced.size() - 1; i >= 0; i--)
        cout << traced[i].fi << " " << traced[i].se << '\n';
    cout << posSchool.fi << " " << posSchool.se;
}
int32_t main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
