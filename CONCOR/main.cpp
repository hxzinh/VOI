#include <bits/stdc++.h>
#define ll long long
#define db double
#define INF 1e9
#define pii pair<int, int>
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define popcount(x) __builtin_popcount(x)
#define set(x) setprecision(x)
#define MASK(x) (1LL << (x))
#define BIT(x, i) ((x) >> (i) & 1)
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 2e3 + 10;
int n, m, d;

struct Dot {
    int x, y;
};
Dot b[NM];

struct Point {
    int x, y, range, cost;
};
Point a[NM];

struct Line {
    int A, B, C;
};
Line lines[NM];

Line makeLine(int x, int y, int u, int v){
    Dot vecN = {y - v, u - x};
    return {vecN.x, vecN.y, 0 - vecN.x * u - vecN.y * v};
}
double getDist(int x, int y, Line l){
    return abs(l.A * x + l.B * y + l.C) / sqrt(l.A * l.A + l.B * l.B);
}
Dot getPoint(Dot u, Line l){
    l = {-l.B, l.A, l.C};
    double x =
}
pair<db, db> giaipt(Line A, Line B){
    double x, y, tam;
    tam =
}
bool check(int x, int y, int u, int v, int r, int c){
    if(u > r) swap(u, r);
    if(v > c) swap(v, c);
    return (x >= u && x <= r) || (y >= v && y <= c);
}
void xuli(){
    for(int i = 1; i <= m + 1; i++){
        int x = b[i].x, y = b[i].y, u = b[i - 1].x, v = b[i - 1].y;
        lines[i] = makeLine(x, y, u, v);
    }

    int res = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m + 1; j++){
            double dist = getDist(a[i].x, a[i].y, lines[j]);
            Dot newPoint =
            if(dist <= db(d + a[i].range) && check()){
                res += a[i].cost;
                break;
            }
        }
    }
    cout << res;
}
int main()
{
    FastIO
    freopen("CONCOR.INP", "r", stdin);
    freopen("CONCOR.OUT", "w", stdout);
    cin >> n >> m >> d;
    for(int i = 1; i <= n; i++){
        int x, y, r, w;
        cin >> x >> y >> r >> w;
        a[i] = {x, y, r, w};
    }
    for(int i = 1; i <= m; i++){
        cin >> b[i].x >> b[i].y;
    }

    xuli();
    return 0;
}
