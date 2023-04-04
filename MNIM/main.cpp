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

const int NM = 105;
int T, n;
int a[NM];
bool ok = true;

int main()
{
    FastIO
    freopen("MNIM.INP", "r", stdin);
    freopen("MNIM.OUT", "w", stdout);
    cin >> T;
    while(T--){
        cin >> n;
        ok = true;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            if(a[i] > 1) ok = false;
        }

        if(ok){
            if(n % 2 == 0) cout << 1 << '\n';
            else cout << -1 << '\n';
            continue;
        }

        int tmp = 0;
        for(int i = 1; i <= n; i++) tmp ^= a[i];
        cout << (tmp > 0 ? 1 : -1) << '\n';
    }
    return 0;
}
