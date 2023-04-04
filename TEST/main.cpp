#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e4 + 10;
int n;
int a[NM];
bool cx[NM];

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++) if(abs(a[i]) > 1) {
        while(a[i] == a[i + 1]) i++;
        int cnt = 0;
        for(int j = 2; j <= sqrt(a[i]); j++) if(a[i] % j == 0) cnt++;
        if(cnt == 0) cout << a[i] << " ";
    }
    return 0;
}
