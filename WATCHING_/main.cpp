#include <bits/stdc++.h>
#define int long long
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
int n, m, bedTime, k;
int a[NM], b[NM];

void xuli() {
    vector<int> A, B;
    for(int i = 1; i <= n; i++) A.push_back(a[i]);
    for(int i = 1; i <= m; i++) B.push_back(b[i]);
    A.push_back(bedTime); B.push_back(bedTime);

    sort(ALL(A)); sort(ALL(B));

    int curTime = 0, curStat = 0;
    int resAve = 0, resBat = 0;
    bool ok = false;

    int u = 1, v = 1;
    while(curTime <= bedTime) {
        if(ok == 0) {
            while(a[u] <= curTime) u++;

        }
    }

    cout << resAve << " " << resBat;
}
int32_t main()
{
    FastIO
    freopen("WATCHING.INP", "r", stdin);
    freopen("WATCHING.OUT", "w", stdout);
    cin >> n >> m >> bedTime >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= m; i++) cin >> b[i];
    a[n + 1] = INF; b[m + 1] = INF;

    xuli();
    return 0;
}
