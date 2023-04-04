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

const int NM = 1e6 + 10;
int n, k, q;
int a[NM], cnt[1005][1005], d[NM];

void sub1(){
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) cnt[i][j] = cnt[i - 1][j] + 1;

    set<int> S;
    while(q--){
        int u, v; cin >> u >> v;
        S.clear();
        for(int i = u; i <= v; i++){
            d[a[i]]++;
            S.insert(a[i]);
        }

        bool ok = true;
        for(int u : S) if(d[u] < k) {
            cout << u << '\n';
            break;
        }
        if(ok) cout << "0" << '\n';
    }
}
int32_t main()
{
    FastIO
    freopen("CUTCAKE.INP", "r", stdin);
    freopen("CUTCAKE.OUT", "w", stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    cin >> q;

    sub1();
    return 0;
}

/* Author: hxzinh */
