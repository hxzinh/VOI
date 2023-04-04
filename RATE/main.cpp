#include <bits/stdc++.h>
#define ll long long
#define db double
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

const int NM = 3e5 + 10;
int n, k;
double a[NM], s[NM], b[NM], maxSum[NM];

bool check(double x){
    b[0] = 0;
    pair<db, int> p;
    for(int i = 1; i <= n; i++) {
        b[i] = b[i - 1] + a[i] - x;
        if(maximize(p.fi, b[i])) p.se = i;
    }
    maxSum[n + 1] = -INF;
    for(int i = n; i > 0; i--) maxSum[i] = max(maxSum[i + 1], b[i]);

    double res = -INF;
    for(int i = 1; i <= n - k + 1; i++) {
        maximize(res, maxSum[i + k - 1] - b[i - 1]);
        if(res >= 0) return true;
    }
    return false;
}
void xuli(){
    double L = 0, R = 1e6, Mid, res = 0.00;
    for(int i = 1; i <= 50; i++){
        Mid = (L + R) / 2;
        if(check(Mid)){
            L = Mid;
            maximize(res, Mid);
        }
        else R = Mid;
    }
    cout << fixed << setprecision(6) << res;
}
int32_t main()
{
    FastIO
    freopen("RATE.INP", "r", stdin);
    freopen("RATE.OUT", "w", stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];

    xuli();
    return 0;
}

