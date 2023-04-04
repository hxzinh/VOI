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

const int NM = 1e5 + 10;
int n, m;
int cntGuest = 0, k = 0, result = 0;
int diff[45], f[MASK(20)];
pair<int, string> a[NM];
bool cx[45][45];
map<string, int> id;

void backtrack(int x, int mask, int cnt){
    if(x > m){
        //cout << mask << " " << cnt << '\n';
        maximize(result, cnt);
        return;
    }

    if(!BIT(mask, x - 1)) backtrack(x + 1, mask | diff[x], cnt + 1);
    backtrack(x + 1, mask | MASK(x - 1), cnt);
}
void sub12(){
    int tmp = 0;
    for(int i = 0; i <= n; i++){
        if(a[i].fi == 1){
            if(tmp){
                for(int j = 1; j <= m; j++) if(BIT(tmp, j - 1))
                    diff[j] |= tmp;
                tmp = 0;
            }
        } else tmp |= MASK(int(id[a[i].se] - 1));
    }
    if(tmp) for(int i = 1; i <= m; i++) if(BIT(tmp, i - 1)) diff[i] |= tmp;


    backtrack(1, 0, 0);
    cout << result;
}
void xuli(){
    int tmp = 0;
    for(int i = 0; i <= n; i++){
        if(a[i].fi == 1){
            if(tmp){
                for(int j = 1; j <= m; j++) if(BIT(tmp, j - 1))
                    diff[j] |= tmp;
                tmp = 0;
            }
        } else tmp |= MASK(int(id[a[i].se] - 1));
    }
    if(tmp) for(int i = 1; i <= m; i++) if(BIT(tmp, i - 1)) diff[i] |= tmp;

    memset(f, -1, sizeof f);
    int res = 0;
    f[MASK(m) - 1] = 0;
    for(int mask = MASK(m) - 1; mask >= 0; mask--) if(f[mask] > -1) {
        for(int i = 1; i <= m; i++) if(BIT(mask, i - 1)) {
            maximize(f[mask ^ diff[i]], f[mask] + 1);
            maximize(f[mask ^ MASK(i - 1)], f[mask]);
        }
    }

    for(int mask = 0; mask < MASK(m); mask++) maximize(res, f[mask]);
    cout << res;
}
int32_t main()
{
    FastIO
    freopen("FRIEND.INP", "r", stdin);
    freopen("FRIEND.OUT", "w", stdout);
    cin >> n >> m;
    a[0].fi = 1;
    for(int i = 1; i <= n; i++){
        cin >> a[i].fi;
        if(a[i].fi == 2){
            cin >> a[i].se;
            if(!id[a[i].se]) id[a[i].se] = ++cntGuest;
        }
    }

    sub12();
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
