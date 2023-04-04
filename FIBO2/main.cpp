#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

unsigned long long f[100];
unsigned long long n;
map<int, bool> mp;

int main()
{
    FastIO
    cin >> n;
    f[0] = 0; f[1] = 1;
    mp[0] = true; mp[1] = true;
    for(int i = 2; i <= 93; i++){
        f[i] = f[i - 1] + f[i - 2];
        mp[f[i]] = true;
    }
    if(mp[n]) cout << "YES";
    else cout << "NO";
    return 0;
}
