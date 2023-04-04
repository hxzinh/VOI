#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

int main()
{
    FastIO
    long long n;
    int cnt = 1;
    bool cx = false;
    cin >> n;
    if(n < 2) cout << "NO";
    else {
        for(int i = 2; i <= sqrt(n); i++){
            if(n % i == 0){
                cout << "NO";
                return 0;
            }
        }
        cout << "YES";
    }
    return 0;
}
