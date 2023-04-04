#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 3e5 + 10;
int n, m, maxFlower = -1, s = 0;
int a[NM];

void readfile(){
    freopen("FGIFT.INP", "r", stdin);
    freopen("FGIFT.OUT", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        cin >> a[i];
        maximize(maxFlower, a[i]);
        s += a[i];
    }
}
bool check(int x){
    int tmp = s, cnt = 0;
    for(int i = 1; i <= m; i++){
        cnt += (a[i] % x == 0 ? a[i] / x : a[i] / x + 1);
        if(cnt > n) return false;
    }
    return true;
}
void xuli(){
    int l = 1, r = maxFlower, res = 0;
    while(l <= r){
        int m = (l + r) >> 1;
        if(check(m)){
            r = m - 1;
            res = m;
        } else l = m + 1;
    }
    cout << res;
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
