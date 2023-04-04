#include <bits/stdc++.h>
#define int long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 5e4 + 10;
const int MOD = 1e9 + 19972207;
int n, k, p;
int f[2][205][35], s[NM];
char a[NM];

void add(int &a, int b){
    if(a + b >= MOD) a += b - MOD;
    else a += b;
}
void readfile(){
    freopen("DIGITS.INP", "r", stdin);
    freopen("DIGITS.OUT", "w", stdout);
    cin >> n >> k >> p;
    for(int i = 1; i <= n; i++) cin >> a[i];
}
void xuli(){
    for(int i = 1; i <= n; i++) a[i] -= '0';
    for(int i = 1; i <= n; i++) s[i] = s[i - 1] + (a[i] - 'a');

    f[1][1][a[1] % p] = 1;
    for(int i = 1; i < n; i++){
        for(int j = 1; j <= k; j++){
            for(int r = 0; r < p; r++) if(f[i & 1][j][r] > 0) {
                add(f[i + 1 & 1][j][(10 * r + a[i + 1]) % p], f[i & 1][j][r]);
                if(r == 0 && j < k){
                    add(f[i + 1 & 1][j + 1][a[i + 1] % p], f[i & 1][j][r]);
                }
                f[i & 1][j][r] = 0;
            }
        }
    }
    cout << f[n & 1][k][0];
}
int32_t main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
