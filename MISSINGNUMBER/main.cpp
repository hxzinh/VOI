#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 2e5 + 10;
int n;
int a[NM];

int main()
{
    FastIO
    cin >> n;
    for(int i = 1; i < n; i++) cin >> a[i];

    sort(a + 1, a + n);
    for(int i = 1; i <= n; i++) if(i != a[i]){
        cout << i;
        break;
    }
    return 0;
}
