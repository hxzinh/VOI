#include <bits/stdc++.h>
#define int long long
#define INF 1e18
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 110;
int n, F[NM][NM][NM], T[30];
string s;

void readfile(){
    freopen("BALASTR.INP", "r", stdin);
    freopen("BALASTR.OUT", "w", stdout);
    cin >> s;
    n = s.length();
    s = ' ' + s;
}

void progress(){
    for (char i = 'A'; i < 'Z'; ++i){
        char j = i;
        while (j != 'A' && j != 'E' && j != 'I' && j != 'O' && j != 'U' && j <= 'Z') j++;
        if (j <= 'Z') T[i - 'A'] = j - i;
        else T[i - 'A'] = INF;
    }
    for (char i = 'Z'; i > 'A'; --i){
        char j = i;
        while (j != 'A' && j != 'E' && j != 'I' && j != 'O' && j != 'U' && j >= 'A') j--;
        if (j >= 'A') minimize(T[i - 'A'], i - j);
    }
    T['Z' - 'A'] = 5;
}
void xuli()
{
    for (int i = 0; i <= n; ++i)
        for(int j = 0; j <= n / 2; ++j)
            for(int k = 0; k <= n / 2; ++k) F[i][j][k] = INF;
    F[0][0][0] = 0;

    for(int i = 0; i < n; ++i){
        for(int j = 0; j <= n / 2; ++j){
            for(int k = 0; k <= n / 2; ++k) if(F[i][j][k] != INF) {
                if (s[i + 1] == 'A' || s[i + 1] == 'E' || s[i + 1] == 'I' || s[i + 1] == 'O' || s[i + 1] == 'U'){
                    minimize(F[i + 1][j + 1][k], F[i][j][k]);
                    minimize(F[i + 1][j][k + 1], F[i][j][k] + 1);
                } else {
                    minimize(F[i + 1][j + 1][k], F[i][j][k] + T[s[i + 1] - 'A']);
                    minimize(F[i + 1][j][k + 1], F[i][j][k]);
                }
            }
        }
    }
    cout << F[n][n / 2][n / 2];
}


int32_t main()
{
    FastIO
    readfile();
    progress();
    xuli();
    return 0;
}
