#include <bits/stdc++.h>
#define int long long
#define INF 1e9
#define pii pair<int, int>
#define fi first
#define se second
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e3 + 10;
int n, d;
pii a[100005];
int cnt[NM][NM];

void xuli(){
    vector<int> dx(d, 0), dy(d, 0);
    for(int i = 1; i <= n; i++){
        int x = (a[i].fi % d + d) % d;
        int y = (a[i].se % d + d) % d;
        dx[x]++; dy[y]++;
        cnt[x][y]++;
    }

    int res = n;
    for(int i = 0; i < d; i++)
        for(int j = 0; j < d; j++) minimize(res, dx[i] + dy[j] - cnt[i][j]);
    cout << res;
}
void readfile(){
    freopen("SOCIAL-DISTANCING.INP", "r", stdin);
    freopen("SOCIAL-DISTANCING.OUT", "w", stdout);
    cin >> d >> n;
    for(int i = 1; i <= n; i++) cin >> a[i].fi >> a[i].se;
}
int32_t main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
