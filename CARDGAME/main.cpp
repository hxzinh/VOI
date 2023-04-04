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
int n, k;
int a[NM], s[NM];

int32_t main()
{
    FastIO
    freopen("CARDGAME.INP", "r", stdin);
    freopen("CARDGAME.OUT", "w", stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];

    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
    cout << s[k] << " " << s[n - 1] - s[n - k - 1];
    return 0;
}
