#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define DOWN 1
#define RIGHT 0
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 2e3 + 10;
const int MOD = 998244353;
int n, m;
int rock[NM][NM][2], r[NM][NM], R[NM][NM], D[NM][NM], row[NM][NM], col[NM][NM], sumrow[NM][NM], sumcol[NM][NM];
char a[NM][NM];
int cnt = 0;


void backtrack(int x, int y){
    if(x > n || y > m) return;
    if(x == n && y == m){
        cnt++;
        return;
    }
    if(!rock[x + 1][y][1]) backtrack(x + 1, y);
    if(!rock[x][y + 1][0]) backtrack(x, y + 1);

    if(rock[x + 1][y][1] < n - x && rock[x + 1][y][1]){
        rock[x + 2][y][1]++;
        backtrack(x + 1, y);
        rock[x + 2][y][1]--;
    }
    if(rock[x][y + 1][0] < m - y && rock[x][y + 1][0]){
        rock[x][y + 2][0]++;
        backtrack(x, y + 1);
        rock[x][y + 2][0]--;
    }
    return;
}
void sub1(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++) if(a[i][j] == 'R') {
            rock[i][j][0] = rock[i][j][1] = 1;
            int u = i + 1, v = j + 1;
            while(u <= n && a[u][j] == 'R'){rock[i][j][1]++; u++;}
            while(v <= m && a[i][v] == 'R'){rock[i][j][0]++; v++;}
        }
    }

    backtrack(1, 1);
    cout << cnt;
}
void sub2doc(){
    for(int i = m; i >= 1; i--){
        r[1][i] = r[1][i + 1] + (a[1][i] == 'R');
        r[2][i] = r[2][i + 1] + (a[2][i] == 'R');
    }

    int numRock = 0;
    for(int i = 1; i <= m; i++){
        if(a[1][i + 1] == 'R') numRock++;
        if(numRock == m - i + 1) break;
        if(a[2][i] == '.' && r[2][i] == 0) cnt++;
    }
    cout << cnt;
}
void sub2ngang(){
    for(int i = n; i >= 1; i--){
        r[i][1] = r[i + 1][1] + (a[i][1] == 'R');
        r[i][2] = r[i + 1][2] + (a[i][2] == 'R');
    }

    int numRock = 0;
    for(int i = 1; i <= n; i++){
        if(a[i + 1][1] == 'R') numRock++;
        if(numRock == n - i + 1) break;
        if(a[i][2] == '.' && r[i][2] == 0) cnt++;
    }
    cout << cnt;
}
void prepare(){
    for(int i = n; i > 0; i--){
        for(int j = m; j > 0; j--){
            R[i][j] = R[i][j + 1] + (a[i][j] == 'R');
            D[i][j] = D[i + 1][j] + (a[i][j] == 'R');
        }
    }

    int l;
    for(int i = 1; i <= n; i++){
        l = 1;
        for(int j = 1; j <= m; j++){
            while(m - R[i][l + 1] < j) l++;
            row[i][j] = l;
        }
    }

    for(int j = 1; j <= m; j++){
        l = 1;
        for(int i = 1; i <= n; i++){
            while(n - D[l + 1][j] < i) l++;
            col[i][j] = l;
        }
    }
}
void full(){
    int zero, one;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(i == 1 && j == 1) zero = one = 1;
            else {
                zero = (sumrow[i][j - 1] - sumrow[i][row[i][j] - 1] + MOD) % MOD;
                one = (sumcol[i - 1][j] - sumcol[col[i][j] - 1][j] + MOD) % MOD;
            }
            sumrow[i][j] = (sumrow[i][j - 1] + one) % MOD;
            sumcol[i][j] = (sumcol[i - 1][j] + zero) % MOD;
        }
    }
    cout << (zero + one) % MOD;
}
int main()
{
    FastIO
    freopen("PUSHINGROCKS.INP", "r", stdin);
    freopen("PUSHINGROCKS.OUT", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) cin >> a[i][j];

    if(a[n][m] == 'R'){
        cout << 0;
        return 0;
    }
    if(n == 1 && m == 1){cout << 1; return 0;}

    prepare();
    full();
    return 0;
}
