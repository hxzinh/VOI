#include <bits/stdc++.h>
#define int long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e5 + 10;

int T, n, p;
int num;

struct Point {
    int x, y;
};
Point a[NM];

struct Line {
    Point A, B;
    int numDot;
};

bool CCW(Point A, Point B, Point C){
    int val = (B.y - A.y) * (C.x - B.x) - (B.x - A.x) * (C.y - B.y);
    return (val == 0);
}
void sub2(){
    int dot = n * p / 100 + (n * p % 100 != 0);
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            int cnt = 0;
            for(int k = 1; k <= n; k++) if(CCW(a[i], a[j], a[k])) cnt++;
            if(cnt >= dot){
                cout << "possible" << '\n';
                return;
            }
        }
    }
    cout << "impossible" << '\n';
    return;
}
vector<Line> dp(int u, int v){
    int k = v - u + 1;
    int dot = k * p / 100 + (k * p % 100 != 0);
    vector<Line> tmp;
    if(k / 2 * p <= 2 * 200){
        for(int i = u; i <= v; i++){
            for(int j = i + 1; j <= v; j++){
                int cnt = 0;
                for(int h = u; h <= v; h++) if(CCW(a[i], a[j], a[h])) cnt++;
                if(cnt >= dot) tmp.push_back({a[i], a[j], cnt});
            }
        }
    } else {
        int m = (u + v) >> 1;
        vector<Line> V(dp(m + 1, v));
        for(Line t : dp(u, m)){
            int cnt = t.numDot;
            for(Line w : V){
                if(CCW(t.A, t.B, w.A) && CCW(t.A, t.B, w.B)) cnt += w.numDot;
            }
            if(cnt >= dot) tmp.push_back({t.A, t.B, cnt});
        }
    }
    return tmp;
}
void full(){
    if(dp(1, n).size()) cout << "possible" << '\n';
    else cout << "impossible" << '\n';

    //cout << dp(1, n).size();
}
int32_t main()
{
    FastIO
    cin >> T;

    while(T--){
        cin >> n >> p;
        for(int i = 1; i <= n; i++) cin >> a[i].x >> a[i].y;
        num = n * p / 100 + (n * p % 100 != 0);
	sub2();
    }
    return 0;
}
