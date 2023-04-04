#include <bits/stdc++.h>
#define int long long
#define ll long long
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define popcount(x) __builtin_popcount(x)
#define setp(x) setprecision(x)
#define MASK(x) (1LL << (x))
#define BIT(x, i) ((x) >> (i) & 1)
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e5 + 10;
const int MOD = 1e9 + 7;
string s;
int n, m;
int a[NM];
ll f[NM][10], g[NM][11][2];

void add(ll &a, ll b){
    if(a + b >= MOD) a += b - MOD;
    else a += b;
}
void sub1(){
    ll m = 0, res = 0;;
    for(int i = 1; i <= n; i++) m = m * 10 + int32_t(s[i] - '0');

    stack<int> st;
    for(int i = 1; i <= m; i++){
        string tmp = "";
        int u = i;
        while(u != 0){
            st.push(u % 10);
            u /= 10;
        }

        while(st.size()){
            tmp += char(st.top() + '0');
            st.pop();
        }
        if(tmp.size() % 2 == 0) continue;
        int k = tmp.size() - 1;

        bool ok = true;
        int pre = -100000;
        for(int j = 0; j <= tmp.size() / 2; j++){
            if(tmp[j] != tmp[k - j] || abs(int32_t(tmp[j] - '0') - pre) < 5){
                ok = false;
                break;
            } else pre = int32_t(tmp[j] - '0');
        }
        //if(ok) cout << tmp << '\n';
        add(res, ok);
    }

    cout << res;
}

ll dp(int x, int p, bool okL){
    if(x > m) return (p != 10);
    ll &res = g[x][p][okL];
    if(res > -1) return res;

    res = 0;
    for(int i = 0; i < 10; i++){
        if((okL || ((x == m && !okL) ? (i < a[x]) : (i <= a[x])))
        && (p == 10 || abs(i - p) >= 5)){
            res += dp(x + 1, (p == 10 && i == 0) ? 10 : i, (okL || i < a[x]));
            res %= MOD;
        }
    }
    return res;
}
void full(){
    memset(g, -1, sizeof g);
    m = (n + 1) / 2;
    for(int i = 1; i <= n; i++) a[i] = s[i] - '0';
    bool ok = (n % 2 == 0);
    if(ok) n--;

    cout << dp(1, 10, ok);
}
int32_t main()
{
    FastIO
    freopen("PLDNUM.INP", "r", stdin);
    freopen("PLDNUM.OUT", "w", stdout);
    cin >> s;
    n = s.size();
    s = '#' + s;

    if(n <= 6) sub1();
    else full();
    return 0;
}

/* Author: hxzinh */

/*
-----code ko bug-----code ko bug-----code ko bug--------------

          _.-/`)
         // / / )
      .=// / / / )
     //`/ / / / /
    // /     ` /
   ||         /
    \\       /
     ))    .'
    //    /
         /
*/
