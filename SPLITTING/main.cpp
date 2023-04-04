#include <bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
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
int n, k;
int sum = 0;
int a[NM], s[NM];
bool cx[NM];

bool check(int x){
    int cnt = 1;
    memset(s, 0, (k + 1) * sizeof(int));
    for(int i = 1; i <= n; i++){
        if(a[i] > x) return false;
        if(s[cnt] + a[i] <= x) s[cnt] += a[i];
        else s[++cnt] += a[i];
    }
    return (cnt <= k);
}
void xuli(){
    int l = 1, r = sum, res = INF;
    while(l <= r){
        int m = (l + r) >> 1;
        if(check(m)){
            res = m;
            r = m - 1;
        } else l = m + 1;
    }
    cout << res;
}
int32_t main()
{
    FastIO
    freopen("SPLITTING.INP", "r", stdin);
    freopen("SPLITTING.OUT", "w", stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        sum += a[i];
    }

    xuli();
    return 0;
}
