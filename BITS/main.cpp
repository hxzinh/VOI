#include <bits/stdc++.h>
#define int long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 5e3 + 10;
int n;
int f[3][2];
string a, b;

void readfile(){
    freopen("BITS.INP", "r", stdin);
    freopen("BITS.OUT", "w", stdout);
    cin >> a >> b;
    n = a.length();
    a = ' ' + a;
    b = ' ' + b;
}
void xuli(){
    for(int i = 1; i <= n; i++){
        if(a[i] == '?') if(b[i] == '0') f[2][0]++;
                        else f[2][1]++;
        else if(b[i] != a[i]){
            if(b[i] == '1') f[1][1]++;
            else if(b[i] == '0') f[0][0]++;
        }
    }

    int res = min(f[1][1], f[0][0]);
    if(f[1][1] == f[0][0]){res += f[2][1] + f[2][0];} else
    if(f[1][1] > f[0][0]){
        f[1][1] -= f[0][0];
        res += f[1][1] + f[2][1] + f[2][0];
    } else {
        f[0][0] -= f[1][1];
        if(f[0][0] > f[2][1]) res = -1;
        else res += f[0][0] + f[2][0] + f[2][1];
    }
    cout << res;
}
int32_t main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
