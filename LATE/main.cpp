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

const int NM = 3e5 + 10;
int Sub, n, k;
pii a[NM];
int en[NM], s[NM];
int cnt[NM];

bool check(int x, int p){
    if(p <= cnt[x - 2]) return true;
    else return false;
}
bool cmp(const pii &A, const pii &B){
    return A.fi > B.fi;
}
void xuli() {
    sort(a + 1, a + n + 1, cmp);
    for(int i = 1; i <= n; i++) cnt[i] = 0;
    for(int i = 1; i <= n; i++) {
        cnt[a[i].fi]++;
        s[a[i].fi] += en[i];
    }
    for(int i = 1; i <= n; i++) cnt[i] += cnt[i - 1];

    int numPerson = n + 1 - k;
    int l = 1, r = n, numWin = 0;
    while(l <= r) {
        int m = (l + r) >> 1;
        if(check(m, numPerson)){
            numWin = m;
            r = m - 1;
        } else l = m + 1;
    }

    int res = 0;
    sort(en + 1, en + n + 1);
    for(int i = 1; i <= numWin; i++) res += en[i];
    cout << res << '\n';
}
int32_t main()
{
    FastIO
    freopen("LATE.INP", "r", stdin);
    freopen("LATE.OUT", "w", stdout);
    cin >> Sub;
    while(Sub--){
        cin >> n >> k;
        for(int i = 1; i <= n; i++) {
            cin >> a[i].fi >> a[i].se;
            en[i] = a[i].se;
        }

        xuli();
    }
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
