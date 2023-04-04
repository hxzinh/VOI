#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 2e3 + 10;
int n;
string a;
int f[NM][NM];

void readfile(){
    freopen("DPPALIN.INP", "r", stdin);
    freopen("DPPALIN.OUT", "w", stdout);
    cin >> a;
    n = a.length();
    a = ' ' + a;
}
int dp(int x, int y){
    if(x > y) return 0;
    int &res = f[x][y];
    if(res > -1) return res;
    if(x == y) return res = 1;
    if(a[x] == a[y]) maximize(res, 2 + dp(x + 1, y - 1));
    maximize(res, dp(x + 1, y));
    maximize(res, dp(x, y - 1));
    return res;
}
void xuli(){
    memset(f, -1, sizeof(f));
    cout << dp(1, n);
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
