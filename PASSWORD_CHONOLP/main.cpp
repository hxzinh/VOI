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

int n;
string s;
int S = 0;
int k[20];
char a[20];
vector<int> val;

void xuli(){
    sort(a + 1, a + n + 1);
    do {
        int sum = 0;
        if(a[1] == '0') continue;
        bool ok = true;
        for(int i = 1; i <= n; i++){
            if(int32_t(a[i] - '0') != k[i]) sum = sum * 10 + int32_t(a[i] - '0');
            else {
                ok = false;
                break;
            }
        }
        if(ok) val.push_back(sum);
    } while(next_permutation(a + 1, a + n + 1));

    int res = INF, ans = -1;
    for(int u : val) if(minimize(res, abs(u - S))) ans = u;
    cout << ans;
}
int32_t main()
{
    FastIO
    freopen("PASSWORD.INP", "r", stdin);
    freopen("PASSWORD.OUT", "w", stdout);
    cin >> s;
    n = s.size();
    for(int i = 1; i <= n; i++) cin >> k[i];

    s = '#' + s;
    for(int i = 1; i <= n; i++) a[i] = s[i];

    for(int i = 1; i <= n; i++) S = S * 10 + int32_t(a[i] - '0');

    xuli();
    return 0;
}
