#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

string s = "";
int n, k;
int cnt = 0;

void backtrack(int x, int last){
    if(x >= n){
        cnt++;
        if(cnt == k){
            cout << s << '\n';
            throw(1);
        }
    }

    for(char i = 'a'; i <= 'z'; i++){
        int newLast;
        if(s.empty()) newLast = 1;
        else newLast = (s.back() == i ? last + 1 : 1);
        s.push_back(i);
        int newX = x + newLast;
        if(newX <= n) backtrack(x + newLast, newLast);
        s.pop_back();
    }
}
int main()
{
    FastIO
    freopen("CONSTSTR.INP", "r", stdin);
    freopen("CONSTSTR.OUT", "w", stdout);
    while(cin >> n >> k){
        cnt = 0;
        s = "";
        try {
            backtrack(0, 0);
        } catch(...){};

    }
    return 0;
}
