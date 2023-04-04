#include <bits/stdc++.h>
#define int long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 2e6 + 10;
int n, d, T;
int f[NM];
bool cx[NM];

void readfile(){
    freopen("FOURDIV.INP", "r", stdin);
    freopen("FOURDIV.OUT", "w", stdout);
    cin >> T;
}
void xuli(){
    memset(cx, true, sizeof(cx));
    cx[1] = false;
    for(int i = 2; i <= sqrt(2000005); i++){
        for(int j = i * i; j <= 2000005; j += i) cx[j] = false;
    }

    int tmp = 1;
    for(int i = 2000005; i > 0; i--) f[i] = cx[i] ? i : f[i + 1];

    while(T--){
        cin >> d;
        int p = f[d + 1];
        int q = f[d + p];
        cout << p * q << '\n';
    }
}
int32_t main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
