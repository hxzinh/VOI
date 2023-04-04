#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
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

const int MOD = 998244353;
const int NM = 5e5 + 1;
int n, k, Sub;
int qMax[NM][20], qMin[NM][20];
int high[NM];
int a[NM];

int getMax(int u, int v){
    int k = log2(v - u + 1);
    return max(qMax[u][k], qMax[v - MASK(k) + 1][k]);
}
int getMin(int u, int v){
    int k = log2(v - u + 1);
    return min(qMin[u][k], qMin[v - MASK(k) + 1][k]);
}
void sub3() {
    int res = 0, ans = n;
    for(int i = 1; i <= n; i++){
        int l = i, r = n, p = 0;
        while(l <= r){
            int mid = (l + r) >> 1;
            if(getMax(i, mid) - getMin(i, mid) <= k){
                p = mid;
                l = mid + 1;
            } else r = mid - 1;
        }
        res =  (res + p - i + 1) % MOD;
    }

    sort(a + 1, a + n + 1);
    for (int l = 1; l <= n; ++l) {
        int r = upper_bound(a + 1, a + n + 1, a[l] + k) - a - 1;
        ans = (ans + 1LL * high[r - l]) % MOD;
    }

    printf("%d ", res);
    printf("%d", ans);
}

int32_t main()
{
    FastIO
    freopen("DELTA.INP", "r", stdin);
    freopen("DELTA.OUT", "w", stdout);
    scanf("%d", &Sub);
    scanf("%d", &n); scanf("%d", &k);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);

    high[0] = 0;
    for (int i = 1; i <= NM - 400; ++i) high[i] = (high[i - 1] * 2 + 1) % MOD;

    for(int i = 1; i <= n; i++) qMax[i][0] = qMin[i][0] = a[i];
    for(int k = 1; MASK(k) <= n; k++){
        for(int i = 1; i + MASK(k) - 1 <= n; i++) {
            qMax[i][k] = max(qMax[i][k - 1], qMax[i + MASK(k - 1)][k - 1]);
            qMin[i][k] = min(qMin[i][k - 1], qMin[i + MASK(k - 1)][k - 1]);
        }
    }

    sub3();
    return 0;
}
