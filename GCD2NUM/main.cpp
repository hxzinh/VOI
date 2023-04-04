#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e6 + 10;
int n;
int a[NM], cnt[NM], d[NM];

int main()
{
    FastIO
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        cnt[a[i]]++;
    }

    ll res = 0;
    for(int i = 1; i <= 1000000; i++){
        int dem = 0;
        for(int j = i; j <= 1000000; j += i) if(cnt[j]) {
            dem += cnt[j];
            if(dem >= 2) break;
        }
        if(dem >= 2) res = i;
    }
    cout << res;
    return 0;
}
