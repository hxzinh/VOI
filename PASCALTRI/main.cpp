#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int MOD = 1e9 + 7;
int n;
ll a[200][200];

int main()
{
    FastIO
    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            if(i == j || j == 0) {
                a[i][j] = 1;
                cout << a[i][j] << " ";
            } else {
                a[i][j] = (a[i - 1][j - 1] + a[i - 1][j]) % MOD;
                cout << a[i][j] << " ";
            }
        }
        cout << '\n';
    }
    return 0;
}
