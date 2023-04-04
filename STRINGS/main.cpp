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
const int MOD = 1e9 + 19972207;
int n;
int f[NM][2][2];
string a, b;

void add(int &a, int b){
    if(a + b >= MOD) a += b - MOD;
    else a += b;
}
void readfile(){
    freopen("STRINGS.INP", "r", stdin);
    freopen("STRINGS.OUT", "w", stdout);
    cin >> n;
    cin >> a >> b;
    a = ' ' + a;
    b = ' ' + b;
}
void sub3(){
    f[0][0][0] = 1;
    for(int i = 0; i < n; i++){
        for(int u = 0; u < 2; u++){
            for(int v = 0; v < 2; v++) if(f[i][u][v] > 0) {
                for(char t = 'a'; t <= 'z'; t++) {
                    if(u != 1) if(t < a[i + 1]) continue;
                    bool okA = u || t >= a[i + 1];
                    bool okB = v || t <= b[i + 1];
                    if(okA && okB) add(f[i + 1][u || t > a[i + 1]][v || t < b[i + 1]], f[i][u][v]);
                }
            }
        }
    }

    int res = f[n][1][1];
    if(b.length() - 1 > n) add(res, f[n][1][0]);
    cout << res;
}
int32_t main()
{
    FastIO
    readfile();
    sub3();
    return 0;
}
