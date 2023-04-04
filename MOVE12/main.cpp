#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
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

const int NM = 1e4 + 10;
int n;
pii a[NM];
bool cx[NM];
vector<int> L, R;

bool check(int x){
    L.clear(); R.clear();
    for(int i = 1; i <= n; i++){
        int t = x / a[i].se;
        L.push_back(a[i].fi - t);
        R.push_back(a[i].fi + t);
    }
    sort(ALL(L));
    sort(ALL(R));
    for(int i = 0; i < n; i++){
        if(L[i] > i + 1 || R[i] < i + 1) return false;
    }
    return true;
}
bool cmp(const pii &A, const pii &B){
    return (A.fi == B.fi ? A.se > B.se : A.fi < B.fi);
}
void xuli(){
    int l = 0, r = INF, res = INF;
    while(l <= r){
        int m = (l + r) >> 1;
        if(check(m)){
            res = m;
            r = m - 1;
        } else l = m + 1;
    }
    cout << res;
}
int main()
{
    FastIO
    freopen("MOVE12.INP", "r", stdin);
    freopen("MOVE12.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i].fi >> a[i].se;

    xuli();
    return 0;
}
