#include <bits/stdc++.h>
#define int long long
#define INF 1e9
#define pii pair<int, int>
#define fi first
#define se second
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

int T, x, y, u, v, n, m, p, q;

int getDist(int a1, int b1, int a2, int b2){
    int ans = (a2 - a1) * (a2 - a1) + (b2 - b1) * (b2 - b1);
    return ans;
}
int getAns(){
    int dx = max(max(x, n) - min(u, p), 0LL);
    int dy = max(max(y, m) - min(v, q), 0LL);
    return dx * dx + dy * dy;
}
void readfilr(){
    freopen("COVERED.INP", "r", stdin);
    freopen("COVERED.OUT", "w", stdout);
    cin >> T;
    while(T--){
        cin >> x >> y >> u >> v >> n >> m >> p >> q;
        cout << getAns() << '\n';
    }
}
int32_t main()
{
    FastIO
    readfilr();
    return 0;
}
