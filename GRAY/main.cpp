#include <bits/stdc++.h>
#include <string>.h
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

int n;

string toBin(int x){
    string s = "";
    while(x != 0){
        s += x % 2 + '0';
        x /= 2;
    }
    while(s.size() < n) s += "0";
    reverse(s.begin(), s.end());
    return s;
}
int main()
{
    FastIO
    cin >> n;

    for(int i = 0; i < 1 << n; i++){
        int cur = i ^ (i >> 1);
        cout << toBin(cur) << '\n';
    }
    return 0;
}
