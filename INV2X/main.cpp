#include <bits/stdc++.h>
#define ll long long
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

const int NM = 1e3 + 10;
int n;
pair<int, int> a[NM];
int cnt[NM][NM];

int main() {
    FastIO
    freopen("INV2X.INP", "r", stdin);
    freopen("INV2X.OUT", "w", stdout);

    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i].fi;
        a[i].se = i;
    }

    sort(a + 1, a + n + 1);

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) cnt[i][j] = cnt[i - 1][j] + (a[i].se >= j);

    int res = 0;
    for(int i = 1; i <= n; i++){
        for(int j = i - 1; j > 0; j--){
            if(a[i].fi > 2 * a[j].fi){
                res += cnt[j][a[i].se];
                break;
            }
        }
    }
    cout << res;

    return 0;
}
