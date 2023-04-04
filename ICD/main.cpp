#include <bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define popcount(x) __builtin_popcount(x)
#define set(x) setprecision(x)
#define MASK(x) (1LL << (x))
#define BIT(x, i) ((x) >> (i) & 1)
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e6 + 10;
int n, m;
int a[NM];

void xuli(){
    int tmp = 0;
    for(int i = 1; i < n; i++){
        a[i] += tmp;
        tmp += (a[i] / (n - i));
        a[i] = (a[i] % (n - i));
    }
    a[n] += tmp;

    for(int i = 1; i <= n; i++) cout << a[i] << " ";
}
int32_t main()
{
    FastIO
    freopen("ICD.INP", "r", stdin);
    freopen("ICD.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

    xuli();
    return 0;
}
