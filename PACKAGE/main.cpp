#include <bits/stdc++.h>
#define int long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 5e5 + 10;
int n, p, q, u, v;

void readfile(){
    freopen("INP", "r", stdin);
    freopen("OUT", "w", stdout);
    cin >> n >> p >> q >> u >> v;
    if(v > q){
        swap(v, q);
        swap(u, p);
    }
}
void xuli(){
    int costP = (n / p) * q;
    int costU = (n / u) * v;
    int res = 0;
    if(costP < costU){
        res += costP;
        n -= (p * (n / p));
        if(n / u > 0 && (n / u) * v <= q){
            res += (n / u) * v;
            n -= (n / u) * u;
        } else {
            res += q;
            n = 0;
        }
    } else {
        res += costU;
        n -= (u * (n / u));
        if(n / p > 0 && (n / p) * q <= v){
            res += (n / p) * q;
            n -= (n / p) * p;
        } else {
            res += v;
            n = 0;
        }
    }
    res += (n < v ? n : v);
    cout << res;
}
void full(){
    int res = 0;
    while(n > 0){
        int costP = (n / p) * q;
        int costU = (n / u) * v;
        int tmp = min((n < p ? p : INF), (n < u ? v : INF));
        int cost = min(n, tmp);
        if(cost < costP && cost < costU){
            res += cost;
            n = 0;
        } else if(costP < costU) {
                    res += costP;
                    n -= (p * (n / p));
               } else {
                    res += costU;
                    n -= (u * (n / u));
               }
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
