#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

vector<int> a;

int main()
{
    FastIO
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        int u; cin >> u;
        a.push_back(u);
    }
    sort(a.begin(), a.end());
    for(int u : a) cout << u << " ";
    cout << '\n';

    sort(a.begin(), a.end(), greater<int>());
    for(int u : a) cout << u << " ";
    return 0;
}
