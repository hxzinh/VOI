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

const int NM = 1e6 + 10;
int sub;

void readfile(){
    cin >> sub;

    while(sub--){
        int n, m, x, y;
        cin >> n >> m >> x >> y;

        if(m > n) swap(n, m);
        if(m == 1){
            cout << (n - 1) * x << '\n';
            continue;
        }

        int res = 0;
        if(2 * x <= y){
            res = (n - 1) * x + (m - 1) * x;
        } else if(y < x){
             res = (min(n, m) - 1) * y;
             int last = max(n, m) - min(n, m);
             if(last % 2 == 0) res += last * y;
             else res += (last - 1) * y + x;
        } else {
            res = (min(n, m) - 1) * y + (max(n, m) - min(n, m)) * x;
        }
        cout << res << '\n';
    }

}
int32_t main()
{
    FastIO
    freopen("HURRYBIRD.INP", "r", stdin);
    freopen("HURRYBIRD.OUT", "w", stdout);
    readfile();
    return 0;
}
