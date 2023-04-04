#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define pii pair<int, int>
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

const int NM = 3e6 + 10;
int n;
int a[NM], cnt[NM], dem[NM];
bool cx[NM];

void xuli() {
    for(int i = 1; i <= 3000000; i++) if(cx[i]) {
        for(int j = i + i; j <= 3000000; j += i) if(cx[j]) {
            cnt[i]++;
            dem[j]++;
        }
    }

    int res = 0;
    for(int i = 1; i <= 3000000; i++) if(cnt[i] && dem[i])
        res += cnt[i] * dem[i];

    cout << res;
}
int32_t main()
{
    FastIO
    freopen("CLIQUE3.INP", "r", stdin);
    freopen("CLIQUE3.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        cx[a[i]] = true;
    }

    xuli();
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
