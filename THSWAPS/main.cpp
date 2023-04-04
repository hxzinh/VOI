#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define pii pair<int, int>
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

const int NM = 250005;
int n, q;
int a[NM];

struct FenwickTree {
    int n;
    vector<int> val;

    FenwickTree(int _n = 0){
        n = _n;
        val.assign(n + 7, 0);
    }

    void update(int x, int u){
        for(; x <= n; x += x & -x) val[x] += u;
    }

    int getCnt(int x){
        int res = 0;
        for(; x > 0; x -= x & -x) res += val[x];
        return res;
    }
};

void xuli(){

}
int32_t main()
{
    FastIO
    freopen("THSWAPS.INP", "r", stdin);
    freopen("THSWAPS.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    cin >> q;

    xuli();
    return 0;
}

/* Author: hxzinh */
