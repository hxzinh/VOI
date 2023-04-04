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
int n, T, k;
int a[NM];

int main()
{
    FastIO
    freopen("ELECTION.INP", "r", stdin);
    freopen("ELECTION.OUT", "w", stdout);
    cin >> T;

    while(T--){
        cin >> n >> k;
        int MaxVal = -1;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            maximize(MaxVal, a[i]);
        }

        for(int i = 1; i <= n; i++) k -= MaxVal - a[i];
        if(k < 0) cout << "NO" << '\n';
        else if(k % n == 0) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}
