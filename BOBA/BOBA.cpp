#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define mp make_pair
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define popcount(x) __builtin_popcount(x)
#define setp(x) setprecision(x)
#define MASK(x) (1LL << (x))
#define BIT(x, i) ((x) >> (i) & 1)
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e5 + 10;
const int MAX = 2e3 + 10;
int n;
ll a[NM], cnt[NM], s[NM];
vector<ll> vec;

void sub123() {
    sort(a + 1, a + n + 1);

    ll res = 0;
    for(int i = 1; i <= n; i++) {
        res += s[a[i]];
        for(int j = 0; j <= 1000; j++) if(cnt[j]) {
            s[j + a[i]] += cnt[j];
        }
        cnt[a[i]]++;
    }
    cout << res;
}
void xuli() {
    for(int i = 1; i <= n; i++) {
        for(int sum = 0; sum <= 2000; sum++) {
            if(cnt[sum]) s[sum + a[i]] += cnt[sum];
        }
        if(!cnt[a[i]]) vec.push_back(a[i]);
        cnt[a[i]]++;
    }
    sort(ALL(vec));

    for(int sum = 0; sum <= 2000; sum++) if(s[sum]) cout << sum << " " << s[sum] << '\n';

    ll res = 0;
    for(int i = 0; i < vec.size(); i++) {
        res += s[vec[i]];
        for(int sum = 0; sum <= 2000; sum++) if(sum >= vec[i]) {
            if(cnt[sum - vec[i]]) s[sum] -= cnt[vec[i]] * cnt[sum - vec[i]];
        }
        cnt[vec[i]] = 0;
    }

    cout << res;
}
int32_t main()
{
    FastIO
    freopen("BOBA.INP", "r", stdin);
    freopen("BOBA.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

    sub123();
    return 0;
}

/* Author: hxzinh */

/*
-----code ko bug-----code ko bug-----code ko bug--------------

          _.-/`)
         // / / )
      .=// / / / )
     //`/ / / / /
    // /     ` /
   ||         /
    \\       /
     ))    .'
    //    /
         /
*/
