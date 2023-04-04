#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define ALL(v) (v).begin(), (v).end()
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 3e3 + 10;
int n, m, r, c;
int a[NM][NM];
///-------------------------------sub34-------------------------------
vector<int> h[305][305];
///-------------------------------full--------------------------------
int sum[NM][NM];

void readfile(){
    freopen("QUALITY.INP", "r", stdin);
    freopen("QUALITY.OUT", "w", stdout);
    cin >> n >> m >> r >> c;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
}
void sub1(){
    int res = -1;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) maximize(res, a[i][j]);
    cout << res;
}
void sub34(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m - c + 1; j++){
            for(int k = 0; k < c; k++) h[i][j].push_back(a[i][j + k]);
        }
    }

    vector<int> ans;
    int res = -1;
    for(int i = 1; i <= n - r + 1; i++){
        for(int j = 1; j <= m - c + 1; j++){
            ans.clear();
            for(int k = 0; k < r; k++){
                ans.insert(ans.end(), ALL(h[i + k][j]));
            }
            sort(ALL(ans));
            maximize(res, ans[(r * c + 1) / 2 - 1]);
        }
    }
    cout << res;
}
int getSum(int top, int bot, int l, int r){
    return sum[bot][r] - sum[top - 1][r] - sum[bot][l - 1] + sum[top - 1][l - 1];
}
bool check(int x){
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + (a[i][j] >= x ? 1 : -1);
    for(int i = 1; i <= n - r + 1; i++){
        for(int j = 1; j <= m - c + 1; j++){
            if(getSum(i, i + r - 1, j, j + c - 1) > 0) return true;
        }
    }
    return false;
}
void full(){
    sum[1][0] = sum[0][1] = sum[0][0] = 0;
    int l = 1, r = n * m, res = -1;
    while(l <= r){
        int g = (l + r) >> 1;
        if(check(g)){
            maximize(res, g);
            l = g + 1;
        } else r = g - 1;
    }
    cout << res;
}
int main()
{
    FastIO
    readfile();
    if(r == c && r == 1) sub1();
    else if(r == n && c == m) cout << (n * m + 1) / 2;
    else if(r <= 100 && c <= 100) sub34();
    else full();
    return 0;
}
