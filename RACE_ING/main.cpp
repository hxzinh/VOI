#include <bits/stdc++.h>
#define int long long
#define INF 1e9
#define ii pair<int, int>
#define fi first
#define se second
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e5 + 10;
int n, q;
int a[NM], fl[NM][105], fr[NM][105], cntl[NM][105], cntr[NM][105];
ii t[NM];

void readfilr(){
    freopen("INP", "r", stdin);
    freopen("OUT", "w", stdout);
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= q; i++) cin >> t[i].fi >> t[i].se;
}
int dpl(int x, int v, bool ok){
    if(x > n && v > 0) return n + 1;
    if(x < 1 && v > 0) return -1;
    int &res = fl[x][v];
    int &ans = fr[x][v];
    if(ok){
        if(res != -1) return res;
    }
    else if(ans != -1) return ans;
    if(v == 0) if(ok) return res = x;
                else return ans = x;
    if(ok){
        if(++cntl[x][v] > 1) return res = INF;
        int tam = v + a[x] - a[x + 1];
        if(tam < 0) res = dpl(x + 1, abs(tam + 1), false);
        else res = dpl(x + 1, tam - 1, true);
        return res;
    } else {
        if(++cntr[x][v] > 1) return ans = INF;
        int tam = v + a[x - 1] - a[x];
        if(tam < 0) ans = dpl(x - 1, abs(tam + 1), true);
        else ans = dpl(x - 1, tam - 1, false);
        return ans;
    }
}
void xuli(){
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= 100; j++) fl[i][j] = fr[i][j] = -1;
    for(int i = 1; i <= q; i++){
        int res = dpl(t[i].fi, abs(t[i].se), (t[i].se > 0));
        cout << (res != -1 ? res : 0) << '\n';
    }
}
int32_t main()
{
    FastIO
    readfilr();
    xuli();
    return 0;
}
