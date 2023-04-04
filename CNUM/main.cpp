#include <bits/stdc++.h>
#define int long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e6 + 10;
int n;
int a[NM], cnt[NM], s[NM];

void readfile(){
    freopen("INP", "r", stdin);
    freopen("OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
}
void xuli(){
    for(int i = n; i >= 1; i--) cnt[i] = cnt[i + 1] + (a[i] == 1);
    for(int i = 1; i <= n; i++) s[i] = s[i - 1] + (a[i] == 2);

    int res = INF;
    for(int i = 1; i <= n; i++) minimize(res, s[i] + cnt[i + 1]);
    cout << res;
}
int32_t main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
