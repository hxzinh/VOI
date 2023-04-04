#include <bits/stdc++.h>
#define int long long
#define INF 1e18
#define ALL(v) (v).begin(), (v).end()
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 100 + 10;
int n, m, r, c, len;
int b[NM][NM], f[NM][NM];
char star[NM][NM];
string k[NM][NM], a[NM];

void readfile(){
    freopen("SKYNIGHT.INP", "r", stdin);
    freopen("SKYNIGHT.OUT", "w", stdout);
    cin >> r >> c >> n >> m;
    len = (c % 6 == 0 ? c / 6 : c / 6 + 1);
    for(int i = 1; i <= r; i++) cin >> a[i];
    for(int i = 1; i <= r; i++) a[i] = ' ' + a[i];
}
int change(char x){
    int ans = 0;
    if(x >= '0' && x <= '9') ans = x - '0';
    else if(x >= 'a' && x <= 'z') ans = x - 'a' + 36;
    else if(x >= 'A' && x <= 'Z') ans = x - 'A' + 10;
    else ans = (x == '#' ? 62 : 63);
    return ans;
}
string toBinary(int x){
    string res = "";
    while(x != 0){
        int u = x % 2;
        res = res + char(u + '0');
        x /= 2;
    }
    while(res.length() < 6) res = res + '0';
    return res;
}
void xuli(){
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= len; j++){
            b[i][j] = change(a[i][j]);
            int u = b[i][j];
            k[i][j] = toBinary(u);
        }
    }

    for(int i = 1; i <= r; i++){
        int cnt = 1;
        for(int j = 1; j <= len; j++){
            for(int u = 0; u < k[i][j].length(); u++){
                if(cnt > c) break;
                star[i][cnt] = (k[i][j][u] == '1' ? '*' : '.');
                ///cout << star[i][cnt];
                cnt++;
            }
        }
    }

    for(int i = 1; i <= r; i++) f[i][0] = 0;
    for(int i = 1; i <= c; i++) f[0][i] = 0;

    for(int i = 1; i <= r; i++)
        for(int j = 1; j <= c; j++) f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1] + (star[i][j] == '*');

    int res = -1;
    for(int i = n; i <= r; i++){
        for(int j = m; j <= c; j++){
            int numStar = f[i][j] - f[i - n][j] - f[i][j - m] + f[i - n][j - m];
            maximize(res, numStar);
        }
    }
    cout << res;
}
int32_t main(){
    FastIO
    readfile();
    xuli();
    return 0;
}
