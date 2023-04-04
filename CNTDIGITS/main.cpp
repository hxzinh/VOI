#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e5 + 10;
int n, p;
int f[NM][105][3], b[NM];
string a;

void readfile(){
    freopen("DIGITS.INP", "r", stdin);
    freopen("DIGITS.OUT", "w", stdout);
    cin >> p;
    cin >> a;
    a = ' ' + a;
    n = a.length() - 1;

    for(int i = 1; i <= n; i++) a[i] -= '0';
    for(int i = 1; i <= n; i++) b[i] = int(a[i]);
    memset(f, -1, sizeof(f));
}
void xuli(){
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= p; j++)
            for(int k = 0; k < 3; k++) f[i][j][k] = -1;

    f[0][0][0] = 0;
    for(int i = 0; i < n; i++){
        for(int r = 0; r < p; r++){
            for(int j = 0; j < 3; j++) if(f[i][r][j] >= 0) {
                if(j <= 0) maximize(f[i + 1][0][0], f[i][r][j]);
                if(j <= 1) maximize(f[i + 1][(10 * r + a[i + 1]) % p][1], f[i][r][j] + 1);
                if(r == 0) maximize(f[i + 1][0][2], f[i][r][j]);
            }
        }
    }

    int res = max(f[n][0][1], f[n][0][2]);
    cout << (res <= 0 ? -1 : res);
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
