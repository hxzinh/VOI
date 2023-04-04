#include <bits/stdc++.h>
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

string s;
bool ok1, ok2, ok3, ok4, ok5;

int32_t main()
{
    FastIO
    freopen("PASS.INP", "r", stdin);
    freopen("PASS.OUT", "w", stdout);

    cin >> s;
    ok3 = true;
    for(int i = 0; i < s.size(); i++){
        if(s[i] >= 'A' && s[i] <= 'Z') ok1 = true;
        if(s[i] >= 'a' && s[i] <= 'z') ok2 = true;
        if(s[i] >= '0' && s[i] <= '9') ok4 = true;
        if(s[i] == '!' || s[i] == '@' || s[i] == '#' || s[i] == '$' || s[i] == '%' || s[i] == '^' || s[i] == '&' || s[i] == '*' || s[i] == '(' || s[i] == ')' || s[i] == '-' || s[i] == '+') ok5 = true;
    }
    for(int i = 1; i < s.size(); i++) if(s[i] == s[i - 1]) ok3 = false;


    if(ok1 && ok2 && ok3 && ok4 && ok5) cout << "YES";
    else cout << "NO";
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
