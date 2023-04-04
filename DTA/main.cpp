#include <bits/stdc++.h>
#define ll long long
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

const int NM = 1e5 + 10;
int n;
int a[3][NM], f[3][NM], dp[3][NM], s[3][NM];


void sub1(){
    for(int i = 1; i <= n; i++){
        s[1][i] = s[1][i - 1] + a[1][i];
        s[2][i] = s[2][i - 1] + a[2][i];
    }

    for(int i = 1; i <= n; i++){
        maximize(f[1][i], f[1][i - 1]);
        maximize(f[2][i], f[2][i - 1]);
        for(int j = 1; j <= i; j++){
            if(s[1][i] - s[1][j - 1] == 0) maximize()
        }
    }
}
int main()
{
    FastIO
    freopen("DTA.INP", "r", stdin);
    freopen("DTA.OUT", "w", stdout);
    cin >> n;
    for(int t = 1; t <= 2; t++)
        for(int i = 1; i <= n; i++) cin >> a[t][i];
    return 0;
}
