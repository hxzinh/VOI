#include <bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f3f3f
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
int f[NM], g[NM];
vector<int> a, b;

int solve(int x, int n, int h[], vector<int> a) {
    return h[x] + (a[n - 1] * (n - x) - h[n] + h[x]);
}
int getMin(int l, int r, int h[], vector<int> a) {
    if (l > r) return 0;
    int x = r + 1;
    int u1 = solve(0, x, h, a), u2 = solve(1, x, h, a), u3 = solve(2, x, h, a);
    if(u1 < u2 && u2 < u3) return u2;

    int res = INF;
	while (l <= r) {
        int mid = (l + r) >> 1;
        int u = solve(mid - 1, x, f, a), v = solve(mid, x, f, a), k = solve(mid + 1, x, f, a);
        if (v <= u && v <= k) return v;
        else if (u <= v && v <= k) r = mid - 1;
             else l = mid + 1;

        if(v <= u && v <= k) res = v;
        if(u <= v && v <= k) r = mid - 1;
        else l = mid + 1;
    }
	return res;
}

void xuli() {
    int res = INF;
    for(int i = 1; i <= a.size(); i++) {
        int ans = f[a.size()] - f[i - 1] - a[i - 1] * (a.size() - i + 1);
        int tmp = getMin(1, i - 1, f, a);
        minimize(res, tmp + ans + g[b.size()]);
    }

    for(int i = 1; i <= b.size(); i++) {
        int ans = g[b.size()] - g[i - 1] - b[i - 1] * (b.size() - i + 1);
        int tmp = getMin(1, i - 1, g, b);
        minimize(res, tmp + ans + f[a.size()]);
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
    sort(ALL(a)); sort(ALL(b));
    for(int i = 1; i <= a.size(); i++) f[i] = f[i - 1] + a[i - 1];
    for(int i = 1; i <= b.size(); i++) g[i] = g[i - 1] + b[i - 1];


    xuli();
    return 0;
}
