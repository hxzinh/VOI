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

const int NM = 1e4 + 10;
int n, m;
int a[NM];

void xuli(){
    sort(a + 1, a + n + 1);
    int res = 0;
    for(int i = 1; i <= n - 2; i++){
        int u = i + 1, v = u + 1, sum = a[i] + a[u] + a[v];
        while(u < v && v <= n){
            if(sum <= m){
                maximize(res, sum);
                if(u < v - 1){
                    u++;
                    sum += a[u] - a[u - 1];
                } else {
                    v++;
                    sum += a[v] - a[v - 1];
                }

            } else {
                v++;
                sum += a[v] - a[v - 1];
            }
        }
    }
    cout << res;
}
int main()
{
    FastIO
    freopen("NDCCARD.INP", "r", stdin);
    freopen("NDCCARD.OUT", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];

    xuli();
    return 0;
}
