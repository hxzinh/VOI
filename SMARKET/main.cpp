#include <bits/stdc++.h>
#define int long long
#define INF 1e9
#define ii pair<int, int>
#define fi first
#define se second
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e5 + 10;
int n, q;
int a[NM], s[NM], ans[NM];
ii p[NM];

void readfile(){
    freopen("INP", "r", stdin);
    freopen("OUT", "w", stdout);
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= q; i++){
        cin >> p[i].fi >> p[i].se;
    }
}
void sub1(){
    for(int i = 1; i <= q; i++){
        int res = 0;
        for(int j = p[i].se; j <= n; j++){
            if(p[i].fi >= a[j]){
                res++;
                p[i].fi -= a[j];
            }
        }
        cout << res << '\n';
    }
}
int getCost(int x, int cast){
    int res = 0;
    while(true){
        int l = x, r = n, ans = 0;
        while(l <= r){
            int mid = (l + r) >> 1;
            if(s[mid] - s[x - 1] <= cast){
                ans = mid;
                l = mid + 1;
            }else r = mid - 1;
        }
        if(ans != 0){
            res += ans - x + 1;
            cast -= (s[ans] - s[x - 1]);
        }
        x = max(ans + 1, x + 1);
        if(cast <= 0 || x > n) break;
    }
    return res;
}
void full(){
    s[0] = 0;
    for(int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
    for(int i = 1; i <= q; i++){
        cout << getCost(p[i].se, p[i].fi) << '\n';
    }
}
int32_t main()
{
    FastIO
    readfile();
    if(n <= 1000) sub1();
    else full();
    return 0;
}
