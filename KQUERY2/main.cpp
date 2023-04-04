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

const int NM = 3e4 + 10;
const int MAX = 1e4 + 10;
const int BLSIZE = 200;
int n, q, numBlock, maxA = -1;
int a[NM], id[NM], L[NM], R[NM], sz[NM];

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
    int numBlock = n / BLSIZE + (n % BLSIZE != 0);
    FenwickTree tree[numBlock + 5];
    for(int i = 1; i <= numBlock; i++) tree[i] = FenwickTree(MAX);

    for(int i = 1; i <= numBlock; i++){
        L[i] = R[i - 1] + 1;
        R[i] = min(i * BLSIZE, n);
        sz[i] = R[i] - L[i] + 1;
        for(int j = L[i]; j <= R[i]; j++){
            id[j] = i;
            tree[i].update(a[j], 1);
        }
    }

    while(q--){
        int type, u, v, k;
        cin >> type;
        if(type == 0){
            cin >> u >> k;
            tree[id[u]].update(a[u], -1);
            tree[id[u]].update(k, 1);
            a[u] = k;
        } else {
            cin >> u >> v >> k;
            int res = 0;
            if(id[u] == id[v]) for(int i = u; i <= v; i++) res += (a[i] > k);
            else {
                for(int i = id[u] + 1; i < id[v]; i++) res += (sz[i] - tree[i].getCnt(k));
                for(int i = u; i <= R[id[u]]; i++) res += (a[i] > k);
                for(int i = L[id[v]]; i <= v; i++) res += (a[i] > k);
            }
            cout << res << '\n';
        }
    }
}
int32_t main()
{
    FastIO
    freopen("KQUERY2.INP", "r", stdin);
    freopen("KQUERY2.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    cin >> q;

    xuli();
    return 0;
}

/* Author: hxzinh */
