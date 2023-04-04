#include <bits/stdc++.h>
#define int long long
#define INF 1e9
#define pii pair<int, int>
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e6 + 10;
int n;
int a[NM], h[NM];
int best[NM];
int result = -INF;
vector<pii> s;
bool s2 = true;

void sub1(){
    int res = -INF;
    for(int i = 1; i < n; i++)
        for(int j = i + 1; j <= n; j++) maximize(res, (a[i] + a[j]) * (j - i));
    cout << res;
}
void sub2(){
    int res = -INF;
    for(int i = 1; i < n; i++) maximize(res, (a[i] + a[n]) * (n - i));
    cout << res;
}
void dp(int u, int v, int l, int r){
    if(u > v) return;
    int m = (u + v) >> 1;

    pii good = make_pair(-INF, -1);
    for(int i = l; i <= r; i++){
        int tmp = (s[m].fi + a[i]) * abs(s[m].se - i);
        if(good.fi < tmp) good = make_pair(tmp, i);
        maximize(result, tmp);
    }

    dp(u, m - 1, l, good.se);
    dp(m + 1, v, good.se, r);
    return;
}
void full(){
    int m = s.size() - 1;
    dp(1, m, 1, n);
    cout << result;
}
int32_t main()
{
    FastIO
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] != i) s2 = false;
    }

    s.push_back({0, 0});
    for(int i = 1; i <= n; i++) h[i] = max(a[i], h[i - 1]);
    for(int i = 1; i <= n; i++) if(a[i] == h[i])
        s.push_back(make_pair(h[i], i));

    if(s2) sub2();
    else full();
    return 0;
}
