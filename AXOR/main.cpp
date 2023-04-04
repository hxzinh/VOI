#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define pll pair<long long, long long>
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

const int NM = 1e6 + 10;
int n, q;
int a[NM], cnt[50][2];

int query() {
    int ans = 0;
    for(int i = 30; i >= 0; i--) {
        if(cnt[i][0] && cnt[i][1]) return -1;
        if(cnt[i][1]) ans ^= MASK(i);
    }

    return ans;
}
void xuli() {

    for(int j = 1; j < n; j++)
    {
        for(int i = 30; i >= 0; i--) {
            if(BIT(a[j], i) != BIT(a[j + 1], i)) {
                if(BIT(a[j], i)) cnt[i][1]++;
                else cnt[i][0]++;
                break;
            }
        }
    }

    cout << query() << '\n';

    while(q--) {
        int u, x;
        cin >> u >> x;

        if(u < n)
        for(int i = 30; i >= 0; i--) {
            if(BIT(a[u], i) != BIT(a[u + 1], i)) {
                if(BIT(a[u], i)) cnt[i][1]--;
                else cnt[i][0]--;
                break;
            }
        }

        if(u > 1)
        for(int i = 30; i >= 0; i--) {
            if(BIT(a[u], i) != BIT(a[u - 1], i)) {
                if(BIT(a[u], i)) cnt[i][0]--;
                else cnt[i][1]--;
                break;
            }
        }

        a[u] = x;

        if(u < n)
        for(int i = 30; i >= 0; i--) {
            if(BIT(a[u], i) != BIT(a[u + 1], i)) {
                if(BIT(a[u], i)) cnt[i][1]++;
                else cnt[i][0]++;
                break;
            }
        }

        if(u > 1)
        for(int i = 30; i >= 0; i--) {
            if(BIT(a[u], i) != BIT(a[u - 1], i)) {
                if(BIT(a[u], i)) cnt[i][0]++;
                else cnt[i][1]++;
                break;
            }
        }

        cout << query() << '\n';
    }
}
int32_t main()
{
    FastIO
    freopen("AXOR.INP", "r", stdin);
    freopen("AXOR.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    cin >> q;

    xuli();
    return 0;
}

/* Author: hxzinh */

