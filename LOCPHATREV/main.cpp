#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

int n, m;

bool check(int x){
    bool ok = false;
    int sum = 0, newX = 0, oldX = x;

    while(x != 0){
        if(x % 10 == 6) ok = true;
        sum += x % 10;
        newX = newX * 10 + x % 10;
        x /= 10;
    }

    return (ok && sum % 10 == 8 && newX == oldX);
}
int main()
{
    FastIO
    cin >> n >> m;

    for(int i = n; i <= m; i++){
        if(check(i)) cout << i << " ";
    }
    return 0;
}
