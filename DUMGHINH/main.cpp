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
int n;

struct Data {
    int Ax, Ay, Bx, By, Cx, Cy, Dx, Dy;
};
Data a[NM];

void readfile(){
    freopen("DIMGHINH.INP", "r", stdin);
    freopen("DIMGHINH.OUT", "w", stdout);
    cin >> n;
}
int cntOdd(int l, int r){
    if(l % 2 == 0) l++;
    if(r % 2 == 0) r--;
    if(l > r) return 0;
    return (r - l) / 2 + 1;
}
int cntEven(int l, int r){
    if(l > r) return 0;
    return r - l + 1 - cntOdd(l, r);
}
void xuli(){
    int maxC1 = -INF, maxD1 = -INF;
    int minC2 = INF, minD2 = INF;

    for(int i = 0; i < n; i++){
        int c1 = INF, c2 = -INF, d1 = INF, d2 = -INF;
        for(int j = 0; j < 4; j++){
            int x, y; cin >> x >> y;
            minimize(c1, x + y);
            maximize(c2, x + y);
            minimize(d1, x - y);
            maximize(d2, x - y);
        }
        maximize(maxC1, c1);
        minimize(minC2, c2);
        maximize(maxD1, d1);
        minimize(minD2, d2);
    }
    int res = cntEven(maxC1 + 1, minC2 - 1) * cntEven(maxD1 + 1, minD2 - 1) + cntOdd(maxC1 + 1,  minC2 - 1) * cntOdd(maxD1 + 1, minD2 - 1);
    cout << res;
}
int32_t main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
