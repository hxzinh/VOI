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

const int NM = 1e5 + 10;
const int NUMBLOCK = 320;
int n, k;
int a[NM], id[NM], L[505], R[505], sz[505];
int mxId[505][NM];
bool cx[NM], ok[NM];

void sub1() {
    for(int i = 0; i < n; i++) {
        vector<pii> vec;
        int id = 0;
        for(int j = 0; j < n; j++) if(!cx[j]) {
            if(id % k == 0) vec.push_back({a[j], j});
            id++;
        }

        if(!vec.size()) break;

        sort(ALL(vec), [](const pii A, const pii B){
             return (A.fi == B.fi) ? A.se < B.se : A.fi > B.fi;
        });
        pii u = *vec.begin();

        cx[u.se] = true;
        cout << u.fi << '\n';
    }
}
void update(int u, int x) {
    sz[u]--;
    ok[x] = true;
    for(int i = 0; i <= NUMBLOCK; i++) mxId[u][i] = n;

    int idx = 0;
    for(int i = L[u]; i <= R[u]; i++) if(!ok[i]) {
        int curId = mxId[u][idx % k];
        if(a[curId] < a[i]) mxId[u][idx % k] = i;
        idx++;
    }
}
void xuli() {
    int nBlock = n / NUMBLOCK + (n % NUMBLOCK != 0);

    for(int i = 1; i <= nBlock; i++)
        for(int j = 0; j < k; j++) mxId[i][j] = n;

    R[0] = -1;
    for(int i = 1; i <= nBlock; i++) {
        L[i] = R[i - 1] + 1;
        R[i] = min(i * NUMBLOCK - 1, n - 1);

        sz[i] = R[i] - L[i] + 1;
        int idx = 0;
        for(int j = L[i]; j <= R[i]; j++) {
            id[j] = i;

            int curId = mxId[i][idx % k];
            if(a[curId] < a[j]) mxId[i][idx % k] = j;
            idx++;
        }
    }

    for(int i = 0; i < n; i++) {
        int sumBlock = 0, res = 0;
        pii trace;

        for(int j = 1; j <= nBlock; j++) if(sz[j]) {
            int curId = mxId[j][(k - sumBlock % k) % k];
            if(maximize(res, a[curId]))
                trace = {j, curId};

            sumBlock += sz[j];
        }


        cout << res << '\n';

        update(trace.fi, trace.se);
    }
}
int32_t main()
{
    FastIO
    freopen("KR.INP", "r", stdin);
    freopen("KR.OUT", "w", stdout);
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> a[i];

    a[n] = 0;

    if(n <= 1000) sub1();
    else xuli();
    return 0;
}


