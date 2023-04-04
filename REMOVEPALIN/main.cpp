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
    freopen("INP", "r", stdin);
    freopen("OUT", "w", stdout);
    cin >> s;
    n = s.length();
}
void sub12(){
    for(int i = 0; i < n; i++){
        string tam = "" + s[i];
        for(int j = i + 1; j < n; j++){
            int len = j - i + 1;
            for(int z = j + 2; z <= j + len + 1; z++)
        }
    }
}
int main()
{
    FastIO
    cout << "Hello world!" << endl;
    return 0;
}
