#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

int n, m;
ll f[50][50];

int main()
{
    FastIO
    cin >> n >> m;

    memset(f, 0, sizeof f);
    f[0][0] = 1;

    for(int i = 0; i < n; i++){
        for(int j = 0; j <= m; j++) if(f[i][j]) {
            for(int u = 0; u <= m - j; u++) f[i + 1][j + u] += f[i][j];
        }
    }

    cout << f[n][m];
    return 0;
}
