#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e5 + 10;
const int MOD = 1e9 + 7;
int n;
int cnt[NM];

int main()
{
    FastIO
    cin >> n;

    for(int i = 1; i <= n; i++){
        int u = i;
        for(int j = 2; j * j <= u; j++) if(u % j == 0) {
            while(u % j == 0){
                cnt[j]++;
                u /= j;
            }
        }
        if(u > 1) cnt[u]++;
    }

    ll res = 1;
    for(int i = 1; i <= n; i++) res = res * (cnt[i] + 1) % MOD;
    cout << res;
    return 0;
}
