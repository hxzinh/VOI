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
int n, k, maxPos = -1;
int phone[NM], s[NM];

void readfile(){
    freopen("BTS.INP", "r", stdin);
    freopen("BTS.OUT", "w", stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        int u, v;
        cin >> u >> v;
        phone[v] = u;
        maximize(maxPos, v);
    }
}
void xuli(){
    int res = 0, ans = 0;
    s[0] = phone[0];
    for(int i = 1; i <= maxPos; i++) s[i] = s[i - 1] + phone[i];
    if(2 * k >= maxPos) res = s[maxPos];
    else {
        res = s[2 * k];
        for(int i = 2 * k + 1; i <= maxPos; i++) maximize(res, s[i] - s[i - 2 * k - 1]);
    }
    cout << res;
}
int32_t main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
