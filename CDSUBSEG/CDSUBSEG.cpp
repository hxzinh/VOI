#include <bits/stdc++.h>
#define int long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 5e5 + 10;
int n, T;
int a[NM], FL[NM], FR[NM];

void readfile(){
    freopen("CDSUBSEG.INP", "r", stdin);
    freopen("CDSUBSEG.OUT", "w", stdout);
    cin >> T;
}
int GCD(int u, int v){
    if(u == 0 || v == 0) return 0;
    if(v > u) swap(u, v);
    int tmp = u % v;
    while(tmp != 0){
        u = v;
        v = tmp;
        tmp = u % v;
    }
    return v;
}
bool check(int k){
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if((i - 1) % k == 0) cnt = 0;
        if(++cnt == 1) FL[i] = a[i];
        else FL[i] = GCD(FL[i - 1], a[i]);
    }

    cnt = n % k;
    for(int i = n; i > 0; i--){
        if(i % k == 0) cnt = k;
        if(--cnt == k - 1 || i == n) FR[i] = a[i];
        else FR[i] = GCD(FR[i + 1], a[i]);
    }

    for(int i = 1; i <= n - k + 1; i++){
        int g = GCD(FR[i], FL[i + k - 1]);
        if(abs(g) != 1) return true;
    }
    return false;
}
void xuli(){
    while(T--){
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> a[i];

        int l = 1, r = n, res = 0;
        while(l <= r){
            int m = (l + r) >> 1;
            if(check(m)){
                res = m;
                l = m + 1;
            } else r = m - 1;
        }
        cout << res << '\n';
    }
}
int32_t main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
