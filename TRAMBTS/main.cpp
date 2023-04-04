#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e5 + 10;
int n;
int minn = INF, maxx = -INF;

struct ToaDo {
    double x, y;
};
ToaDo a[NM];

void readfile(){
    freopen("BTS.INP", "r", stdin);
    freopen("BTS.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i].x >> a[i].y;
        minimize(minn, a[i].x);
        maximize(maxx, a[i].x);
    }
}
double getDist(double x, double y, double u, double v){
    return sqrt((u - x) * (u - x) + (v - y) * (v - y));
}
bool check(int x){

}
void xuli(){
    double l = -INF, r = INF;
    double res = INF;
    ToaDo u, v;
    u.x = u.y = v.x = v.y = 0;
    for(int i = 1; i <= 100; i++){
        double d1 = 0, d2 = 0;
        u.x = l + (r - l) / 3;
        v.x = r - (r - l) / 3;
        for(int j = 1; j <= n; j++){
            d1 = max(d1, getDist(u.x, u.y, a[j].x, a[j].y));
            d2 = max(d2, getDist(v.x, v.y, a[j].x, a[j].y));
        }
        if(d1 <= d2) r = v.x;
        else {
            res = min(d1, d2);
            l = u.x;
        }
    }
    cout << fixed << setprecision(2) << res;
}
int32_t main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
