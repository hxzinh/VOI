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

const int NM = 3e3 + 10;
int n, Time;
ii a[NM];
int f[NM][NM];

bool tmp(const ii &A, const ii &B){
    return A.fi < B.fi;
}
void readfile(){
    freopen("INP", "r", stdin);
    freopen("OUT", "w", stdout);
    cin >> n >> Time;
    for(int i = 1; i <= n; i++){
        cin >> a[i].fi >> a[i].se;
    }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= Time; j++) f[i][j] = -INF;
    sort(a + 1, a + n + 1, tmp);
}
int dp(int x, int t){
    if(x > n || t <= 0) return 0;
    int &res = f[x][t];
    if(res != -INF) return res;
    res = max(res, a[x].se + dp(x + 1, t - a[x].fi));
    res = max(res, dp(x + 1, t));
    return res;
}
int xuli(){
    int res = dp(1, Time);
    cout << res;
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
