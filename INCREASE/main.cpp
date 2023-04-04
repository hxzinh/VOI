#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define MASK(x) (1LL << (x))
#define BIT(i, x) ((x) >> (i) & 1)
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int MOD = 1e9 + 7;
const int NM = 2e3 + 10;
int n;
int ans = 0;
int a[NM];

void backtrack(int x, int mask){
    if(x > n){
        int max1 = -1, max2 = -1;
        if(__builtin_popcount(mask) <= 1) return;
        for(int i = 1; i <= n; i++) if(BIT(i - 1, mask)){
            if(a[i] > max1){
                max1 = a[i];
                continue;
            }
            if(a[i] > max2){
                max2 = a[i];
                continue;
            }
            return;
        }
        ans++;
        return;
    }
    int newMask = mask | MASK(x - 1);
    backtrack(x + 1, newMask);
    backtrack(x + 1, mask);
    return;
}
int main()
{
    FastIO
    freopen("INCREASE.INP", "r", stdin);
    freopen("INCREASE.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

    backtrack(1, 0);
    cout << ans;
    return 0;
}
