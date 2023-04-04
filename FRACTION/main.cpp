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
int q, a = 0, b = 1;

void Minimal(int &u, int &v){
    bool ok = false;
    if((u < 0 && v > 0) || (u > 0 && v < 0)) ok = true;
    u = abs(u); v = abs(v);

    while(__gcd(u, v) > 1){
        int tmp = __gcd(u, v);
        u /= tmp;
        v /= tmp;
    }
    if(ok) u *= -1;
}
void PlusFrac(int &x, int &y, int u, int v){
    x = x * v + u * y;
    y *= v;
    Minimal(x, y);
}
void MinusFrac(int &x, int &y, int u, int v){
    x = x * v - u * y;
    y *= v;
    Minimal(x, y);
}
void MultiFrac(int &x, int &y, int u, int v){
    x *= u; y *= v;
    Minimal(x, y);
}
void DivideFrac(int &x, int &y, int u, int v){
    MultiFrac(x, y, v, u);
}
pii getNum(string x){
    pii ans;
    bool ok = true;
    for(char u : x){
        if(u == '/'){
            ok = false;
            continue;
        }
        if(ok) ans.fi = ans.fi * 10 + int32_t(u - '0');
        else ans.se = ans.se * 10 + int32_t(u - '0');
    }
    return ans;
}
void sub1(){
    while(q--){
        char t;
        string s;
        cin >> t >> s;
        pii newNum = getNum(s);
        int u = newNum.fi, v = newNum.se;

        Minimal(u, v);
        if(t == '+') PlusFrac(a, b, u, v);
        else if(t == '-') MinusFrac(a, b, u, v);
        else if(t == '*') MultiFrac(a, b, u, v);
        else if(t == '/') MultiFrac(a, b, v, u);
    }

    if(a == 0){
        cout << 0 << '/' << 1;
        return;
    }

    Minimal(a, b);
    cout << a << '/' << b;
}
int32_t main()
{
    FastIO
    freopen("FRACTION.INP", "r", stdin);
    freopen("FRACTION.OUT", "w", stdout);
    cin >> q;

    sub1();
    return 0;
}
