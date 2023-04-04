#include <bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int MAX = 2e5 + 10;
int n, k, T;
int a[MAX], b[MAX];

bool check(int x){
    int cnt = 0;
    for(int i = 1; i <= n; i++) b[i] = a[i];
    for(int i = 1; i < n; i++){
        if(abs(b[i] - b[i + 1]) > x){
            cnt++;
            if(i == n - 1) continue;
            b[i + 1] = (b[i + 2] > b[i] ? min(b[i] + x, (b[i] + b[i + 2]) / 2) : max(b[i] - x, (b[i] + b[i + 1]) / 2));
        }
    }
    return (cnt <= k);
}
void xuli(){
    int maxH = -1;
    for(int i = 1; i <= n; i++) maximize(maxH, a[i]);
    int l = 1, r = maxH + 1, res = INF;
    while(l <= r){
        int m = (l + r) >> 1;
        if(check(m - 1)){
            r = m - 1;
            res = m - 1;
        } else l = m + 1;
    }
    cout << res << '\n';
}
void sub1(){
    for(int i = 1; i <= n; i++){

    }
}
int32_t main()
{
    FastIO
    freopen("TERRAIN.INP", "r", stdin);
    freopen("TERRAIN.OUT", "w", stdout);
    cin >> T;
    while(T--){
        cin >> n >> k;
        for(int i = 1; i <= n; i++) cin >> a[i];

        xuli();
    }
    return 0;
}
