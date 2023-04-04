#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
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

const int NM = 1e6 + 1;
int n, maxHigh = -1;
int h[NM], f[NM];
int P[NM][21];
int Val[NM];

struct FenwickTree {
    int n;

    FenwickTree(int _n = 0){
        n = _n;
    }

    void update(int u, int x){
        for(; u > 0; u -= u & -u) minimize(Val[u], x);
    }

    int getMin(int u){
        int res = INF;
        for(; u <= n; u += u & -u) minimize(res, Val[u]);
        return res;
    }
};

void full(){
    memset(Val, INF, sizeof Val);
    FenwickTree tree(maxHigh);

    for(int i = n; i > 0; i--){
        f[i] = tree.getMin(h[i] + 1);
        tree.update(h[i], i);
        if(f[i] == INF) f[i] = -1;
    }

    for(int i = 1; i <= n; i++) P[i][0] = f[i];

    for(int j = 1; MASK(j) <= n; j++){
        for(int i = 1; i <= n; i++)
            if(P[i][j - 1] > 0) P[i][j] = P[P[i][j - 1]][j - 1];
            else P[i][j] = -1;
    }

    for(int i = 1; i <= n; i++){
        int a; cin >> a;
        if(f[i] == -1){
            cout << -1 << " ";
            continue;
        }

        int last = i;
        for (int mask = a; mask > 0; mask -= mask & -mask) {
            int j = __builtin_ctz(mask & -mask);
            last = P[last][j];

            if(last == -1) {
                break;
            }
        }
        cout << (last > 0 ? h[last] : -1) << " ";
    }
}
int main()
{
    FastIO
    freopen("MTCAT.INP", "r", stdin);
    freopen("MTCAT.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> h[i];
        maximize(maxHigh, h[i]);
    }

    full();
    return 0;
}
