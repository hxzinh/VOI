#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define pii pair<int, int>
#define fi first
#define se second
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 5e3 + 10;
int T, n, m, p, q;
bool cx[NM][NM], ok[NM][NM];

struct Point {
    int x, y;

    Point(int _x = 0, int _y = 0){
        x = _x; y = _y;
    }
};
Point a[NM], b[NM];
pair<Point, Point> SegA[NM], SegB[NM];

struct Vec {
    int x, y;

    Vec(int _x = 0, int _y = 0){
        x = _x, y = _y;
    }

    int dot(const Vec &other){
        return x * other.x + y * other.y;
    }

    double dist() const {
        return sqrt(x * x + y * y);
    }
};

Point operator - (const Point &B, const Point &A) {
    return Point(B.x - A.x, B.y - A.y);
}

bool operator == (const Point &A, const Point &B) {
    return (A.x == B.x) && (A.y == B.y);
}

int sign(int x){
    if(x > INF) return 1;
    if(x < -INF) return -1;
    return 0;
}

double cross(Point AB, Point AC){
    return AB.x * AC.y - AC.x * AB.y;
}
double dot(Point AB, Point AC) {
    return AB.x * AC.x + AB.y * AC.y;
}
bool intersect(Point A, Point B, Point C, Point D) {
    int ABxAC = sign(cross(B - A, C - A));
    int ABxAD = sign(cross(B - A, D - A));
    int CDxCA = sign(cross(D - C, A - C));
    int CDxCB = sign(cross(D - C, B - C));
    if (ABxAC == 0 || ABxAD == 0 || CDxCA == 0 || CDxCB == 0) {
        if (ABxAC == 0 && sign(dot(A - C, B - C)) <= 0) return true;
        if (ABxAD == 0 && sign(dot(A - D, B - D)) <= 0) return true;
        if (CDxCA == 0 && sign(dot(C - A, D - A)) <= 0) return true;
        if (CDxCB == 0 && sign(dot(C - B, D - B)) <= 0) return true;
        return false;
    }
    return (ABxAC * ABxAD < 0 && CDxCA * CDxCB < 0);
}

void xuli(){
    pii res;
    memset(cx, true, sizeof cx);
    memset(ok, true, sizeof ok);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= p; j++){
            for(int k = 1; k <= m; k++){
                if((a[i] == SegA[k].fi) || (a[i] == SegA[k].se)) continue;
                if(!intersect(a[i], b[j], SegA[k].fi, SegA[k].se))
                    cx[i][j] = false;
            }

            for(int k = 1; k <= q; k++){
                if((b[j] == SegB[k].fi) || (b[j] == SegB[k].se)) continue;
                if(!intersect(a[i], b[j], SegB[k].fi, SegB[k].se))
                    ok[i][j] = false;
            }
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= q; j++) if(ok[i][j] && cx[i][j]){
            cout << i << " " << j;
            return;
        }
    }
}
void Read(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i].x >> a[i].y;
    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        SegA[i] = {a[u], a[v]};
    }

    cin >> p >> q;
    for(int i = 1; i <= p; i++) cin >> b[i].x >> b[i].y;
    for(int i = 1; i <= q; i++){
        int u, v;
        cin >> u >> v;
        SegB[i] = {b[u], b[v]};
    }
}
int main()
{
    FastIO
    freopen("FREEWAY.INP", "r", stdin);
    freopen("FREEWAY.OUT", "w", stdout);
    cin >> T;
    while(T--){
        Read();
        xuli();
    }
    return 0;
}
