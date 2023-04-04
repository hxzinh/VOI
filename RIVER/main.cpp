#include <bits/stdc++.h>
#define int long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e6 + 10;
int n, m, k;
int sum = 0;
int a[NM];

void readfile(){
    freopen("RIVER.INP", "r", stdin);
    freopen("RIVER.OUT", "w", stdout);
    cin >> n >> m >> k;
    for(int i = 0; i <= n; i++){
        a[i] = 1 + (i * i % m);
        sum += a[i];
    }
}
bool check(int x){
    int len = 0, cnt = 0;
    for(int i = 0; i < n; i++){
        if(x < a[i]) return false;
        if(len + a[i] > x){
            len = 0;
            cnt++;
        }
        len += a[i];
    }
    return (cnt + 1 <= k);
}
void xuli(){
    int l = 1, r = sum, res = -1;
    while(l <= r){
        int m = (l + r) >> 1;
        if(check(m)){
            res = m;
            r = m - 1;
        } else l = m + 1;
    }
    cout << res;
}
int32_t main(){
    FastIO
    readfile();
    xuli();
    return 0;
}
