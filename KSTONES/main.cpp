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
int a[NM], dp[NM];

int32_t main()
{
    FastIO
    freopen("KSTONES.INP", "r", stdin);
    freopen("KSTONES.OUT", "w", stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = 1; i <= k; i++){
        for(int j = 1; j <= n; j++) if(i >= a[j]){
            if(!dp[i - a[j]]) dp[i] = 1;
        }
    }
    cout << (dp[k] ? "First" : "Second");
    return 0;
}
