#include <bits/stdc++.h>
#define int long long
#define INF 1e9
#define ii pair<int, int>
#define fi first
#define se second
#define uLL unsigned long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e5 + 10;
int n, L, R;
int cnt = 0;
int a[NM];
bool ok1, ok2, cx1, cx2;


void readfile(){
    freopen("MAXDIS.INP", "r", stdin);
    freopen("MAXDIS.OUT", "w", stdout);
    cin >> n >> L >> R;
    ok1 = ok2 = true;
    for(int i = 1; i <= n; i++){
        int u; cin >> u;
        if(u == L) ok1 = false, cx1 = true;
        if(u == R) ok2 = false, cx2 = true;
        if(u > L && ok1){a[++cnt] = L; ok1 = false;}
        if(u > R && ok2){a[++cnt] = R; ok2 = false;}
        a[++cnt] = u;
    }
    if(ok1) a[++cnt] = L;
    if(ok2) a[++cnt] = R;
}
pair<uLL, int> getDis(int u, int v){
    uLL dis = v - u;
    return make_pair(dis / 2, v - (dis / 2));
}
void xuli(){
    sort(a + 1, a + n + 1);
    pair<uLL, int> res = make_pair(0, -1);

    a[0] = (L < a[1] ? L : a[1]); a[cnt + 1] = (R > a[cnt] ? R : a[cnt]);
    for(int i = 1; i <= cnt; i++){
        pair<uLL, int> u;
        if(a[i] == L && !cx1) u = make_pair(min(a[i] - a[i - 1], a[i + 1] - a[i]), a[i]);
        else if(a[i] == R && !cx2) u = make_pair(min(a[i] - a[i - 1], a[i + 1] - a[i]), a[i]);
        else u = getDis(a[i], a[i + 1]);
        if(u.fi >= res.fi && u.se >= L && u.se <= R) res = u;
    }
    cout << res.se;
}
int32_t main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
