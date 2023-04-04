#include <bits/stdc++.h>
#define int long long
#define INF 1e9
#define ALL(v) (v).begin(), (v).end()
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e5 + 10;
int n, m, k;
vector<int> X, Y;

int32_t main()
{
    FastIO
    freopen("TABLEDEL.INP", "r", stdin);
    freopen("TABLEDEL.OUT", "w", stdout);
    cin >> n >> m >> k;
    for(int i = 1; i <= k; i++){
        int u, v;
        cin >> u >> v;
        X.push_back(u);
        Y.push_back(v);
    }

    sort(ALL(X)); sort(ALL(Y));
    X.resize(unique(ALL(X)) - X.begin());
    Y.resize(unique(ALL(Y)) - Y.begin());
    int res = X.size() * Y.size();
    cout << res;
    return 0;
}
