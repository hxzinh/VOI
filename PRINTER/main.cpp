#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define ALL(v) (v).begin(), (v).end()
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e6 + 10;
int n;
string s;
vector<string> t;

void readfile(){
    freopen("INP", "r", stdin);
    freopen("OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> s;
        t.push_back(s);
    }
}
void xuli(){
    sort(ALL(t));
    for(string u : t) cout << u << '\n';
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
