#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

string s;
int res = 0;

int main()
{
    FastIO
    cin >> s;

    int ans = 1;
    for(int i = 1; i < s.size(); i++){
        if(s[i] == s[i - 1]) ans++;
        else {
            maximize(res, ans);
            ans = 1;
        }
    }
    maximize(res, ans);
    cout << res;
    return 0;
}
