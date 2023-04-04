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

const int NM = 5e3 + 10;
int n;
int a[NM], s[NM];

int main() {
    FastIO
    freopen("TWOSUM.INP", "r", stdin);
    freopen("TWOSUM.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

    s[0] = 0;
    for(int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];

    int res = 0;
    for(int i = 1; i < n; i++){
        for(int j = i; j < n; j++){
            int sum = s[j] - s[i - 1];
            if(sum > s[n] - s[j]) break;
            int l = j + 1, r = n, p = 0;
            while(l <= r){
                int m = (l + r) >> 1;
                if(s[m] - s[j] <= sum){
                    p = m;
                    l = m + 1;
                } else r = m - 1;
            }
            if(sum == s[p] - s[j]) res = max(res, p - i + 1);
        }
    }
    cout << res;
    return 0;
}
