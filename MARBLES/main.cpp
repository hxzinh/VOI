#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f3f3f3f3f
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
int numRed, numBlue, numYellow;
ll a[NM], b[NM], c[NM];

ll getSum(ll x, ll y, ll z) {
    return (x - y) * (x - y) + (y - z) * (y - z) + (z - x) * (z - x);
}
void sub1() {
    ll res = INF;
    for(int i = 1; i <= numRed; i++) {
        for(int j = 1; j <= numBlue; j++) {
            for(int k = 1; k <= numYellow; k++) {
                minimize(res, getSum(a[i], b[j], c[k]));
            }
        }
    }

    cout << res;
}
int findBlue(ll val){
    ll L  = -1, R = -1;
    int l = 1, r = numBlue;

    while(l <= r){
        int m = (l + r) >> 1;
        if (b[m] <= val) {
            L = m;
            l = m + 1;
        } else r = m - 1;
    }

    l = 1, r = numBlue;
    while(l <= r){
        int m = (l + r) >> 1;
        if (b[m] >= val) {
            R = m;
            r = m - 1;
        } else l = m + 1;
    }
    if(L == -1 && R == -1) return -1;
    if(L != -1 && R == -1) return L;
    if(L == -1 && R != -1) return R;
    if(val - b[L] <= b[R] - val) return L;
    return R;
}
pii findYellow(ll val){
    ll L = -1, R = -1;
    int l = 1, r = numYellow;

    while(l <= r){
        int m = (l + r) >> 1;
        if (c[m] <= val) {
            L = m;
            l = m + 1;
        } else r = m - 1;
    }

    l = 1, r = numYellow;
    while (l <= r){
        int m = (l + r) >> 1;
        if (c[m] >= val) {
            R = m;
            r = m - 1;
        } else l = m + 1;
    }
    return make_pair(L, R);
}
void xuli() {
    ll res = INF;

    pii val = {0, 0};
    vector<ll> ans;
    for(int i = 1; i <= numRed; i++) {
        val.fi = a[i];
        val.se = b[findBlue(a[i])];
        pii fA = findYellow(val.fi);
        pii fB = findYellow(val.se);
        if(posA.fi != -1) ans.push_back(c[posA.first]);
        if(posA.se != -1) ans.push_back(c[posA.second]);
        if(fB.fi != -1) ans.push_back(c[fB.first]);
        if(fB.se != -1) ans.push_back(c[fB.second]);
        for(ll x : ans)
            minimize(res, getSum(val.fi, val.se, x));
        ans.clear();
    }

    cout << res;
}
void sub2() {
    ll res = INF;
    for(int i = 1; i <= numRed; i++) {
        for(int j = 1; j <= numBlue; j++) {
            int l = 1, r = numYellow, k = numYellow;
            while(l <= r) {
                int m = (l + r) >> 1;
                if(c[m] <= (a[i] + b[j]) / 2) {
                    k = m;
                    l = m + 1;
                } else r = m - 1;
            }
            minimize(res, getSum(a[i], b[j], c[k]));
            if(k - 1 > 0) minimize(res, getSum(a[i], b[j], c[k - 1]));
            if(k + 1 <= numYellow) minimize(res, getSum(a[i], b[j], c[k + 1]));
        }
    }

    cout << res;
}
int32_t main()
{
    FastIO
    freopen("MARBLES.INP", "r", stdin);
    freopen("MARBLES.OUT", "w", stdout);
    cin >> numRed >> numBlue >> numYellow;
    for(int i = 1; i <= numRed; i++) cin >> a[i];
    for(int i = 1; i <= numBlue; i++) cin >> b[i];
    for(int i = 1; i <= numYellow; i++) cin >> c[i];

    sort(a + 1, a + numRed + 1);
    sort(b + 1, b + numBlue + 1);
    sort(c + 1, c + numYellow + 1);
    c[numYellow + 1] = INF;

    int m = max({numRed, numBlue, numYellow});
    if(m <= 100) sub1();
    else if(m <= 1000) sub2();
    else xuli();
    return 0;
}

