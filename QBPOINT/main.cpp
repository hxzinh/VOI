#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define ii pair<int, int>
#define fi first
#define se second
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

int n;

struct Point {
    int x, y;
    int index;
};
Point a[NM], b[NM];

struct LineSegment {
    P1, P2: Point;
};

double getDist(Point P1, Point P2){
    return sqrt((P1.x - P2.x) * (P1.x - P2.x) + (P1.y - P2.y) * (P1.y - P2.y));
}
int CCW(Point p, Point q, Point r){
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if(val == 0) return 0;       /// 3 diem thang hang
    return (val > 0) ? 1 : 2;    /// > 0 : nguoc chieu kim dong ho  || < 0 : cung chieu kim dong ho
}
int getArea(Point p[n]){
    int res = 0;
    p[n] = p[0];
    for(int i = 0; i <= n; i++){
        s += (p[i].x * p[x + 1].y - p[i].y * p[i + 1].x);
    }
    return abs(res / 2);
}
bool LowerAngle()Point P1, Point P2, Point P3){
    int tmp = CCW(P3, P1, P2);
    if(tmp > 0) return false;
    else if(tmp == 0 && (P1.x < P2.x || (P1.x == P2.x && P1.y < P2.y))) return true;
    return false;
}

void readfile(){
    freopen("INP", "r", stdin);
    freopen("OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i].x >> a[i].y;
        a[i].index = i;
    }
}
bool cmp(Point A, Point B){
    return (CCW(a[1], A, B) > 0);
}
void Graham(int i, int c){
    c = 1;
    for(int i = 2; i <= n; i++){
        if(a[i].y < a[c].y || (a[i].y == a[c].y && a[i].x < a[c].x)) c = i;
    }
    swap(a[c], a[1]);
    sort(a + 2, a + n + 1, cmp);
    a[n + 1] = a[1];
    int m = 2;
    b[1] = a[1]; b[2] = a[2];
    for(int i = 3; i <= n; i++){
        while(m > 1 && CCW(b[m - 1], b[m], a[i]) == 1)
    }
}
int main()
{
    FastIO
    cout << "Hello world!" << endl;
    return 0;
}
