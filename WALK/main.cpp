#include <bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define popcount(x) __builtin_popcount(x)
#define set(x) setprecision(x)
#define MASK(x) (1LL << (x))
#define BIT(x, i) ((x) >> (i) & 1)
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

int n, m;

void xuli(){
    int cnt = 1, res = 0, pre = n;
    while(true){
        int x = n + (cnt % 2 == 0 ? 1 : -1) * MASK(cnt - 1);
        if((x <= m && pre >= m) || (pre <= m && x >= m)){
            res += abs(pre - m);
            break;
        } else res += abs(pre - x);
        pre = x;
        cnt++;
    }
    cout << cnt << " " << res;
}
int32_t main()
{
    FastIO
    freopen("WALK.INP", "r", stdin);
    freopen("WALK.OUT", "w", stdout);
    cin >> n >> m;

    xuli();
    return 0;
}
