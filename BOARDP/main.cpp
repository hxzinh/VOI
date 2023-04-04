#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 105;
int n;
int res = INF, dem = 0;
int a[NM][NM], b[NM][NM];
char s[NM][NM], c[NM][NM];

void readfile(){
    freopen("BOARD.INP", "r", stdin);
    freopen("BOARD.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
            s[i][j] = a[i][j] + '0';
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> b[i][j];
            c[i][j] = b[i][j] + '0';
        }
    }
}
void backtrack(int x, int y){
    if(x >= n || y > n || dem > 0){
        int cnt = 0;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++) cnt += (a[i][j] == b[i][j]);
        maximize(res, cnt);
        return;
    }
    dem++;
    for(int i = 1; i <= n; i++) swap(a[i][y], a[i][y + 1]);
    backtrack(1, y + 1);
    for(int i = 1; i <= n; i++) a[x][i] = a[x][i] ^ 1;
    backtrack(x + 1, 1);
    for(int i = 1; i <= n; i++) swap(a[i][y], a[i][y + 1]);
    backtrack(x + 1, 1);
    for(int i = 1; i <= n; i++) a[x][i] = a[x][i] ^ 1;
    dem--;
    return;
}
void sub1(){
    backtrack(1, 1);
    cout << res;
}
int main()
{
    FastIO
    readfile();
    sub1();
    return 0;
}
