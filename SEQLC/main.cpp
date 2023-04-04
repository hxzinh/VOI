#include <bits/stdc++.h>
#define int long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 2e3 + 10;
int n, k;
int maxx = -INF, minn = INF;
int a[NM], f[NM], g[NM];

struct Data {
    int up, down, cur, cost;
    bool inline operator < (const Data &A) const {
        return cur < A.cur;
    }
};
Data s[NM], t[NM];

void readfile(){
    freopen("INP", "r", stdin);
    freopen("OUT", "w", stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
}
bool check(int x){
    for(int i = 1; i <= n; i++) f[i] = i - 1;

    int tmp = 0;
    for(int i = 2; i <= n; i++){
        for(int j = 1; j < i; j++){
            if(abs(a[j] - a[i]) <= x * (i - j))
                minimize(f[i], f[j] + i - j - 1);
        }
        tmp = min(tmp, f[i - 1]) + 1;
    }
    minimize(f[n], tmp);
    if(f[n] > k) return false;
    else return true;
}
void xuli(){
    a[0] = a[1];
    a[n + 1] = a[n];
    for(int i = 1; i <= n; i++){
        g[i] = max(abs(a[i] - a[i - 1]), abs(a[i + 1] - a[i]));
        minimize(minn, g[i]);
        maximize(maxx, g[i]);
    }

    int l = 0, r = maxx, res = INF;
    f[1] = 0;
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
    readfile();
    xuli();
    return 0;
}
