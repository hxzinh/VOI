#include <bits/stdc++.h>
#define ll long long
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

const int NM = 1e5 + 5;
const int BLSIZE = 320;
int n, q;
long long a[NM], s[NM];
pii p[NM];
vector <int> pos[NM];

///---------------------
int numBlock;
int imp[BLSIZE][NM], L[BLSIZE], R[BLSIZE], id[NM];
long long sum[NM], preSum[NM], backSum[NM];

struct Segmenttree {
    int n;
    vector<int> val, lazy;

    Segmenttree(int _n = 0){
        n = _n;
        val.assign(4 * n + 7, 0);
        lazy.assign(4 * n + 7, 0);
    }

    void update(int i, int l, int r, int x, int d){
        if(l > x || r < x) return;
        if(l == r && l == x){
            val[i] = d;
            return;
        }
        int m = (l + r) >> 1;
        update(2 * i, l, m, x, d);
        update(2 * i + 1, m + 1, r, x, d);
        val[i] = val[2 * i] + val[2 * i + 1];
    }

    int getSum(int i, int l, int r, int u, int v){
        if(l > v || r < u) return 0;
        if(l >= u && r <= v) return val[i];
        int m = (l + r) >> 1;
        int sumL = getSum(2 * i, l, m, u, v);
        int sumR = getSum(2 * i + 1, m + 1, r, u, v);
        return sumL + sumR;
    }

    void update(int x, int d){
        update(1, 1, n, x, d);
    }

    int getSum(int u, int v){
        return getSum(1, 1, n, u, v);
    }
};

void sub1(){
    Segmenttree tree(n);
    for(int i = 1; i <= n; i++) tree.update(i, a[i]);

    while(q--){
        int type, x, y;
        cin >> type >> x >> y;
        if(type == 1) tree.update(x, y);
        else {
            int res = 0;
            for(int i = x; i <= y; i++) res += tree.getSum(p[i].fi, p[i].se);
            cout << res << '\n';
        }
    }
}
void sub2(){
    for(int i = 1; i <= n; i++)
        for(int j = p[i].fi; j <= p[i].se; j++)
        {
            s[i] += a[j];
            pos[j].push_back(i);
        }
    Segmenttree tree(n);
    for(int i = 1; i <= n; i++) tree.update(i, s[i]);

    while(q--){
        int type, x, y;
        cin >> type >> x >> y;
        if(type == 1){
            for(auto u : pos[x]) {
                int curSum = tree.getSum(u, u);
                tree.update(u, curSum + y - a[x]);
            }
            a[x] = y;
        } else {
            cout << tree.getSum(x, y) << '\n';
        }
    }
}

void init(){
    numBlock = n / BLSIZE + (n % BLSIZE != 0);
    for(int i = 1; i <= numBlock; i++){
        L[i] = R[i - 1] + 1;
        R[i] = min(n, i * BLSIZE);
        for(int j = L[i]; j <= R[i]; j++){
            id[j] = i;
            imp[i][p[j].fi]++;
            imp[i][p[j].se + 1]--;
        }

        for(int j = 1; j <= n; j++) imp[i][j] += imp[i][j - 1];
    }
}
void update(int x, long long d){
    for(int i = 1; i <= numBlock; i++) sum[i] += imp[i][x] * d;
    for(int i = x; i <= R[id[x]]; i++) preSum[i] += d;
    for(int i = id[x] + 1; i <= numBlock; i++) backSum[i] += d;
}
long long query(int x){
    return preSum[x] + backSum[id[x]];
}
long long getSum(int u, int v){
    long long res = 0;

    for(int i = id[u] + 1; i < id[v]; i++) res += sum[i];

    for(int i = u; i <= min(v, R[id[u]]); i++) res += query(p[i].se) - query(p[i].fi - 1);
    if(id[u] != id[v])
        for(int i = L[id[v]]; i <= v; i++) res += query(p[i].se) - query(p[i].fi - 1);

    return res;
}
void full(){
    init();
    for(int i = 1; i <= n; i++) update(i, a[i]);

    while(q--){
        int type, x, y;
        cin >> type >> x >> y;
        if(type == 1){
            update(x, y - a[x]);
            a[x] = y;
        } else {
            cout << getSum(x, y) << '\n';
        }
    }
}
int32_t main()
{
    FastIO
    freopen("FUNCTIONS.INP", "r", stdin);
    freopen("FUNCTIONS.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> p[i].fi >> p[i].se;
    cin >> q;

    full();
    return 0;
}
