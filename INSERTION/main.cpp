#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define ALL(v) (v).begin(), (v).end()
#define pii pair<int, int>
#define fi first
#define se second
#define MASK(x) (1LL << (x))
#define BIT(i, x) ((x) >> (i) & 1)
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

string s, p;
int q, k, Sub;

int main()
{
    FastIO
    freopen("INSERTION.INP", "r", stdin);
    freopen("INSERTION.OUT", "w", stdout);
    cin >> Sub;
    cin >> p;
    cin >> q;
    s = " ";
    p = ' ' + p;
    while(q--){
        int x, l, r;
        cin >> x >> l >> r;
        s.insert(x, p.substr(l, r - l + 1));
    }
    cin >> k;
    while(k--){
        int u; cin >> u;
        cout << s[u];
    }
    return 0;
}
