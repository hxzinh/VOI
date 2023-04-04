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

const int NM = 1e5 + 10;
int n;
int a[NM], cnt[NM];

void xuli() {
    int res = 0;
    for(int i = n; i > 0; i--) {
        vector<int> prime;
        int tmp = a[i], curLen = 0;
        for(int j = 2; j * j <= tmp; j++) if(tmp % j == 0) {
            while(tmp % j == 0) tmp /= j;
            maximize(curLen, cnt[j]);
            prime.push_back(j);
        }
        if(tmp > 1) {
            maximize(curLen, cnt[tmp]);
            prime.push_back(tmp);
        }

        for(int u : prime) maximize(cnt[u], curLen + 1);
        maximize(res, curLen + 1);
    }

    cout << res;
}
int32_t main()
{
    FastIO
    freopen("GOODSEQ.INP", "r", stdin);
    freopen("GOODSEQ.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

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
