#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 5010;
int n, m, r, c, len;
int f[5010][5010];

int toNum(char x){
    int ans = 0;
    if(x >= '0' && x <= '9') ans = x - '0';
    else if(x >= 'a' && x <= 'z') ans = x - 'a' + 36;
    else if(x >= 'A' && x <= 'Z') ans = x - 'A' + 10;
    else ans = (x == '#' ? 62 : 63);
    return ans;
}
void readfile(){
    freopen("SKYNIGHT.INP", "r", stdin);
    freopen("SKYNIGHT.OUT", "w", stdout);
    cin >> r >> c >> n >> m;
    len = (c % 6 == 0 ? c / 6 : c / 6 + 1);
    for(int i = 1; i <= r; i++){
        string a; cin >> a;
        for(int j = 0; j < a.size(); j++){
            int u = j * 6;
            int x = toNum(a[j]);
            while(x != 0){
                u++;
                f[i][u] = x % 2;
                x /= 2;
            }
        }
    }
}
void xuli(){
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++) f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1] + f[i][j];
    }

    int res = 0;
    for(int i = n; i <= r; i++){
        for(int j = m; j <= c; j++){
            int numStar = f[i][j] - f[i - n][j] - f[i][j - m] + f[i - n][j - m];
            maximize(res, numStar);
        }
    }
    cout << res;
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
