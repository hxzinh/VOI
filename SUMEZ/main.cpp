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
int n, m;
int a[NM], s[NM];

int32_t main()
{
    FastIO
    freopen("SUMEZ.INP", "r", stdin);
    freopen("SUMEZ.OUT", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];

    s[0] = 0;
    for(int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
    while(m--){
        int L, R;
        cin >> L >> R;
        cout << s[R] - s[L - 1] << '\n';
    }
    return 0;
}
