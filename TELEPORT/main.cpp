#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f3f3f3f
#define ALL(v) (v).begin(), (v).end()
#define pii pair<int, int>
#define fi first
#define se second
#define MASK(x) (1LL << (x))
#define BIT(i, x) ((x) >> (i) & 1)
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e5 + 10;
int n;
ll f[NM], g[NM], p[NM];
vector<ll> a, b;


void xuli() {

    ll res = INF;
    int sz = a.size() - 1;
    for(int i = 1; i <= sz; i++) {
        int l = 1, r = i - 1, ans = i;
        while(l <= r) {
            int m = (l + r) >> 1;
            if(a[i] - a[m] <= a[m]) {
                ans = m;
                r = m - 1;
            } else l = m + 1;
        }

        ll result = g[b.size() - 1];
        result += (f[sz] - f[i - 1]) - a[i] * (sz - i + 1);
        result += a[i] * (i - ans) - (f[i - 1] - f[ans - 1]);
        result += f[ans - 1];
        minimize(res, result);
    }

    sz = b.size() - 1;
    for(int i = 1; i <= sz; i++) {
        int l = 1, r = i - 1, ans = i;
        int aDist = f[a.size() - 1];
        while(l <= r) {
            int m = (l + r) >> 1;
            if(b[i] - b[m] <= b[m]) {
                ans = m;
                r = m - 1;
            } else l = m + 1;
        }
        ll result = f[a.size() - 1];
        result += (g[sz] - g[i - 1]) - b[i] * (sz - i + 1);
        result += b[i] * (i - ans) - (g[i - 1] - g[ans - 1]);
        result += g[ans - 1];
        minimize(res, result);
    }

    cout << res;
}
int32_t main()
{
    FastIO
    freopen("TELEPORT.INP", "r", stdin);
    freopen("TELEPORT.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int u; cin >> u;
        if(u < 0) a.push_back(-u);
        else if (u > 0) b.push_back(u);
    }

    a.push_back(-INF); b.push_back(-INF);
    sort(ALL(a)); sort(ALL(b));
    for(int i = 1; i < a.size(); i++) f[i] = f[i - 1] + a[i];
    for(int i = 1; i < b.size(); i++) g[i] = g[i - 1] + b[i];


    xuli();
    return 0;
}
