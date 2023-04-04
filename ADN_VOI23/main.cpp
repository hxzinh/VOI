#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define MAX 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define popcount(x) __builtin_popcount(x)
#define setp(x) setprecision(x)
#define MASK(x) (1LL << (x))
#define BIT(x, i) ((x) >> (i) & 1)
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e6 + 10;
int n;
int result = INF;
string s;
char a[] = {'A', 'G', 'T', 'X'};
int dp[4501][4505][4];
pair<long long, int> f[NM][5];

void backtrack(int x) {
    if(x > n) {
        int ans = 0;
        for(int i = 1; i < n; i++) {
            bool ok = false;
            for(int j = i + 1; j <= n; j++) {
                if(s[i] != s[j]) ok = true;
                if(ok) ans++;
            }
        }
        minimize(result, ans);

        //cout << s << " " << ans << '\n';
        return;
    }

    if(s[x] == '?') {
        for(int i = 0; i < 4; i++) {
            s[x] = a[i];
            backtrack(x + 1);
        }
        s[x] = '?';
    }
    else backtrack(x + 1);
}
void sub1() {
    backtrack(1);
    cout << result;
}
void sub3() {
    memset(dp, INF, sizeof dp);

    if(s[1] == '?') {
        for(int i = 0; i < 4; i++) dp[1][1][i] = 0;
    }
    else {
        for(int i = 0; i < 4; i++) {
            if(s[1] == a[i]) {
                dp[1][1][i] = 0;
                break;
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            for(int u = 0; u < 4; u++) if(dp[i][j][u] < INF) {
                if(s[i + 1] == '?') {
                    for(int v = 0; v < 4; v++) {
                        if(a[u] == a[v]) {
                            minimize(dp[i + 1][j + 1][v],
                                     dp[i][j][u] + i - j);
                        }
                        else {
                            minimize(dp[i + 1][1][v], dp[i][j][u] + i);
                        }
                    }
                }
                else {
                    int num = 1;
                    for(int v = 0; v < 4; v++) {
                        if(a[v] == s[i + 1]) {
                            num = v;
                            break;
                        }
                    }

                    if(s[i + 1] != a[u]) {
                        minimize(dp[i + 1][1][num], dp[i][j][u] + i);
                    }
                    else {
                        minimize(dp[i + 1][j + 1][num],
                                 dp[i][j][u] + i - j);
                    }
                }
            }
        }
    }

    int res = INF;
    for(int i = 0; i < 4; i++)
        for(int j = 1; j <= n; j++) minimize(res, dp[n][j][i]);

    cout << res;
}
void xuli() {
    for(int i = 1; i <= n; i++)
        for(int j = 0; j < 4; j++) f[i][j] = {MAX, MAX};

    if(s[1] == '?') {
        for(int i = 0; i < 4; i++) f[1][i] = {0, 0};
    }
    else {
        for(int i = 0; i < 4; i++) {
            if(s[1] == a[i]) {
                f[1][i] = {0, 0};
                break;
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < 4; j++) if(f[i][j].fi < MAX) {
            if(s[i + 1] == '?') {
                for(int v = 0; v < 4; v++) {
                    if(j == v) {
                        if(f[i + 1][v].fi > f[i][j].fi + f[i][j].se) {
                            f[i + 1][v].fi = f[i][j].fi + f[i][j].se;
                            f[i + 1][v].se = f[i][j].se;
                        }
                        else
                        if(f[i + 1][v].fi == f[i][j].fi + f[i][j].se)
                            minimize(f[i + 1][v].se, f[i][j].se);
                    }
                    else {
                        if(f[i + 1][v].fi > f[i][j].fi + i) {
                            f[i + 1][v].fi = f[i][j].fi + i;
                            f[i + 1][v].se = i;
                        }
                        else
                        if(f[i + 1][v].fi == f[i][j].fi + i)
                            minimize(f[i + 1][v].se, i);
                    }
                }
            }
            else {
                if(s[i + 1] == a[j]) {
                    if(f[i + 1][j].fi > f[i][j].fi + f[i][j].se) {
                        f[i + 1][j].fi = f[i][j].fi + f[i][j].se;
                        f[i + 1][j].se = f[i][j].se;
                    }
                    else
                    if(f[i + 1][j].fi == f[i][j].fi + f[i][j].se)
                        minimize(f[i + 1][j].se, f[i][j].se);
                }
                else {
                    int num = 0;
                    for(int u = 0; u < 4; u++) {
                        if(a[u] == s[i + 1]) {
                            num = u;
                            break;
                        }
                    }

                    if(f[i + 1][num].fi > f[i][j].fi + i) {
                        f[i + 1][num].fi = f[i][j].fi + i;
                        f[i + 1][num].se = i;
                    }
                    else
                    if(f[i + 1][num].fi == f[i][j].fi + i)
                        minimize(f[i + 1][num].se, i);
                }
            }
        }
    }

    ll res = INF;
    for(int i = 0; i < 4; i++) minimize(res, f[n][i].fi);
    cout << res;
}
int32_t main()
{
    FastIO
    freopen("ADN.INP", "r", stdin);
    freopen("ADN.OUT", "w", stdout);
    cin >> s;
    n = s.size();
    s = "#" + s;

    xuli();
    return 0;
}

