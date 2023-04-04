#include <bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define popcount(x) __builtin_popcount(x)
#define set(x) setprecision(x)
#define MASK(x) (1LL << (x))
#define BIT(x, i) ((x) >> (i) & 1)
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e5 + 10;
int n, sumCost;
pii a[NM];
string f[505][100005], g[NM];

string getSum(string a, string b)
{
    string res = "";
    while(a.length() < b.length()) a="0"+a;
    while(b.length() < a.length()) b="0"+b;
    int carry = 0;
    for(int i = a.length() - 1; i >= 0; i--)
    {
        int tmp = a[i] - 48 + b[i] - 48 + carry;
        carry = tmp / 10;
        tmp = tmp % 10;
        res = char(tmp + '0') + res;
    }
    if(carry > 0) res= "1" + res;
    return res;
}

void xuli(){
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= sumCost; j++) f[i][j] = "0";

    f[0][0] = "1";
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= sumCost; j++) if(f[i][j] != "0"){
            f[i + 1][j] = getSum(f[i + 1][j], f[i][j]);
            for(int k = 1; k <= a[i + 1].se; k++){
                if(j + a[i + 1].fi * k > sumCost) break;
                f[i + 1][j + a[i + 1].fi * k] = getSum(f[i + 1][j + a[i + 1].fi * k], f[i][j]);
            }
        }
    }
    cout << f[n][sumCost];
}
void full(){
    for(int i = 0; i <= sumCost; i++) g[i] = "0";
    g[0] = "1";

    for(int i = 1; i <= n; i++){
        for(int sum = 0; )
    }
}
int32_t main()
{
    FastIO
    freopen("QBMARKET.INP", "r", stdin);
    freopen("QBMARKET.OUT", "w", stdout);
    cin >> sumCost >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i].fi >> a[i].se;
    }

    xuli();
    return 0;
}
