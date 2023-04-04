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

const int MOD = 1e9 + 7;
const int NM = 2e5 + 10;
int n;
int frac[NM], finv[NM], ans[NM], cnt[NM];
vector<int> val;

struct Data {
    int val, id;

    bool inline operator < (const Data &A) const {
        return val > A.val;
    }
};
Data a[NM];

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
int comb(int t, int n) {
	return t > n ? 0 : (1LL * frac[n] * finv[t] % MOD) * finv[n - t] % MOD;
}
void xuli(){
    for(int i = 1; i <= n; i++){
        cnt[a[i].val]++;
        val.push_back(a[i].val);
    }
    sort(ALL(val));
    val.resize(unique(ALL(val)) - val.begin());

    int sum = 0;
    for(int u : val) sum += comb(2, cnt[u]);

    for(int i = 1; i <= n; i++){
        int tmp = sum - comb(2, cnt[a[i].val]) + comb(2, cnt[a[i].val] - 1);
        cout << tmp << '\n';
    }
}
int main()
{
    FastIO
    freopen("BALLS.INP", "r", stdin);
    freopen("BALLS.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i].val;
        a[i].id = i;
    }

    frac[0] = 1;
    for(int i = 1; i <= n; i++) frac[i] = (1LL * frac[i - 1] * i) % MOD;
    finv[n] = pw(frac[n], MOD - 2) % MOD;
    for (int i = n; i >= 1; i--) finv[i - 1] = (1LL * finv[i] * i) % MOD;

    xuli();
    return 0;
}
