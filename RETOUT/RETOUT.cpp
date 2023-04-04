#include <bits/stdc++.h>
#define int long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e3 + 10;
const int MOD = 1e9 + 7;
int n, m;
int a[NM];
int f[NM][5005];
bool ok = true;

void add(int &a, int b){
    if(a + b >= MOD) a += b - MOD;
    else a += b;
    return;
}
void readfile(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] != 1) ok = false;
    }
}
int gt(int x){
    int res = 1;
    for(int i = 1; i <= x; i++) res = (res * i) % MOD;
    return res;
}
void sub2(){
    int res = (gt(m - 1) % MOD) / ((gt(m - n) * gt(n - 1)) % MOD);
    cout << res;
}
void sub13(){
    memset(f, 0, sizeof(f));
    f[0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++) if(j >= a[i]){
            add(f[i][j], f[i - 1][j - a[i]]);
            add(f[i][j], f[i][j - a[i]]);
        }
    }
    cout << f[n][m];
}
int32_t main(){
    FastIO
    readfile();
    if(ok) sub2();
    else sub13();
    return 0;
}
