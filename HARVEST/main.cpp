#include <bits/stdc++.h>
#define int long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e5 + 10;
int n, m;
int a[NM], b[NM];

void readfile(){
    freopen("HARVEST.INP", "r", stdin);
    freopen("HARVEST.OUT", "w", stdout);
}
bool check(int x){
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(cnt == m) return true;
        if(a[i] > b[cnt + 1]){
            if(a[i] - b[cnt + 1] > x) return false;
            int goL = a[i] - b[cnt + 1] > 2 * x ? a[i] : a[i] + x - 2 * (a[i] - b[cnt + 1]);
            int goR = (x + a[i] + b[cnt + 1]) / 2;
            int maxPos = max(goL, goR);
            while(cnt < m && b[cnt + 1] <= maxPos) cnt++;
        } else {
            while(cnt < m && b[cnt + 1] <= a[i] + x) cnt++;
        }
    }
    return cnt == m;
}
void getAns(){
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);
    int l = 0, r = 1e15;
    int res = r;
    while(l <= r){
        int m = (l + r) >> 1;
        if(check(m)){
            res = m;
            r = m - 1;
        } else l = m + 1;
    }
    cout << res << " ";
}
void xuli(){
    while(true){
        cin >> n >> m;
        if(n == m && n == 0) break;
        for(int i = 1; i <= n; i++) cin >> a[i];
        for(int i = 1; i <= m; i++) cin >> b[i];
        getAns();
    }
}
int32_t main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
