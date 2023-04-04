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

ll n;
vector<pair<ll, ll>> ans;

int main()
{
    FastIO
    cin >> n;

    for(ll i = 2; i * i <= n; i++){
        if(n % i == 0){
            ans.push_back({i, 0});
            while(n % i == 0){
                n /= i;
                ans[ans.size() - 1].se++;
            }
        }
    }
    if(n > 1) ans.push_back({n, 1});

    for(ll i = 0; i < ans.size(); i++){
        cout << ans[i].fi << "^" << ans[i].se << " ";
        if(i < ans.size() - 1) cout << "*" << " ";
    }
    return 0;
}
