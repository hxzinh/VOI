#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

ll n;

int main()
{
    FastIO
    cin >> n;

    int pre = n % 10;
    n /= 10;
    ll cur = 0;
    while(n != 0){
        cur = cur * 10 + n % 10;
        n /= 10;
    }
    int last = cur % 10;
    cur /= 10;

    ll tmp = 0, res = cur;
    while(cur != 0){
        tmp = tmp * 10 + cur % 10;
        cur /= 10;
    }

    if(pre < last) swap(pre, last);
    if(tmp == res && 2 * last == pre) cout << "YES";
    else cout << "NO";
    return 0;
}
