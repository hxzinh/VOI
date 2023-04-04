#include <bits/stdc++.h>
#define int long long
#define ll long long
#define INF 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define mp(x, y) make_pair(x, y)
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

const int NM = 2e5 + 10;
int n;
int t[NM];
ll f[NM][10];
pair<ll, ll> g[6][5][5], p[NM][5];
vector<int> card[NM][4];
vector<pii> a[NM];

bool cmp(const pii &A, const pii &B){
    return A.se > B.se;
}
void xuli(){
    memset(p, 0, sizeof p);

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 3; j++){
            sort(ALL(card[i][j]), greater<int>());
            int sz = (j == 1 ? 3 : 1);
            while(card[i][j].size() > sz) card[i][j].pop_back();

            for(int u : card[i][j]) a[i].push_back(mp(j, u));
        }
    }

    memset(f, -1, sizeof f);
    f[0][0] = 0;
    for(int i = 0; i < n; i++){
        int sz = a[i + 1].size();

        for(int mask = 0; mask < MASK(sz); mask++){
            int cost = 0, select = __builtin_popcount(mask);
            if(select > 3) continue;
            pii cur = {0, 0};
            bool ok = true;
            for(int j = 0; j < sz; j++) if(BIT(mask, j) && select <= 3) {
                if(cost + a[i + 1][j].fi <= 3){
                    cur.fi += a[i + 1][j].se;
                    maximize(cur.se, a[i + 1][j].se);
                    cost += a[i + 1][j].fi;
                } else {
                    ok = false;
                    break;
                }
            }

            if(!ok) continue;
            for(int num = 0; num < 10; num++) if(f[i][num] > -1){
                if(num + select >= 10) maximize(f[i + 1][(num + select) % 10], f[i][num] + cur.fi + cur.se);
                else maximize(f[i + 1][num + select], f[i][num] + cur.fi);
            }
        }
    }

    ll res = -INF;
    for(int i = 0; i < 10; i++) maximize(res, f[n][i]);
    cout << res;
}
int32_t main()
{
    FastIO
    freopen("DESTROY.INP", "r", stdin);
    freopen("DESTROY.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> t[i];
        for(int j = 1; j <= t[i]; j++) {
            int u, v; cin >> u >> v;
            card[i][u].push_back(v);
        }
    }

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
