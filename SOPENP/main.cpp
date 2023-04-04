#include <bits/stdc++.h>
#define int long long
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

const int NM = 1111111;
int n, L, R;
int a[NM], cnt[NM];

int xuli(int x){
    if(x == 0) return 0;
    memset(cnt, 0, sizeof cnt);

    int res = 0, ans = 0, v = 0;
    for(int i = 1; i <= n; i++){
        if(ans <= x && v != n + 1)
        for(v = v + 1; v <= n; v++){
            if(cnt[a[v]] > 0) cnt[a[v]]++;
            else {
                ans++;
                cnt[a[v]] = 1;
            }
            if(ans > x) break;
        }
        res += v - i;
        cnt[a[i]]--;
        if(!cnt[a[i]]) ans--;
    }
    return res;
}
int32_t main()
{
    FastIO
    freopen("SOPENP.INP", "r", stdin);
    freopen("SOPENP.OUT", "w", stdout);
    cin >> n >> L >> R;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    vector<int> val;
    for(int i = 1; i <= n; i++) val.push_back(a[i]);
    sort(ALL(val));
    val.resize(unique(ALL(val)) - val.begin());
    for(int i = 1; i <= n; i++) a[i] = lower_bound(ALL(val), a[i]) - val.begin() + 1;


    cout << xuli(R) -  xuli(L - 1);
    return 0;
}
