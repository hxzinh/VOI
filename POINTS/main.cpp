#include <bits/stdc++.h>
#define ll long long
#define oo 4e18
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define SQR(x) (1LL * (x) * (x))

using namespace std;
const int NM = 5e5+10;
int numPoint;
int ans = oo;
int minyLeft[NM], maxyLeft[NM], minyRight[NM], maxyRight[NM];

struct Point
{
    int x,y;

    Point(int _x = 0, int _y = 0){
        x = _x; y = _y;
    }

    bool operator < (const Point &A){
        return x < A.x || (x == A.x && y < A.y);
    }
};
Point points[NM];

void readfile(){
    freopen("points.inp","r",stdin);
    freopen("points.out","w",stdout);
    cin >> numPoint;
    for(int i = 1; i <= numPoint; i++){
        cin >> points[i].x >> points[i].y;
    }

    sort(points + 1, points + numPoint + 1);
    minyLeft[0] = oo;
    maxyLeft[0] = -oo;
    minyRight[numPoint + 1] = oo;
    maxyRight[numPoint + 1] = -oo;
    for(int i = 1; i <= numPoint; i++){
        minyLeft[i] = min(minyLeft[i-1], points[i].y);
        maxyLeft[i] = max(maxyLeft[i-1], points[i].y);
    }
    for(int i = numPoint; i >= 1; i--){
        minyRight[i] = min(minyRight[i+1], points[i].y);
        maxyRight[i] = max(maxyRight[i+1], points[i].y);
    }
}
int floorsqrt(ll x){
    ll tmp = sqrt(x);
    for(int i = 7; i >= -7; i--){
        if(tmp + i >= 0 && SQR(tmp + i) <= x) return tmp + i;
    }
}
bool check(int from,int to,ll res){
    int minX = points[from].x, maxX = points[to].x;
    int minY = min(minyLeft[from - 1], minyRight[to + 1]);
    int maxY = max(maxyLeft[from - 1], maxyRight[to + 1]);
    if(maxY < minY) return true;
    if(SQR(maxY - minY) > res) return false;
    ///
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            if(SQR(i ? minX : maxX) + SQR(j ? minY : maxY) > res) return false;
        }
    }
    return true;
}
bool ok(ll res){
    if(SQR(points[numPoint].x - points[1].x) <= res) return true;
    if(SQR(maxyLeft[numPoint] - minyLeft[numPoint]) <= res) return true;

    ll tam = floorsqrt(res);
    int head = 1;
    int last = numPoint;
    for(int i = numPoint; i >= 1; i--){
        if(points[i].x < 0) break;
        int x = points[i].x;
        while(head <= numPoint && points[head].x < -x) head++;
        while(last > 1 && points[last - 1].x >= x - tam) last--;
        int from = max(head, last), to = i;
        if(check(from, to, res)) return true;
    }
    last = numPoint;
    head = 1;
    for(int i = 1; i <= numPoint; i++){
        if(points[i].x > 0) break;
        int x = points[i].x;
        while(last >= 1 && points[last].x > -x) last--;
        while(head < numPoint && points[head + 1].x <= x + tam) head++;
        int from = i, to = min(head, last);
        if(check(from, to, res)) return true;
    }
    return false;
}
void xuli(){
    long long res;
    long long d = 0, c = oo, g;
    while(d <= c){
        g = (d + c) >> 1;
        if(ok(g)){
            c = g - 1;
            res = g;
        }else d = g + 1;
    }
    cout << res;
}
int32_t main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
