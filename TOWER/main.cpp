#include <bits/stdc++.h>
#define int long long
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

const int NM = 1e3 + 10;
const int MAX = 2e4 + 10;
int n;
int f[MAX], ID[NM];

struct Data {
    int u, v, w, id;
};
Data a[NM], b[NM];

bool cmp(const Data &A, const Data &B){
    return A.u + A.v < B.u + B.v;
}
void xuli(){
    sort(b + 1, b + n + 1, cmp);

    for(int i = 1; i <= n; i++){
        int id = b[i].id;
        for(int j = a[id].u + a[id].v; j >= a[id].u; j--){
            maximize(f[j], f[j - a[id].u] + a[id].w);
        }
    }

    int res = -INF;
    for(int i = 1; i <= MAX; i++) maximize(res, f[i]);
    cout << res;
}
int32_t main()
{
    FastIO
    freopen("TOWER.INP", "r", stdin);
    freopen("TOWER.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i].u >> a[i].v >> a[i].w;
        a[i].id = i;
        b[i] = a[i];
    }

    xuli();
    return 0;
}
