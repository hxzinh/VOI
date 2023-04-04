#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define pii pair<int, int>
#define fi first
#define se second
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
    inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
    inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

int n;
vector<int> a;

int main()
{
    FastIO
    cin >> n;
    for(int i = 1; i <= n; i++){
        int u; cin >> u;
        a.push_back(u);
    }
    sort(a.begin(), a.end());

    pii res = {INF, 0}, ans = {0, 0};
    for(int i = 0; i < a.size(); i++){
        if(ans.fi == a[i]) ans.se++;
        else ans = {a[i], 1};
        if(maximize(res.se, ans.se)) res.fi = ans.fi;
        else if(res.se == ans.se) minimize(res.fi, ans.fi);
    }
    cout << res.fi << " " << res.se;
    return 0;
}
