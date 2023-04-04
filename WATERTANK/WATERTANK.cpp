#include <bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define fi first
#define se second
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NMAX = 1e5 + 10;
int n;
int qMax[NMAX], qMin[NMAX];
pii a[NMAX];

bool cmp(const pii &A, const pii &B){
    return A.fi < B.fi;
}
void xuli(){
    sort(a + 1, a + n + 1, cmp);
    //for(int i = 1; i <= n; i++) cout << a[i].fi << " " << a[i].se << '\n';
    memset(qMin, INF, sizeof qMin);
    for(int i = n; i > 0; i--) qMin[i] = min(qMin[i + 1], a[i].se);
    for(int i = n; i > 0; i--) qMax[i] = max(qMax[i + 1], a[i].se);

    int res = 0;
    for(int i = 1; i < n; i++){
        int ans = a[i].fi * max(abs(a[i].se - qMin[i + 1]) - 1, abs(a[i].se - qMax[i + 1]) - 1);
        maximize(res, ans);
    }
    cout << res;
}
void sub1(){
    int res = 0;
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            maximize(res, min(a[i].fi, a[j].fi) * (abs(i - j) - 1));
        }
    }
    cout << res;
}
int32_t main()
{
    FastIO
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i].fi;
        a[i].se = i;
    }

    if(n <= 1000) sub1();
    else xuli();
    return 0;
}
