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

const int NM = 105;
const double pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117067;
const int MOD = 1e9 + 7;
int n, m;
ll newX[NM], newY[NM];
pii a[NM];
bool cx[NM][NM][10], t[NM][NM][10];
vector<ll> zipx, zipy;

void backtrack(int x, int y, int p) {
    cx[x][y][p] = false;
    if(p == 1) {
        if(t[x - 1][y][4] && cx[x - 1][y][4] && x - 1 > 0) backtrack(x - 1, y, 4);
        if(t[x][y - 1][2] && cx[x][y - 1][2] && y - 1 > 0) backtrack(x, y - 1, 2);
        if(t[x][y][5] && cx[x][y][5]) backtrack(x, y, 5);
    }
    if(p == 2) {
        if(t[x - 1][y][3] && cx[x - 1][y][3] && x - 1 > 0) backtrack(x - 1, y, 3);
        if(t[x][y + 1][1] && cx[x][y + 1][1] && y + 1 <= 100) backtrack(x, y + 1, 1);
        if(t[x][y][5] && cx[x][y][5]) backtrack(x, y, 5);
    }
    if(p == 3) {
        if(t[x][y + 1][4] && cx[x][y + 1][4] && y + 1 <= 100) backtrack(x, y + 1, 4);
        if(t[x + 1][y][2] && cx[x + 1][y][2] && x + 1 <= 100) backtrack(x + 1, y, 2);
        if(t[x][y][5] && cx[x][y][5]) backtrack(x, y, 5);
    }
    if(p == 4) {
        if(t[x + 1][y][1] && cx[x + 1][y][1] && x + 1 <= 100) backtrack(x + 1, y, 1);
        if(t[x][y - 1][3] && cx[x][y - 1][3] && y - 1 > 0) backtrack(x, y - 1, 3);
        if(t[x][y][5] && cx[x][y][5]) backtrack(x, y, 5);
    }
    if(p == 5) {
        if(t[x][y][1]) backtrack(x, y, 1);
        if(t[x][y][2]) backtrack(x, y, 2);
        if(t[x][y][3]) backtrack(x, y, 3);
        if(t[x][y][4]) backtrack(x, y, 4);
    }
}
void xuli() {
    double cir = pi * pow(0.5, 2);
    double cor = (1 - cir) / 4;
    backtrack(0, 0, 5);

    ll cnt = 0;
    for(int i = 1; i <= 100; i++)
        for(int j = 1; j <= 100; j++)
            for(int k = 1; k < 5; k++) if(cx[i][j][k]) cnt++;

    cout << fixed << setprecision(5) << cor * (cnt * 1.00);
}
int32_t main()
{
    FastIO
    freopen("NANO.INP", "r", stdin);
    freopen("NANO.OUT", "w", stdout);
    cin >> n;

    memset(t, true, sizeof t);
    memset(cx, true, sizeof cx);

    for(int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        a[i] = mp(x, y);
        zipx.push_back(x);
        zipy.push_back(y);
        //t[x][y][5] = false;
    }

    sort(ALL(zipx));
    zipx.resize(unique(ALL(zipx)) - zipx.begin());
    newX[0] = 1;
    for(int i = 0; i < zipx.size() - 1; i++) newX[i + 1] = newX[i] + 1 + (zipx[i] + 1 < zipx[i + 1]);

    sort(ALL(zipy));
    zipy.resize(unique(ALL(zipy)) - zipy.begin());
    newY[0] = 1;
    for(int i = 0; i < zipy.size() - 1; i++) newY[i + 1] = newY[i] + 1 + (zipy[i] + 1 < zipy[i + 1]);

    for(int i = 1; i <= n; i++) {
        a[i].fi = newX[lower_bound(ALL(zipx), a[i].fi) - zipx.begin()];
        a[i].se = newY[lower_bound(ALL(zipy), a[i].se) - zipy.begin()];
        t[a[i].fi][a[i].se][5] = false;
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
