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

const int NM = 1e6 + 10;
int n, m;
int a[NM];
bool cx[NM];
vector<int> Prime;

void xuli(){
    cx[1] = true;
    for(int i = 2; i <= 1000; i++){
        for(int j = i * i; j <= 1000000; j += i) cx[j] = true;
    }
    for(int i = 1; i <= 1000000; i++) if(!cx[i]) Prime.push_back(i);

    for(int i = 1; i <= n; i++){
        int u = sqrt(a[i]);
        if(u * u == a[i] && !cx[u]) cout << 1 << '\n';
        else cout << 0 << '\n';
    }
}
int32_t main()
{
    FastIO
    freopen("THREE.INP", "r", stdin);
    freopen("THREE.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

    xuli();
    return 0;
}
