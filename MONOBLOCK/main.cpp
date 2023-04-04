#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define mp make_pair
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

const int NM = 1e5 + 10;
int n, q;
int a[NM], id[NM], cnt[NM];

struct FenwickTree {
    int n;
    vector<int> sum;

    FenwickTree(int _n = 0) {
        n = _n;
        sum.assign(n + 7, 0);
    }

    void update(int u, int x) {
        for(; u <= n; u += u & -u) sum[u] += x;
    }

    int getCnt(int u) {
        int res = 0;
        for(; u > 0; u -= u & -u) res += sum[u];
        return res;
    }
};

bool check(int u) {
    if(u == 1 && a[u] != a[u + 1]) return true;
    if(u == n && a[u] != a[u - 1]) return true;
    if(a[u] != a[u - 1] && a[u] != a[u + 1]) return true;
    return false;
}
void xuli() {
    int cntBlock = 1;
    ll res = n, tmp = 1;
    cnt[1]++;
    for(int i = 2; i <= n; i++) {
        if(a[i] != a[i - 1]) {
            tmp *= cnt[cntBlock];
            cntBlock++;
        }
        cnt[cntBlock]++;
    }

    for(int i = 2; i <= cntBlock; i++) res += (cntBlock - i + 1) * tmp;

    cout << res;
}
int32_t main()
{
    FastIO
    freopen("MONOBLOCK.INP", "r", stdin);
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> a[i];

    xuli();
    return 0;
}

/* Author: hxzinh */

/*
-----code ko bug-----code ko bug-----code ko bug--------------

          _.-/`)
         // / / )
      .=// / / / )
     //`/ / / / /
    // /     ` /
   ||         /
    \\       /
     ))    .'
    //    /
         /
*/
