#include <bits/stdc++.h>
#define int long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 3e3 + 10;
const int MOD = 998244353;
int T, n, m;
int a[NM][NM];

void add(int &a, int b){
    if(a + b >= MOD) a += b - MOD;
    else a += b;
}
void readfile(){
    freopen("COUNTPATH.INP", "r", stdin);
    freopen("COUNTPATH.OUT", "w", stdout);
    cin >> T;
}
void xuli(){
    a[0][0] = 1;
    for(int i = 1; i <= 3000; i++){
        for(int j = 1; j <= 3000; j++){
            add(a[i][j], a[i - 1][j]);
            add(a[i][j], a[i][j - 1]);
            add(a[i][j], a[i - 1][j - 1]);
        }
    }

    while(T--){
        cin >> n >> m;
        cout << a[n][m] << " ";
    }
}
int32_t main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
