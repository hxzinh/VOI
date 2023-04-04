#include <bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f3f3f3f
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

const int NM = 1e5 + 10;
int n;
int a[NM], b[NM];

int FindB(int x){
    if(b[1] >= x) return b[1];
    if(b[n] <= x) return b[n];
    int l = 1, r = n;
    while(l <= r){
        int m = (l + r) >> 1;
        if(b[m] == x) return b[m];
        if(b[m] < x) l = m + 1;
        else r = m - 1;
    }

    return (abs(b[l] - x) <= abs(b[r] - x) ? b[l] : b[r]);
}
void xuli(){
    int res = INF;
    sort(b + 1, b + n + 1);

    for(int i = 1; i <= n; i++){
        int x = FindB(-a[i]);
        int val = abs(a[i] + x);
        minimize(res, val);
    }
    cout << res;
}
int32_t main()
{
    FastIO
    freopen("NKSGAME.INP", "r", stdin);
    freopen("NKSGAME.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];

    xuli();
    return 0;
}
