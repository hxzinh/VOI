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
int n, k;
int result = 0, c[NM];
pii a[NM];
vector<int> edges[NM];

bool check(int u, int p) {
    for(int v : edges[u]) if(v != p) {
        if((a[u] > a[v] && c[u] > c[v]) || (a[u] < a[v] && c[u] < c[v])) {
            bool tmp = check(v, u);
            if(!tmp) return false;
        } else return false;
    }
    return true;
}
void sub1() {
    if(n == 1) {
        cout << k;
        return;
    }

    for(int i = 1; i <= k; i++) c[i] = i;

    int res = 0;
    do {
        if(check(1, -1)) res++;
    } while(next_permutation(c + 1, c + k + 1));

    cout << res;
}
int32_t main()
{
    FastIO
    freopen("SCORING.INP", "r", stdin);
    freopen("SCORING.OUT", "w", stdout);
    cin >> n >> k;
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    for(int i = 1; i <= n; i++) {
        cin >> a[i].fi;
        a[i].se = i;
    }

    if(k == n) cout << 1;
    else sub1();
    return 0;
}
