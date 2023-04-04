#include <bits/stdc++.h>
#define ll long long
#define INF 1e18
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e6 + 10;
const int MOD = 998244353;
int s, len;
string n;
int f[NM], k[NM];

void add(int &a, int b){
    if(a + b >= MOD) a += b - MOD;
    else a += b;
}
void readfile(){
    freopen("SUMDIV.INP", "r", stdin);
    freopen("SUMDIV.OUT", "w", stdout);
    cin >> s;
    cin >> n;
    len = n.size();
    n = ' ' + n;
}
void xuli(){
    k[0] = INF;
    for(int i = 1; i <= s; i++)
        for(int j = i; j <= s; j += i) k[j] += i;

    f[0] = 1;
    for(int i = 0; i < len; i++) if(f[i] > 0) {
        int tam = 0;
        for(int j = i + 1; j <= len; j++){
            tam = tam * 10 + (n[j] - '0');
            if(tam > s) break;
            if(k[tam] <= s) add(f[j], f[i]);
        }
    }
    cout << f[len];
}
int32_t main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
