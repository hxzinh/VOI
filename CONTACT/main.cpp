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
const int MOD = 1e9 + 7;
int n, m;
int par[NM];
vector<int> gr[22];
bool cx[NM];

struct Data {
    int L, R, k;
} a[NM];

struct DijoinsetUnion {
    vector<int> fa;
    int n;

    DijoinsetUnion(int _n = 0) {
        n = _n;
        fa.assign(n + 7, -1);
    }

    int root(int x) {
        if(fa[x] < 0) return x;
        return fa[x] = root(fa[x]);
    }

    void Merge(int x, int y) {
        int u = root(x), v = root(y);
        if(u == v) return;

        if(fa[u] > fa[v]) swap(u, v);
        fa[u] += fa[v];
        fa[v] = u;
    }
};

ll pw(int x, int k) {
    if(k == 1) return x;
    if(k == 0) return 1;
    ll tmp = pw(x, k >> 1);
    if(k & 1) return (tmp * x % MOD) * tmp % MOD;
    else return tmp * tmp % MOD;
}
void sub1() {
    cout << pw(2, n);
}
int root(int x) {
    if(par[x] < 0) return x;
    return par[x] = root(par[x]);
}
bool join(int x, int y) {
    int u = root(x), v = root(y);
    if(u == v) return false;

    if(par[u] > par[v]) swap(u, v);
    par[u] += par[v];
    par[v] = u;
    return true;
}
void sub23() {
    memset(par, -1, sizeof par);
    for(int i = 1; i <= m; i++) {
        for(int u = 0; u < a[i].k; u++) {
            join(a[i].L + u, a[i].R + u);
        }
    }

    set<int> S;
    for(int i = 1; i <= n; i++) S.insert(root(i));
    cout << pw(2, S.size());
}
void solve(int u, int v, int k) {
    if(k == 0) {
        join(u, v);
        return;
    }

    solve(u, v, k - 1);
    solve(u + MASK(k - 1), v + MASK(k - 1), k - 1);
}
void xuli() {
    memset(par, -1, sizeof par);

    int ans = n;
    for(int i = 1; i <= m; i++) {
        int dist = a[i].k, u = a[i].L, v = a[i].R;
        while(dist) {
            int curBit = 0;
            while(MASK(curBit) <= dist) curBit++;
            curBit--;

            if(join(u, v)) ans--;
            gr[curBit].push_back(u);
            gr[curBit].push_back(v);
            u += MASK(curBit);
            v += MASK(curBit);
            dist -= MASK(curBit);
        }
    }

    for(int k = 20; k > 0; k--) if(gr[k].size()) {
        sort(ALL(gr[k]));
        gr[k].resize(unique(ALL(gr[k])) - gr[k].begin());
        for(int u : gr[k]) {
            if(join(u, u + MASK(k - 1))) ans--;
            gr[k - 1].push_back(u);
            gr[k - 1].push_back(u + MASK(k - 1));
        }
    }

    cout << pw(2, ans);
}
int32_t main()
{
    FastIO
    freopen("CONTACT.INP", "r", stdin);
    freopen("CONTACT.OUT", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int L, R, k;
        cin >> L >> R >> k;
        a[i] = {L, R, k};
    }

    if(m == 0) sub1();
    else if(n <= 2000 && m <= 2000) sub23();
    else xuli();

    //xuli();
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
