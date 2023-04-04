#include <bits/stdc++.h>
#define int long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int MOD = 111539768;
const int NM = 1e3 + 10;
int n, m, k, u, v, r, c;
int a[NM][NM], p[1000005];

void add(int &a, int b){
    if(a + b >= MOD) a += b - MOD;
    else a += b;
}
void sub1(){
    int cnt = 0;
    p[1] = 1; a[1][1] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(p[++cnt] != 0) continue;
            p[cnt] = p[cnt - 1] * k % MOD;
            a[i][j] = p[cnt];
        }
    }

    int res = 0;
    for(int i = r; i <= u; i++)
        for(int j = c; j <= v; j++) add(res, a[i][j]);

    cout << res;
}
int32_t main()
{
    FastIO
    freopen("BONUS.INP", "r", stdin);
    freopen("BONUS.OUT", "w", stdout);
    cin >> n >> m >> k >> r >> c >> u >> v;

    sub1();
    return 0;
}
