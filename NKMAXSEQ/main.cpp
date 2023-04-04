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

const int NM = 5e4 + 10;
int n, p;
int a[NM], s[NM];

void sub1(){
    for(int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];

    int res = -1;
    for(int i = 1; i <= n; i++){
        for(int j = n; j >= i; j--) if(s[j] - s[i - 1] >= p){
            maximize(res, j - i + 1);
            break;
        }
    }
    cout << res;
}
int32_t main()
{
    FastIO
    freopen("NKMAXSEQ.INP", "r", stdin);
    freopen("NKMAXSEQ.OUT", "w", stdout);
    cin >> n >> p;
    for(int i = 1; i <= n; i++) cin >> a[i];

    sub1();
    return 0;
}
