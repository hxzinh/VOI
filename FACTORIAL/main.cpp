#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

string n;
int T, k;
int sum = 0;

int main()
{
    FastIO
    freopen("FACTORIAL.INP", "r", stdin);
    freopen("FACTORIAL.OUT", "w", stdout);
    cin >> T;
    while(T--){
        cin >> n >> k;
        sum = 0;
        for(int i = 0; i < n.size(); i++) sum += int(n[i] - '0');
        int Last = n.back() - '0';
        if(k == 1) cout << "YES" << '\n';
        else if(k == 2) cout << (Last % 2 == 0 ? "YES" : "NO") << '\n';
        else if(k == 3) cout << (Last % 2 == 0 && sum % 3 == 0 ? "YES" : "NO") << '\n';
    }
    return 0;
}
