#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 305;
const int MOD = 1e9 + 7;
int n, k, l, r;
int a[NM], f[NM][NM][NM];

void add(int &a, int b){
    if(a + b > MOD) a += b - MOD;
    else a += b;
}
void xuli() {
    memset(f, 0, sizeof f);
    f[0][0][0] = 1;

    for (int x = 0; x <= n; ++x)
        for (int y = 0; y <= k; ++y)
            for (int z = 0; z <= min(r, 255); ++z) if (f[x][y][z] > 0) {
                add(f[x + 1][y][z], f[x][y][z]);
                add(f[x + 1][y + 1][z | a[x + 1]], f[x][y][z]);
            }

    int ans = 0;
    for (int i = l; i <= min(r, 255); ++i) if (i % 3 == 0) add(ans, f[n][k][i]);
    cout << ans;
}


int main()
{
    FastIO
    freopen("ORMATH.INP", "r", stdin);
    freopen("ORMATH.OUT", "w", stdout);
    cin >> n >> k >> l >> r;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    xuli();
    return 0;
}
