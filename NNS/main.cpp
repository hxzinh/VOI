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
int n, q;
string s;

void sub1(){
    while(q--){
        int type; cin >> type;
        if(type == 1){
            int u; char x;
            cin >> u >> x;
            s[u] = x;
        } else {
            int u, v; cin >> u >> v;
            int L = u, R = v;
            bool ok = true;
            while(L <= R){
                if(s[L] != s[R]){
                    ok = false;
                    break;
                }
                L++; R--;
            }
            if(ok) cout << "YES" << '\n';
            else cout << "NO" << '\n';
        }
    }
}
int main()
{
    FastIO
    freopen("NNS.INP", "r", stdin);
    freopen("NNS.OUT", "w", stdout);
    cin >> n >> q;
    cin >> s;
    s = '#' + s;

    sub1();
    return 0;
}
