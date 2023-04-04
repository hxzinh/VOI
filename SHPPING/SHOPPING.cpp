#include <bits/stdc++.h>
#define int long long
#define INF 1e18
#define ii pair<int, int>
#define fi first
#define se second
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 2e5 + 10;
int n, q;
int a[NM];

void readfile(){
    freopen("SHOPPING.INP", "r", stdin);
    freopen("SHOPPING.OUT", "w", stdout);
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> a[i];
}
void xuli(){
    while(q--){
        int l, r, cost;
        cin >> cost >> l >> r;

        int res = 0;
        for(int i = l; i <= r; i++){
            res += cost / a[i];
            cost -= a[i] * (cost / a[i]);
        }
        cout << cost << '\n';
    }

}
int32_t main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
