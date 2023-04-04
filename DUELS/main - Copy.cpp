#include <bits/stdc++.h>
#define int long long
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
const int MOD = 1e9 + 7;
int n, m, T;
int a[NM], b[NM];
int frac[NM], finv[NM];

map<int, int> cntNum;

int pw(int x, int t){
    if(t == 0) return 1;
    if(t == 1) return x;
    int w = pw(x, t >> 1);
    if(t % 2 == 0) return (1LL * w * w) % MOD;
    else return (1LL * w * w % MOD) * 1LL * x % MOD;
}
void add(int &a, int b){
    if(a + b >= MOD) a += b - MOD;
    else a += b;
}
int comb(int k, int n) {
	return k > n ? 0 : (1LL * frac[n] * finv[k] % MOD) * finv[n - k] % MOD;
}
void Minimal(int &u, int &v){
    while(__gcd(u, v) > 1){
        int k = __gcd(u, v);
        if(k == 1) break;
        u /= k;
        v /= k;
    }
}
void xuli(){
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);

    int cnt = 0;
    for(int i = 1; i <= n; i++){
        int l = 1, r = m, pos = -1;
        while(l <= r){
            int m = (l + r) >> 1;
            if(b[m] < a[i]){
                pos = m;
                l = m + 1;
            } else r = m - 1;
        }
        if(pos == -1) cnt += (a[i] > b[1] ? cntNum[b[1]] : 0);
        else cnt += pos;
    }

    int dem = 0;
    for(int i = 1; i <= n; i++) dem += cntNum[a[i]];



    int u = n * m, v = n * m;

    if(cnt == u) cout << 1 << "/" << 1 << '\n';
    else if(cnt > 0){
        Minimal(cnt, u);
        cout << cnt << "/" << u << '\n';
    } else cout << 0 << "/" << 1 << '\n';

    if(dem == v) cout << 1 << "/" << 1 << '\n';
    else if(dem > 0){
        Minimal(dem, v);
        cout << dem << "/" << v << '\n';
    } else cout << 0 << "/" << 1 << '\n';
}
int32_t main()
{
    FastIO
    cin >> T;

    frac[0] = 1;
    for(int i = 1; i <= NM; i++) frac[i] = (1LL * frac[i - 1] * i) % MOD;
    finv[NM] = pw(frac[NM], MOD - 2) % MOD;
    for (int i = NM; i >= 1; i--) finv[i - 1] = (1LL * finv[i] * i) % MOD;


    while(T--){
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> a[i];
        cin >> m;
        for(int j = 1; j <= m; j++){
            cin >> b[j];
            cntNum[b[j]]++;
        }

        xuli();
        for(int j = 1; j <= m; j++) cntNum[b[j]] = 0;
    }
    return 0;
}
