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
int a[NM], f[NM];

void readfile(){
    freopen("INP", "r", stdin);
    freopen("OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) f[i] = 1;
}
int dp(int x){
    if(x < 0 || x > n) return 0;
    int &res = f[x];
    if(f[x] != 1) return f[x];
    if(a[x] > a[x + 1]) res = max(res, dp(x + 1) + 1);
    if(a[x] > a[x - 1]) res = max(res, dp(x - 1) + 1);
    return res;
}
void xuli(){
    int res = 0;
    a[0] = INF;
    for(int i = 1; i <= n; i++){
        res += dp(i);
    }
    cout << res;
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
