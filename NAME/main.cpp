#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e3 + 10;
int n;
string s[NM], res[NM];

void xuli(){
    for(int i = 1; i <= n; i++) s[i] = " " + s[i];

    for(int i = 1; i <= n; i++){
        for(int j = 1; j < s[i].size(); j++){
            if(s[i][j] == s[i][j - 1] && s[i][j] == ' ') continue;
            if(s[i][j - 1] == ' '){
                if(s[i][j] >= 'a' && s[i][j] <= 'z') s[i][j] = char(s[i][j] - 32);
            } else if(s[i][j] != ' ') {
                if(s[i][j] >= 'A' && s[i][j] <= 'Z') s[i][j] = char(s[i][j] + 32);
            }
            res[i] = res[i] + s[i][j];
        }
    }

    for(int i = 1; i <= n; i++) cout << res[i] << '\n';
}
int main()
{
    FastIO
    freopen("NAME.INP", "r", stdin);
    freopen("NAME.OUT", "w", stdout);
    cin >> n;
    for(int i = 0; i <= n; i++) getline(cin, s[i]);

    xuli();
    return 0;
}
