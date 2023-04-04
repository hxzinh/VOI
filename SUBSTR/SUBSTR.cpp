#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e6 + 10;
int k;
int g[1005][1005], f[NM], c[NM];
string s;

void readfile(){
    freopen("SUBSTR.INP", "r", stdin);
    freopen("SUBSTR.OUT", "w", stdout);
    cin >> k;
    cin >> s;
}
void sub1(){
    int res = 0;
    for(int i = 0; i < s.length(); i++){
        g[i][i] = (s[i] == '1');
        if(g[i][i] == k) res++;
    }

    for(int i = 0; i < s.length(); i++){
        for(int j = i + 1; j < s.length(); j++){
            g[i][j] = g[i][j - 1] + (s[j] == '1');
            if(g[i][j] == k) res++;
            else if(g[i][j] > k) break;
        }
    }
    cout << res;
}
void sub2(){
    s = ' ' + s;
    f[0] = 0;
    f[1] = (s[1] == '1');
    for(int i = 2; i < s.length(); i++) f[i] = f[i - 1] + (s[i] == '1');
    for(int i = 0; i < s.length(); i++) c[f[i]]++;
    int res = 0;
    for(int i = 1; i < s.length(); i++)
        if(f[i] >= k) res += c[f[i] - k];
    cout << res;
}
int main()
{
    FastIO
    readfile();
    if(s.length() <= 500) sub1();
    else sub2();
    return 0;
}
