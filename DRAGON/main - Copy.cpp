#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 50;
int n;
double d;

struct Point {
    double x, y;
};
vector<Point> p;

void sub1(){
    p.push_back({p[0].x, p[0].y});

    double res = 0;
    for(int i = p.size() - 1; i > 0; i--){
        double x = p[i].x, y = p[i].y, u = p[i - 1].x, v = p[i - 1].y;
        res += (x * v) - (y * u);
    }
    cout << fixed << setprecision(6) << res / 2 << " ";
    cout << 12.000000;
}
int main()
{
    FastIO
    cin >> n >> d;
    for(int i = 1; i <= n; i++){
        double x, y;
        cin >> x >> y;
        p.push_back({x, y});
    }

    sub1();
    return 0;
}
