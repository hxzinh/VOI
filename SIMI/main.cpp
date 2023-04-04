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
int n;
string s;

void readfile(){
    freopen("SIMI.INP", "r", stdin);
    freopen("SIMI.OUT", "w", stdout);
    cin >> s;
    n = s.length();
    s = ' ' + s;
}
void sub1(){
    int res = 0;
    for(int i = 1; i <= n; i++){
        int tmp = 1;
        for(int j = i; j <= n; j++){
            if(s[j] == s[tmp]){
                res++;
                tmp++;
            } else break;
        }
    }
    cout << res;
}
int main()
{
    FastIO
    readfile();
    sub1();
    return 0;
}
