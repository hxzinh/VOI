#include <bits/stdc++.h>
#define int long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 2e4 + 10;
int n;
int f[NM], dem[NM], g[NM];
bool matrix[3005][3005];

struct Data {
    int a, b, c, s;
};
Data ds[NM];

struct Point {
    int x, y;
    int index;
};
Point a[NM], b[NM];

struct LineSegment {
    Point P1, P2;
};

double getDist(Point P1, Point P2){
    return sqrt((P1.x - P2.x) * (P1.x - P2.x) + (P1.y - P2.y) * (P1.y - P2.y));
}
int CCW(Point p, Point q, Point r){
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if(val == 0) return 0;       /// 3 diem thang hang
    return (val > 0) ? 1 : 2;    /// > 0 : nguoc chieu kim dong ho  || < 0 : cung chieu kim dong ho
}
bool LowerAngle(Point P1, Point P2, Point P3){
    int tmp = CCW(P3, P1, P2);
    if(tmp > 0) return false;
    else if(tmp == 0 && (P1.x < P2.x || (P1.x == P2.x && P1.y < P2.y))) return true;
    return false;
}
int Area(Point A, Point B, Point C){
    int res = (A.x - B.x) * (A.y + B.y) + (B.x - C.x) * (B.y + C.y) + (C.x - A.x) * (C.y + A.y);
    return abs(res);
}
void sort3(int u, int v, int k){
    if(u > v) swap(u, v);
    if(u > k) swap(u, k);
    if(v > k) swap(v, k);
}

void readfile(){
    freopen("INP", "r", stdin);
    freopen("OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i].x >> a[i].y;
        a[i].index = i;
    }
    for(int i = 1; i <= n - 3; i++){
        cin >> b[i].x >> b[i].y;
        if(b[i].x > b[i].y) swap(b[i].x, b[i].y);
        b[i].index = i;
    }
}
void progress(){
    memset(matrix, false, sizeof(matrix));
    for(int i = 1; i < n; i++){
        matrix[i][i + 1] = true;
        matrix[i + 1][i] = true;
    }
    matrix[1][n] = true;
    matrix[n][1] = true;
    for(int i = 1; i <= n - 3; i++){
        Point u = b[i];
        matrix[u.x][u.y] = matrix[u.y][u.x] = true;
    }
}
void sub1(){
    progress();
    int cnt = 0;
    for(int i = 1; i < n; i++){
        int v = i + 1;
        if(v > n) v -= n;
        for(int j = v + 1; j <= n; j++) if(matrix[i][j] && matrix[j][v]) {
            f[++cnt] = Area(a[i], a[v], a[j]);
        }
    }
    g[1] = f[1];
    g[2] = max(g[1], f[2]);
    for(int i = 3; i <= cnt; i++) g[i] = max(g[i - 2] + f[i], g[i - 1]);
    if(g[cnt] % 2 == 0) cout << g[cnt] / 2;
    else cout << g[cnt] / 2 << ".5";
}
void sub2(int start){
    int cnt = 0;
    int u = start, v;
    for(int i = 1; i <= n - 2; i++){
        cnt++;
        u++;
        if(u > n) u -= n;
        v = u + 1;
        if(v > n) v -= n;
        ds[cnt].a = start;
        ds[cnt].b = u;
        ds[cnt].c = v;
        ds[cnt].s = Area(a[start], a[u], a[v]);
    }
    f[1] = ds[1].s;
    f[2] = max(f[1], ds[2].s);
    for(int i = 1; i <= n - 2; i++) f[i] = max(ds[i].s + f[i - 2], f[i - 1]);
    cout << (f[n - 2] / 2);
    if(f[n - 2] % 2 != 0) cout << ".5";
}
void sub3(){
    progress();
    int cnt = 0;
    int u, v, id, t, u2, v2, t2;
    for(int i = 1; i <= n - 3; i++){
        u = b[i].x, v = b[i].y;
        int tg[2], nt = 0;
        for(int t = 1; t <= n; t++) if(matrix[u][t] && matrix[t][v]) {
            u2 = u; v2 = v; t2 = t;
            sort3(u2, v2, t2);
            int id = CCW(a[u2], a[v2], a[t2]);
            if(id) tg[nt] = id, nt++;
        }
    }
}
int32_t main()
{
    FastIO
    readfile();
    for(int i = 1; i <= n - 3; i++){
        int u = b[i].x, v = b[i].y;
        dem[u]++;
        dem[v]++;
    }
    bool cx = false;
    int start;
    for(int i = 1; i <= n; i++){
        if(dem[i] == n - 3){
            cx = true;
            start = i;
            break;
        }
    }
    if(cx) sub2(start);
    else sub1();
    return 0;
}
