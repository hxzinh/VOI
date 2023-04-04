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
int n, maxx = 0, rev = 0, m = 0;
int a[NM];
int cnt[NM];

bool check(int x){
    int cnt = rev, tmp = 1;
    for(int i = 1; i <= m; i++){
        if(a[i] < tmp){
            cnt++;
            continue;
        }
        cnt += a[i] - tmp;
        if(cnt + m - i <= x) return true;
        if(cnt > x) return false;
        tmp = a[i] + 1;
    }
    return (cnt <= x);
}
void xuli(){
    sort(a + 1, a + m + 1);
    int l = 0, r = n + 1, res = n + 1;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(check(mid)){
            res = mid;
            r = mid - 1;
        } else l = mid + 1;
    }
    cout << res;
}
int32_t main()
{
    FastIO
    cin >> n;
    for(int i = 1; i <= n; i++){
        int u; cin >> u;
        if(u <= n){
            m++;
            a[m] = u;
        }
        else rev++;
    }
    if(m == 0) rev++;

    xuli();
    return 0;
}
