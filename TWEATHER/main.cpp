#include <bits/stdc++.h>
#define int long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e5 + 10;
const int MOD = 1e9 + 7;
string s;
string a[] = {"NW", "WS", "SE", "EN"};
int f[NM];

void add(int &a, int b){
    if(a + b >= MOD) a += b - MOD;
    else a += b;
}
void readfile(){
    freopen("WEATHER.INP", "r", stdin);
    freopen("WEATHER.OUT", "w", stdout);
    cin >> s;
    s = ' ' + s;
}
void xuli(){
    memset(f, 0, sizeof(f));
    f[0] = 1;
    for(int i = 0; i < s.length(); i++) if(f[i] > 0) {
        if(i < s.length()) add(f[i + 1], f[i]);
        if(i + 2 < s.length()){
            for(int j = 0; j < 4; j++){
                if(s[i + 1] == a[j][0] && s[i + 2] == a[j][1]) add(f[i + 2], f[i]);
            }
        }
    }
    cout << f[s.length() - 1];
}
int32_t main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
