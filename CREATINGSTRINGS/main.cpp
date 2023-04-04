#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

int n;
char a[10];
vector<string> res;

int main()
{
    FastIO
    string u; cin >> u;
    n = u.size();
    for(int i = 0; i < u.size(); i++) a[i + 1] = u[i];
    sort(a + 1, a + n + 1);

    do {
        string ans = "";
        for(int i = 1; i <= n; i++) ans += a[i];
        res.push_back(ans);
    } while(next_permutation(a + 1, a + n + 1));

    sort(res.begin(), res.end());
    res.resize(unique(res.begin(), res.end()) - res.begin());

    cout << res.size() << '\n';
    for(string u : res) cout << u << '\n';
    return 0;
}
