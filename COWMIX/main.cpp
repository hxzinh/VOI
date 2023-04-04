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

int n, k;
int a[20];
int f[20][MASK(16)];

void readfile(){
    freopen("COWMIX.INP", "r", stdin);
    freopen("COWMIX.OUT", "w", stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
}
void xuli(){
    for(int i = 1; i <= n; i++) f[i][MASK(i - 1)] = 1;

    for(int mask = 0; mask <= MASK(n); mask++){
        for(int i = 1; i <= n; i++) if(f[i][mask]) {
            for(int j = 1; j <= n; j++) if(!BIT(mask, j - 1)) {
                int newMask = mask | MASK(j - 1);
                if(abs(a[i] - a[j]) > k) f[j][newMask] += f[i][mask];
            }
        }
    }
    int res = 0;
    for(int i = 1; i <= n; i++) res += f[i][MASK(n) - 1];
    cout << res;
}
int32_t main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
