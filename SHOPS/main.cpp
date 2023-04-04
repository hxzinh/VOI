#include <bits/stdc++.h>
#define int long long
#define INF 1e18
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 5e5 + 10;
int n, k;
int trace = -1;
int a[NM], s[NM], f[NM];

bool check(int x){
    int sum = 0;
    for(int i = x; i <= n; i++){
        if(f[i] - s[i - x] <= k){
            trace = i - x + 1;
            return true;
        }
    }
    return false;
}
void xuli(){
    int l = 1, r = n, res = 0;
    while(l <= r){
        int m = (l + r) >> 1;
        if(check(m)){
            res = m;
            l = m + 1;
        } else r = m - 1;
    }
    cout << res << " " << trace;
}
int32_t main()
{
    FastIO
    freopen("SHOPS.INP", "r", stdin);
    freopen("SHOPS.OUT", "w", stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
    f[n] = s[n];
    for(int i = n - 1; i > 0; i--) f[i] = min(s[i], f[i + 1]);
    xuli();
    return 0;
}
