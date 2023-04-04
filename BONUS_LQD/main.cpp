#include <bits/stdc++.h>
#define int long long
#define INF 1e18
#define ii pair<int, int>
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

using namespace std;
const int NM = 5e3 + 10;
int n, m;
int maxLength;
int a[NM][NM], s[NM][NM], pre[NM][NM];
struct Data {
    int sum, preLength, pos, cnt;
};
///---------------------------full------------------------------
int f[NM][NM], g[NM][NM];
vector<ii> dis;

struct Distances{
    int x, y, dis;

    bool inline operator < (const Distances &A) const {
        return dis < A.dis;
    }
};
Distances d[NM];




void readfile(){
    freopen("BONUS.INP", "r", stdin);
    freopen("BONUS.OUT", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) cin >> a[i][j];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) s[i][j] = a[i][j];
}
void sub3(){
    queue<Data> q;
    maxLength = m - 1;
    for(int i = 1; i <= m; i++){
        q.push({a[1][i], 0, i, 1});
    }

    int res = -INF;
    while(!q.empty()){
        int sum = q.front().sum;
        int preL = q.front().preLength;
        int preI = q.front().pos;
        int cnt = q.front().cnt;
        q.pop();
        if(cnt >= 3) res = max(res, abs(sum));
        for(int newPos = preI + preL + 1; newPos <= m; newPos++){
            q.push({sum + a[1][newPos], newPos - preI, newPos, cnt + 1});
        }
        for(int newPos = preI - preL - 1; newPos > 0; newPos--){
            q.push({sum + a[1][newPos], preI - newPos, newPos, cnt + 1});
        }
    }
    cout << res;
}
int pw(int x){
    return x * x;
}
bool cmp(ii x, ii y){
    return x.fi * x.fi + x.se * x.se < y.fi * y.fi + y.se * y.se;
}
int getRes(){
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) f[i][j] = g[i][j] = a[i][j];

    for(int k = 0; k < dis.size(); k++){
        int u = dis[k].fi;
        int v = dis[k].se;
        if(!u && !v) continue;
        for(int i = max(1LL, 1 - u); i <= min(n, n - u); i++)
            for(int j = max(1LL, 1 - v); j <= min(m, m - v); j++)
                maximize(g[i][j], f[i + u][j + v] + a[i][j]);
        if(k == dis.size() - 1 || (k < dis.size() && cmp(dis[k], dis[k + 1]))){
            for(int i = 1; i <= n; i++)
                for(int j = 1; j <= m; j++) f[i][j] = g[i][j];
        }
    }

    int res = -INF;
    int sum = 0, cnt = 0;
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++) if(a[i][j] > 0){
        cnt++;
        sum += a[i][j];
    }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) if(cnt > 2 || f[i][j] != sum) maximize(res, f[i][j]);
    return res;
}
void full(){
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            dis.push_back(make_pair(i - 1, j - 1));
            dis.push_back(make_pair(1 - i, j - 1));
            dis.push_back(make_pair(i - 1, 1 - j));
            dis.push_back(make_pair(1 - i, 1 - j));
        }
    sort(ALL(dis), cmp);

    int res = getRes();
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) a[i][j] = -a[i][j];
    maximize(res, getRes());
    cout << res;
}
int32_t main()
{
    FastIO
    readfile();
    full();
    return 0;
}
