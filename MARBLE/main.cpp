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

const int NM = 5e5 + 10;
const int MOD = 998244353;
int n, k;
int a[NM], f[1005][1005][2];

void add(int &a, int b){
    if(a + b >= MOD) a += b - MOD;
    else a += b;
}
void sub1(){
    for(int i = 1; i <= n; i++) f[0][i][0] = f[0][i][1] = 1;

    for(int i = 0; i < k; i++){
        for(int j = 1; j <= n; j++){
            add(f[i + 1][j][0], f[i][j][0]);
        }
    }
}
int main()
{
    FastIO
    freopen("MARBLE.INP", "r", stdin);
    freopen("MARBLE.OUT", "w", stdout);
    cin >> n >> k;
    return 0;
}
