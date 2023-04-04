#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 2505;
int n;
int a[NM], f[NM][NM];

int dp(int x, int p) {
    if(x == n) return 1;
    if(x > n) return 0;
    int &res = f[x][p];
    if(res < INF) return res;

    minimize(res, 1 + dp(x + 1, p + 1));
    if(abs(a[x + 1] - a[x]) <= 1) minimize(res, 1 + dp(x + 2, p + 1));
    return res;
}
void xuli() {
    sort(a + 1, a + n + 1);

    for(int i = 1; i <= n; i++)
        for(int j = 0; j <= n; j++) f[i][j] = INF;

    cout << dp(1, 0);
}
int main()
{
    FastIO
    freopen("BUBBLETEA.INP", "r", stdin);
    freopen("BUBBLETEA.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

    xuli();
    return 0;
}
