#include <bits/stdc++.h>
#define int long long
#define INF 1e9
#define MASK(x) (1LL << (x))
#define BIT(x, i) ((x) >> (i) & 1)
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 50;
int n;
int a[NM][NM], f[NM][100005];

void readfile(){
    freopen("DELIVER.INP", "r", stdin);
    freopen("DELIVER.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) cin >> a[i][j];
}
void xuli(){
    for(int i = 1; i <= n; i++)
        for(int mask = 0; mask <= MASK(n); mask++) f[i][mask] = INF;
    for(int i = 1; i <= n; i++) f[i][MASK(i - 1)] = 0;

    for(int mask = 1; mask <= MASK(n); mask++){
        for(int i = 1; i <= n; i++) if(f[i][mask] < INF) {
            for(int j = 1; j <= n; j++) if(!BIT(mask, j - 1)) {
                int newMask = mask | MASK(j - 1);
                minimize(f[j][newMask], f[i][mask] + a[i][j]);
            }
        }
    }

    int res = INF;
    for(int i = 1; i <= n; i++) minimize(res, f[i][MASK(n) - 1]);
    cout << res;
}
int32_t main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
