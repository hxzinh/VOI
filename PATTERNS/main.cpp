#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e5 + 10;
int n, m;
int cnt = 0;
string a, s;

void readfile(){
    freopen("PATTERNS.INP", "r", stdin);
    freopen("PATTERNS.OUT", "w", stdout);
    cin >> a >> s;
    n = a.length();
    m = s.length();
    a = ' ' + a;
    s = ' ' + s;
}
void xuli(){
    for(int i = 1; i <= n; i++) cnt += (a[i] == '*');
    int k = s - (n + cnt);

}
int main()
{
    FastIO
    cout << "Hello world!" << endl;
    return 0;
}
