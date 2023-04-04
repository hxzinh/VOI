#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define fi first
#define se second
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 4e4 + 10;
int n, m;
int ans = INF, cnt = 0;
int a[NM], pw[NM], f[NM][205];
pii g[NM];

int dp(int x, set<int> S){
    if(x > n) return pw[S.size()];
    if(S.size() > sqrt(m)) return INF;
    int &res = f[x][S.size()];
    if(res < INF) return res;
    S.insert(a[x]);
    if(S.size() <= sqrt(m)) minimize(res, dp(x + 1, S));

    int cost = pw[S.size()];
    S.clear();
    minimize(res, cost + dp(x + 1, S));
    return res;
}
void xuli(){
    memset(f, INF, sizeof f);
    for(int i = 1; i <= m; i++) pw[i] = i * i;
    set<int> S;
    cout << dp(1, S);
}
int32_t main()
{
    FastIO
    freopen("CTNCLN.INP", "r", stdin);
    freopen("CTNCLN.OUT", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];

    xuli();
    return 0;
}
