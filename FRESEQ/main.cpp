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

const int NM = 1e5 + 10;
const int BLSIZE = 320;
int n, q;
int a[NM];
int g[1005][1005], f[NM][12];
pii query[NM];
vector<int> val;
///------------------------------------------------------
int imp[NM], id[NM], L[NM], R[NM];

void sub1(){
    for(int i = 1; i <= n; i++) val.push_back(a[i]);
    sort(ALL(val));
    val.resize(unique(ALL(val)) - val.begin());
    for(int i = 1; i <= n; i++){
        a[i] = lower_bound(ALL(val), a[i]) - val.begin() + 1;
    }

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) g[i][j] = g[i - 1][j] + (a[i] == j);

    for(int i = 1; i <= q; i++){
        int res = 0;
        for(int j = 1; j <= n; j++)
            maximize(res, g[query[i].se][j] - g[query[i].fi - 1][j]);
        cout << res << '\n';
    }
}

void sub2(){
    for(int i = 1; i <= n; i++)
        for(int j = 0; j <= 10; j++) f[i][j] = f[i - 1][j] + (a[i] == j);

    for(int i = 1; i <= q; i++){
        int res = 0;
        for(int j = 0; j <= 10; j++)
            maximize(res, f[query[i].se][j] - f[query[i].fi - 1][j]);
        cout << res << '\n';
    }
}

int getCnt(int u, int v){
    int res = 0;
    if(id[u] == id[v]) return imp[id[u]] - (u - L[id[u]]) - (R[id[u]] - v);

    int blockL = (u == L[id[u]] ? id[u] : id[u] + 1);
    int blockR = (v == R[id[v]] ? id[v] : id[v] - 1);
    for(int j =  blockL; j <= blockR; j++) maximize(res, imp[j]);
    if(u > L[id[u]]) maximize(res, L[id[u] + 1] - u);
    if(v < R[id[v]]) maximize(res, v - R[id[v] - 1]);
    return res;
}
void full(){
    for(int i = 1; i <= n; i++) val.push_back(a[i]);
    sort(ALL(val));
    val.resize(unique(ALL(val)) - val.begin());
    for(int i = 1; i <= n; i++){
        a[i] = lower_bound(ALL(val), a[i]) - val.begin() + 1;
    }

    int t = 1, numBlock = 0;
    while(t <= n){
        imp[++numBlock] = 1;
        L[numBlock] = t;
        id[t] = numBlock;
        while(a[t] == a[t + 1]){
            t++;
            id[t] = numBlock;
            imp[numBlock]++;
        }
        R[numBlock] = t;
        t++;
    }

    for(int i = 1; i <= q; i++){
        cout << getCnt(query[i].fi, query[i].se) << '\n';
    }
}

int32_t main()
{
    FastIO
    freopen("FRESEQ.INP", "r", stdin);
    freopen("FRESEQ.OUT", "w", stdout);
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= q; i++) cin >> query[i].fi >> query[i].se;

    bool ok = true;
    for(int i = 1; i <= n; i++){
        if(a[i] > 10){
            ok = false;
            break;
        }
    }

    if(n <= 1000 && q <= 1000) sub1();
    else if(ok) sub2();
    else full();
    return 0;
}
