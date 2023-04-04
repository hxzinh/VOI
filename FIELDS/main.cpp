#include <bits/stdc++.h>
#define int long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e5 + 10;
int T, n, m, b;
int a[NM], s[NM];

void readfile(){
    freopen("FIELDS.INP", "r", stdin);
    freopen("FIELDS.OUT", "w", stdout);
    cin >> T;
    cin >> n >> m >> b;
    for(int i = 1; i <= n; i++) cin >> a[i];
}
int getDist(int l, int r){
    if(l > r) return 0;
    return s[r] - s[l - 1];
}
int getCost(int l, int r){
    if(l > r) return 0;
    int m = (r - l + 1) >> 1;
    int x = l + m - 1, y = r - m + 1;
    return getDist(y, r) - getDist(l, x);
}
void xuli(){
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];

    int res = 0, r = 1;
    for(int l = 1; l <= n; l++){
        while(r <= n && getCost(l, r) <= b) r++;
        maximize(res, r - l);
    }
    cout << res;
}
int32_t main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
