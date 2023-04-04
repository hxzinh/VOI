#include <bits/stdc++.h>
#define int long long
#define INF 1e9
#define ii pair<int, int>
#define fi first
#define se second
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 2e5 + 10;
int T, n;
int a[NM], b[NM];
ii c[NM];

void readfile(){
    freopen("MEDPYRH.INP", "r", stdin);
    freopen("MEDPYRH.OUT", "w", stdout);
    cin >> T;
}
int dp(int x){
    if(b[n - x + 1] == b[n + x - 1]) return b[n - x + 1];
    else return dp(x - 1);
}
bool check(int x){
    for(int i = 1; i <= 2 * n - 1; i++) b[i] = (a[i] >= x);

    if(b[n] == b[n + 1] || b[n] == b[n - 1]) return b[n];
    return dp(n);
}
void solve(){
    int l = 1, r = 2 * n - 1, res = 0;
    while(l <= r){
        int m = (l + r) >> 1;
        if(check(m)){
            res = m;
            l = m + 1;
        } else r = m - 1;
    }
    cout << res << '\n';
}
int getTV(int x, int y, int z){
    if(x > y) swap(x, y);
    if(x > z) swap(x, z);
    if(y > z) swap(y, z);
    return y;
}
void full(){
    while(n >= 1){
        if(n == 1){
            cout << a[n] << '\n';
            break;
        }
        if(a[n] == a[n - 1] || a[n] == a[n + 1]){
            cout << a[n] << '\n';
            break;
        }
        if(a[n] > a[n - 1] && a[n] < a[n + 1] && (a[n] < a[n - 2] || a[n] > a[n + 2])){
            cout << a[n] << '\n';
            break;
        }
        if(a[n - 1] == a[n + 1]){
            if(a[n - 1] == a[n - 2] || a[n + 1] == a[n + 2]){
                cout << a[n - 1] << '\n';
                break;
            }
        }
        if(a[n] > a[n + 1] && a[n] < a[n - 1]){
            cout << a[n] << '\n';
            break;
        }
        if(a[n] > a[n - 1] && a[n] < a[n + 1]){
            cout << a[n] << '\n';
            break;
        }

        for(int i = 1; i <= 2 * n - 3; i++){
            int x = a[i], y = a[i + 1], z = a[i + 2];
            a[i] = getTV(x, y, z);
        }
        n--;
    }
}
void xuli(){
    while(T--){
        cin >> n;
        for(int i = 1; i <= 2 * n - 1; i++) cin >> a[i];
        full();
    }
}
int32_t main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
