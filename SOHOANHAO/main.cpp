#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

unsigned long long n;

int main()
{
    FastIO
    cin >> n;

    if(n == 6 || n == 28 || n == 496 || n == 8128 || n == 33550336 || n == 8589869056
    || n == 137438691328 || n == 2305843008139952128) cout << "YES";
    else cout << "NO";
    return 0;
}
