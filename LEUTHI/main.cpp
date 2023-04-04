#include <bits/stdc++.h>
#define int long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int MOD = 1e9 + 7;
const int NM = 1e5 + 10;
int n, k;
int f[NM];

void readfile(){
    freopen("INP", "r", stdin);
    freopen("OUT", "w", stdout);
    cin >> n >> k;
}
int chap(int N, int K){
    int s1 = 1, s2 = 1;
    for(int i = 1; i <= N; i++) s1 = (s1 * i) % MOD;
    for(int i = 1; i <= N - K; i++) s2 = (s2 * i) % MOD;
    for(int i = 1; i <= K; i++) s2 = (s2 * i) % MOD;
    s1 = s1 / s2;
    return s1;
}
void xuli(){
    int s1 = chap(n, k);
    f[1] = 0; f[2] = 1;
    for(int i = 3; i <= n; i++) f[i] = (i - 1) * (f[i - 1] + f[i - 2]) % MOD;
    int res = s1 * f[k] % MOD;
    cout << res;
}
int32_t main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
