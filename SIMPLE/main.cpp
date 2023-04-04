#include <bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f3f3f3f
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e5 + 10;
int n, cnt = 0;
int a[NM];

void backtrack(int x, int sum){
    if(cnt > NM) return;
    if(sum % 10 == 0) if(sum){
        a[++cnt] = x;
        return;
    }
    for(int i = 1; i <= 9; i++) if(x * 10 + i != 0 && x * 10 < INF)
        backtrack(x * 10 + i, sum += i);
}
int32_t main()
{
    FastIO
    freopen("SIMPLE.INP", "r", stdin);
    freopen("SIMPLE.OUT", "w", stdout);
    cin >> n;

    backtrack(0, 0);
    sort(a + 1, a + cnt + 1);
    cout << a[n];
    return 0;
}
