#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define pii pair<int, int>
#define fi first
#define se second
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int MOD = 1e9 + 7;
int n;
ll cnt[1000005], d[1000005];
vector<pii> a[1000005];
vector<int> g;

int main()
{
    FastIO
    freopen("INP", "r", stdin);
    freopen("OUT", "w", stdout);
    cin >> n;

    for(ll i = 1; i <= n; i++){
        ll u; cin >> u;
        if(!d[u]) g.push_back(u);
        d[u]++;
    }

    for(int u = 1; u <= 1000000; u++) if(d[u]) {
        int tmp = u;
        for(ll i = 2; i * i <= u; i++) if(u % i == 0) {
            while(u % i == 0){
                cnt[i] += d[tmp];
                u /= i;
            }
        }
        if(u > 1) cnt[u] += d[tmp];
        u = tmp;
    }

    ll res = 1;
    for(int i = 2; i <= 1000000; i++) if(cnt[i]) {
        res = res * (cnt[i] + 1) % MOD;
        //cout << cnt[i] << '\n';
    }
    cout << res;
    return 0;
}
