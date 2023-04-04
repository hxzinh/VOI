#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define ALL(v) (v).begin(), (v).end()
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 2e3 + 10;
int n;
int a[NM];
int g[NM][NM];
vector<int> pos[NM][2];

int dp(int x, int y){
    if(x > y || x > n || y < 0) return 0;
    if(x == y) return -INF;
    int &res = g[x][y];
    if(res != -1) return res;
    if(x == y - 1) return (a[x] == a[y]);
    if(a[x] == a[x + 1]) return 1 + dp(x + 2, y);
    if(a[y] == a[y - 1]) return 1 + dp(x, y - 2);
    if(a[x] == a[y]) return 1 + dp(x + 1, y - 1);

    maximize(res, dp(x + 1, y - 1));

    int statx = (x % 2) ^ 1, staty = (y % 2) ^ 1;
    int u = lower_bound(ALL(pos[a[x]][statx]), x) - pos[a[x]][statx].begin();
    int v = lower_bound(ALL(pos[a[x]][statx]), y) - pos[a[x]][statx].begin();
    for(int i = u; i < v; i++){
        int Next = pos[a[x]][statx][i];
        if(Next > y) break;
        maximize(res, 1 + dp(x + 1, Next - 1) + dp(Next + 1, y));
    }

    u = lower_bound(ALL(pos[a[y]][staty]), x) - pos[a[y]][staty].begin();
    v = lower_bound(ALL(pos[a[y]][staty]), y) - pos[a[y]][staty].begin();
    for(int i = u; i < v; i++){
        int Next = pos[a[y]][staty][i];
        if(Next > y) break;
        maximize(res, 1 + dp(x, Next - 1) + dp(Next + 1, y - 1));
    }
    return res;
}
void trace(int x, int y){
    if(x > y) return;
    if(a[x] == a[y]){
        cout << x << " " << y << '\n';
        trace(x + 1, y - 1);
        return;
    }
    if(a[x] == a[x + 1]){
        cout << x << " " << x + 1 << '\n';
        trace(x + 2, y);
        return;
    }
    if(a[y] == a[y - 1]){
        cout << y << " " << y - 1 << '\n';
        trace(x, y - 2);
        return;
    }
    if(x == y - 1){
        cout << x << " " << y << '\n';
        return;
    }

    int tmp = g[x][y];
    int statx = (x % 2) ^ 1, staty = (y % 2) ^ 1;
    int u = lower_bound(ALL(pos[a[x]][statx]), x) - pos[a[x]][statx].begin();
    int v = lower_bound(ALL(pos[a[x]][statx]), y) - pos[a[x]][statx].begin();
    for(int i = u; i < v; i++){
        int Next = pos[a[x]][statx][i];
        if(Next > y) break;
        if(tmp == 1 + dp(x + 1, Next - 1) + dp(Next + 1, y)){
            cout << x << " " << Next << '\n';
            trace(x + 1, Next - 1);
            trace(Next + 1, y);
            return;
        }
    }

    u = lower_bound(ALL(pos[a[y]][staty]), x) - pos[a[y]][staty].begin();
    v = lower_bound(ALL(pos[a[y]][staty]), y) - pos[a[y]][staty].begin();
    for(int i = u; i < v; i++){
        int Next = pos[a[y]][staty][i];
        if(Next > y) break;
        if(tmp == 1 + dp(x, Next - 1) + dp(Next + 1, y - 1)){
            cout << Next << " " << y << '\n';
            trace(x, Next - 1);
            trace(Next + 1, y - 1);
            return;
        }
    }
    cout << x << " " << y << '\n';
    trace(x + 1, y - 1);
    return;
}
void xuli(){
    memset(g, -1, sizeof(g));

    cout << dp(1, n) << '\n';
    trace(1, n);
}
int main() {
    FastIO
    freopen("PARTY.INP", "r", stdin);
    freopen("PARTY.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        pos[a[i]][i % 2].push_back(i);
    }

    xuli();
    return 0;
}
