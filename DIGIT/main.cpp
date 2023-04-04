#include <bits/stdc++.h>
#define ll long long
#define int unsigned long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

int a, b, k, T;


int Mul(ll x, ll y){
    if(y == 0) return 0;
    int t = Mul(x, y / 2);
    if(y % 2 == 0) return (t + t) % b;
    else return ((t + t) % b + x) % b;
}
int P10(ll x){
    if(x == 0) return 1 % b;
    int t = P10(x / 2) % b;
    t = Mul(t, t);
    if(x % 2 == 0) return t % b;
    else return (t % b * 10) % b;
}
void xuli(){
    cout << (Mul(a, P10(k - 1)) * 10/ b) << '\n';
}
int32_t main()
{
    FastIO
    freopen("DIGIT.INP", "r", stdin);
    freopen("DIGIT.OUT", "w", stdout);
    cin >> T;

    while(T--){
        cin >> a >> b >> k;
        xuli();
    }
    return 0;
}
