#include <bits/stdc++.h>
#define int long long
#define INF 1e18
#define MASK(x) (1LL << (x))
#define BIT(i, x) ((x) >> (i) & 1)
#define ii pair<int, int>
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e2 + 10;
int n;
int sum = 0, res = INF;
int a[NM];
int f[NM][505][505], g[MASK(20)];
ii val[MASK(20)];

void readfile(){
    freopen("SWEETS.INP", "r", stdin);
    freopen("SWEETS.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) sum += a[i];
}
void backtrack(int x, int s1, int s2){
    if(x > n){
        int s3 = sum - (s1 + s2);
        if(s1 < s2 || s2 < s3 || s1 < s3) return;
        minimize(res, s1 - s3);
        return;
    }
    backtrack(x + 1, s1 + a[x], s2);
    backtrack(x + 1, s1, s2 + a[x]);
    backtrack(x + 1, s1, s2);
    return;
}
void sub12(){
    backtrack(1, 0, 0);
    cout << res;
}
void sub4(){
    memset(f, 0, sizeof(f));
    f[0][0][0] = 1;
    for(int i = 0; i < n; i++){
        for(int u = 0; u <= sum; u++){
            for(int v = 0; v <= sum; v++) if(f[i][u][v]) {
                f[i + 1][u + a[i + 1]][v] = 1;
                f[i + 1][u][v + a[i + 1]] = 1;
                f[i + 1][u][v] = 1;
            }
        }
    }

    for(int u = 0; u <= sum; u++){
        for(int v = 0; v <= sum; v++) if(f[n][u][v]){
            int tmp = sum - (u + v);
            if(u >= v && v >= tmp) minimize(res, u - tmp);
        }
    }
    cout << res;
}
bool cmp(const ii &A, const ii &B){
    return A.fi < B.fi;
}
void sub3(){
    int res = INF;
    for(int mask = 1; mask <= MASK(n) - 1; mask++){
        for(int i = 1; i <= n; i++) if(BIT(i - 1, mask)){
            int newMask = mask | MASK(i - 1);
            g[newMask] = g[mask] + a[i];
        }
    }

    int cnt = 0;
    for(int mask = 1; mask <= MASK(n); mask++)  if(g[mask] <= sum / 2) {
        val[++cnt] = make_pair(g[mask], mask);
    }

    sort(val + 1, val + cnt + 1, cmp);
    for(int i = cnt; i >= 1; i--){
        int l = 1, r = i - 1, pos;
        while(l <= r){
            int m = (l + r) >> 1;
            if(val[m].fi <= val[i].fi){
                pos = m;
                l = m + 1;
            } else r = m - 1;
        }

        int sa = sum - (val[i].fi + val[pos].fi);
        if(sa >= val[i].fi){
            minimize(res, sa - val[pos].fi);
            cout << val[pos].fi << '\n';
        }
    }
    cout << res;
}
int32_t main()
{
    FastIO
    readfile();
    /**
    if(n <= 10) sub12();
    else if(n <= 20) sub3();
    else sub4();
    **/
    sub12();
    cout << '\n';
    sub3();
    return 0;
}
