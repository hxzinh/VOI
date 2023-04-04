#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define ii pair<int, int>
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

struct FenwickTree{
    vector<int> v;
    int n;

    FenwickTree(int _n = 0){
        n = _n;
        v.assign(n + 7, 0);
    }

    void update(int x, int d){
        for(; x <= n; x += x & -x) v[x] ^= d;
    }

    int xorr(int x){
        int res = 0;
        for(; x >= 1; x &= x - 1) res ^= v[x];
        return res;
    }

    int getXor(int u, int v){
        return xorr(u) ^ xorr(v - 1);
    }
};

int main()
{
    FastIO
    int x;
    cin >> x;
    cout << popcount(x);
    return 0;
}
