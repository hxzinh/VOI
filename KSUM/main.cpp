#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

int n, k;
ll a[1000005], cnt[1000005];

int main()
{
    FastIO
    cin >> n >> k;
    memset(cnt, 0, sizeof cnt);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        cnt[a[i]]++;
    }

    ll res = 0;
    for(int i = 1; i < k; i++) if(cnt[i] && cnt[k - i]) {
        if(i == k - i) res += cnt[i] * (cnt[i] - 1);
        else res += cnt[i] * cnt[k - i];
    }
    cout << res / 2;
    return 0;
}
