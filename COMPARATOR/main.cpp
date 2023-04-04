#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define popcount(x) __builtin_popcount(x)
#define setp(x) setprecision(x)
#define MASK(x) (1LL << (x))
#define BIT(x, i) ((x) >> (i) & 1)
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

vector<string> a;
map<string, int> mp;

bool cmp2(const string A, const string B){
    return A > B;
}
bool cmp3(const string A, const string B){
    return (A.size() == B.size() ? A < B : A.size() < B.size());
}
bool cmp4(const string A, const string B){
    return (mp[A] == mp[B] ? A < B : mp[A] > mp[B]);
}
int32_t main()
{
    FastIO
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        string u; cin >> u;
        a.push_back(u);
        mp[u]++;
    }

    sort(ALL(a));
    for(string u : a) cout << u << " ";
    cout << '\n';

    sort(ALL(a), cmp2);
    for(string u : a) cout << u << " ";
    cout << '\n';

    sort(ALL(a), cmp3);
    for(string u : a) cout << u << " ";
    cout << '\n';

    sort(ALL(a), cmp4);
    for(string u : a) cout << u << " ";
    cout << '\n';
    return 0;
}

/* Author: hxzinh */

/*
-----code ko bug-----code ko bug-----code ko bug--------------

          _.-/`)
         // / / )
      .=// / / / )
     //`/ / / / /
    // /     ` /
   ||         /
    \\       /
     ))    .'
    //    /
         /
*/
