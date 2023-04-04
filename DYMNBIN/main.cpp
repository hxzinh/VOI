#include <bits/stdc++.h>
#define ll long long
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

const int NM = 2e5 + 10;
string s;
int q;
int pw[NM];

void sub1(){
    while(q--){
        int type, u, v, x;
        cin >> type >> u >> v >> x;
        if(type == 1) for(int i = u; i <= v; i++) s[i] = (x ? '1' : '0');
        else {
            string n = s.substr(u, x);
            string m = s.substr(v, x);
            cout << (n == m);
        }
    }
}
int main()
{
    FastIO
    freopen("DYMNBIN.INP", "r", stdin);
    freopen("DYMNBIN.OUT", "w", stdout);
    cin >> s;
    cin >> q;
    s = " " + s;

    sub1();
    return 0;
}
