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

const int NM = 55;
int n;
int a[NM];

int Gett(int x){
    if(x / 10 == 9) return 9 - (x % 10);
    if(x < 10) return 9 - x;
    if(x < 100) return (9 - x / 10) * 10;
}
void xuli(){
    int sum = 0, res = -1;
    for(int i = 1; i <= n; i++) sum += a[i];

    for(int i = 1; i <= n; i++) maximize(res, sum + Gett(a[i]));
    cout << res;
}
int32_t main()
{
    FastIO
    freopen("MODIFY.INP", "r", stdin);
    freopen("MODIFY.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

    xuli();
    return 0;
}
