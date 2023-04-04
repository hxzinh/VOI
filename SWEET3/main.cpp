#include <bits/stdc++.h>
#define int long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e6 + 10;
int T, n, a, b, c;
string s;
int f[10][100];

void readfile(){
    freopen("INP", "r", stdin);
    freopen("OUT", "w", stdout);
    cin >> T;
}
void sub1(){
    int cnt = 0;
    for(int i = 0; i <= 1000000; i++){
        if(a * i > n) break;
        for(int j = 0; j <= 1000000; j++){
            int cur = n - a * i - b * j;
            if(cur < 0) break;
            if(cur % c == 0) cnt++;
        }
    }
    cout << cnt;
}
int dp(int x, int t){
    if(x < 0) return (t == 0);
    int &res = f[x][t];
    if(res != -1) return res;
    res = 0;
    for(int i = 0; i <= 9; i++){
        for(int j = 0; j <= 9; j++){
            for(int z = 0; z <= 9; z++){
                int tmp = a * i + b * j + c * z + t;
                if(tmp % 10 == s[x] - '0') res += dp(x - 1, tmp / 10);
            }
        }
    }
    return res;
}
void full(){
    while(T--){
        cin >> s >> a >> b >> c;
        memset(f, -1, sizeof(f));
        cout << dp(s.size() - 1, 0) << '\n';
    }
}
int32_t main()
{
    FastIO
    readfile();
    full();
    return 0;
}
