#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e2 + 10;
int n;
int p[1005];
string s;

void readfile(){
    freopen("INP", "r", stdin);
    freopen("OUT", "w", stdout);
    cin >> s >> n;
    p['a'] = n;
    for(char i = 'b'; i <= 'z'; i++){
        n++;
        p[i] = (n > 25 ? n = 0 : n);
    }
}
void xuli(){
    int res = 0;
    for(int i = 0; i < s.length(); i++) res += p[s[i]];
    cout << res;
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
