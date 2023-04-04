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

const int NM = 1e3 + 10;
int n, m;
int s[NM], a[NM];

struct Data {
    int fi, se, cost;
};
Data q[NM];

bool cmp(const pii &A, const pii &B){
    return A.se < B.se;
}
void xuli(){
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++) if(a[i] >= q[j].fi && a[i] <= q[j].se){
            s[i] += (abs(a[i] - q[j].fi) % 2 == 0 ? q[j].cost : -q[j].cost);
        }
        cout << s[i] << '\n';
    }
}
int32_t main()
{
    FastIO
    freopen("DUNES.INP", "r", stdin);
    freopen("DUNES.OUT", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> q[i].fi >> q[i].se >> q[i].cost;
    for(int i = 1; i <= m; i++){
        cin >> a[i];
    }

    xuli();
    return 0;
}
