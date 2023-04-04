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
int L = INF, R = -1, cnt = 0;
bool ok[1000005];

int main()
{
    FastIO
    cin >> n;
    for(int i = 1; i <= n; i++){
        int u; cin >> u;
        maximize(R, u);
        minimize(L, u);
        if(!ok[u]) cnt++;
        ok[u] = true;
    }
    cout << (R - L + 1) - cnt;
    return 0;
}
