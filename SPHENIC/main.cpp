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

    bool ok = true;
    int dem = 0;
    for(ll i = 2; i * i <= n; i++){
        int cnt = 0;
        while(n % i == 0){
            cnt++;
            n /= i;
            if(cnt > 1){
                ok = false;
                break;
            }
        }
        dem += cnt;
        if(!ok) break;
    }
    if(n != 1) dem++;
    if(dem != 3) ok = false;
    cout << ok;
    return 0;
}
