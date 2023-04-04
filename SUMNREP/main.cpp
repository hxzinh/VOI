#include <bits/stdc++.h>
#define int long long
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

const int NM = 3e5 + 10;
int n, m;
int a[NM], cnt[1000005];
vector<int> prime;
bool ok[1000005];

struct SegmentTree {
    int n;
    vector<ll> sum, Max;

    SegmentTree(int _n = 0){
        n = _n;
        sum.assign(4 * n + 7, 0);
        Max.assign(4 * n + 7, -1);
    }

    void build(int i, int l, int r){
        if(l > r) return;
        if(l == r){
            sum[i] = a[l];
            Max[i] = a[l];
            return;
        }

        int m = (l + r) >> 1;
        build(2 * i, l, m);
        build(2 * i + 1, m + 1, r);
        sum[i] = sum[2 * i] + sum[2 * i + 1];
        Max[i] = max(Max[2 * i], Max[2 * i + 1]);
    }

    void update(int i, int l, int r, int u, int v){
        if(u > r || v < l || l > r || Max[i] <= 2) return;
        if(l == r && u <= l && v >= l){
            a[l] = cnt[a[l]];
            sum[i] = a[l];
            Max[i] = a[l];
            return;
        }

        int m = (l + r) >> 1;
        update(2 * i, l, m, u, v);
        update(2 * i + 1, m + 1, r, u, v);
        sum[i] = sum[2 * i] + sum[2 * i + 1];
        Max[i] = max(Max[2 * i], Max[2 * i + 1]);
    }

    ll getSum(int i, int l, int r, int u, int v){
        if(u > r || v < l || l > r) return 0;
        if(u <= l && v >= r) return sum[i];

        int m = (l + r) >> 1;
        int sumL = getSum(2 * i, l, m, u, v);
        int sumR = getSum(2 * i + 1, m + 1, r, u, v);
        return sumL + sumR;
    }

    void update(int u, int v){
        update(1, 1, n, u, v);
    }

    ll getSum(int u, int v){
        return getSum(1, 1, n, u, v);
    }
};

void xuli(){
    for(int i = 1 ; i <= 1000000 ; i++)
    for(int j = i ; j <= 1000000 ; j += i)
        cnt[j]++;

    SegmentTree tree(n);
    tree.build(1, 1, n);

    for(int i = 1; i <= m; i++){
        int type, u, v;
        cin >> type >> u >> v;
        if(type == 1) tree.update(u, v);
        else cout << tree.getSum(u, v) << '\n';
    }
}
int32_t main()
{
    FastIO
    freopen("SUMNREP.INP", "r", stdin);
    freopen("SUMnREP.OUT", "w", stdout);
    cin >> n >> m;
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
