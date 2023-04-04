#include <bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
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
int n, m, id = -1;
pii ans;

struct Data{
    int x, y, id;

    bool inline operator < (const Data &P) const {
        return (x == P.x ? y < P.y : x < P.x);
    }

} a[NM];

bool xuli(){
    int Min = INF;
    for(int i = 1; i <= n; i++){
        cin >> a[i].x >> a[i].y;
        a[i].id = i;
    }

    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++){
        if(a[i].x > Min){
            ans = {a[id].id, a[i].id};
            return true;
        }
        if(minimize(Min, a[i].y)) id = i;
    }

    return false;
}
int32_t main() {
    FastIO
    freopen("NEKO.INP", "r", stdin);
    freopen("NEKO.OUT", "w", stdout);
    cin >> n >> m;

    if(xuli()){
        cout << "YES" << '\n';
        cout << ans.fi << " " << ans.se;
    } else cout << "NO";
    return 0;
}
