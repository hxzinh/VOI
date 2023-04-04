#include <bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define popcount(x) __builtin_popcount(x)
#define set(x) setprecision(x)
#define MASK(x) (1LL << (x))
#define BIT(x, i) ((x) >> (i) & 1)
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 3e5 + 10;
int n, num, numPine, numBam;
int sPine[NM], sBam[NM];
pii a[NM];

bool cmp(const pii &A, const pii &B){
    return A.fi < B.fi;
}
void xuli(){
    sort(a + 1, a + n + 1, cmp);

    for(int i = 1; i <= n; i++){
        sPine[i] = sPine[i - 1] + (a[i].se == 1);
        sBam[i] = sBam[i - 1] + (a[i].se == 2);
    }

    int res = INF;
    for(int i = 1; i <= n; i++){
        if(sPine[i] < numPine || sBam[i] < numBam) continue;
        int l = 1, r = n, pos = 1;
        while(l <= r){
            int m = (l + r) >> 1;
            int curPine = sPine[i] - sPine[m - 1];
            int curBam = sBam[i] - sBam[m - 1];
            if(curPine >= numPine && curBam >= numBam){
                pos = m;
                l = m + 1;
            } else r = m - 1;
        }
        minimize(res, a[i].fi - a[pos].fi);
    }
    cout << (res < INF ? res : -1);
}
int32_t main()
{
    FastIO
    freopen("MINROAD.INP", "r", stdin);
    freopen("MINROAD.OUT", "w", stdout);
    cin >> n >> numPine >> numBam;
    for(int i = 1; i <= n; i++){
        cin >> a[i].fi >> a[i].se;
    }

    xuli();
    return 0;
}
