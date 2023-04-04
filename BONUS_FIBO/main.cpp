#include <bits/stdc++.h>
#define int long long
#define INF 1e9
#define ALL(v) (v).begin(), (v).end()
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e5 + 10;
const int LOG = 74;
int T, n, k;
int cnt = 2, maxA = -1;
int f[100], s[NM], p[NM], fibo[NM], a[NM], g[100][100][2];
bool cx[NM];
///-------------------------sub2--------------------------------
int box[NM][30];
vector<int> save;

void readfile(){
    freopen("INP", "r", stdin);
    freopen("OUT", "w", stdout);
    cin >> T;

    f[1] = f[2] = 1;
    cx[1] = cx[2] = true;
    while(f[cnt] < 1000000000000000){
        cnt++;
        f[cnt] = f[cnt - 1] + f[cnt - 2];
        if(f[cnt] <= 100000) cx[f[cnt]] = true;
    }
}
void sub1(){
    for(int i = 1; i <= 100000; i++){
        int res = 0, tmp = i;
        while(tmp > 0){
            int l = 1, r = cnt, index;
            while(l <= r){
                int mid = (l + r) >> 1;
                if(f[mid] <= tmp){
                    index = mid;
                    l = mid + 1;
                } else r  = mid - 1;
            }
            tmp -= f[index];
            res++;
        }
        s[i] = res;
    }
    while(T--){
        cin >> n >> k;
        int ans = 0;
        for(int i = 1; i <= n; i++) if(s[n - i + 1] >= k) ans += s[n - i + 1];
        cout << ans << '\n';
    }
}
void sub2(){
    int tam;
    for(int i = 1; i <= 100000; i++){
        if(cx[i]) tam = i;
        fibo[i] = tam;
    }
    for(int i = 1; i <= 100000; i++){
        int t = i - fibo[i];
        a[i] = a[t] + 1;
        maximize(maxA, a[i]);
        box[i][a[i]] = 1;
    }
    for(int i = 1; i <= 100000; i++){
        for(int k = 1; k <= maxA; k++){
            box[i][k] += box[i - 1][k];
        }
    }
    while(T--){
        cin >> n >> k;
        int ans = 0;
        for(int i = k; i <= maxA; i++) ans += box[n][i] * i;
        cout << ans << '\n';
    }
}
int dp(int x, int t, int i){
    if(x <= 0 || t <= 0) return 0;
    int l = 1, r = cnt;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(fibo[mid] <= x){
            i = mid;
            l = mid + 1;
        } else r = mid - 1;
    }
    if(x == fibo[i]){
        if(g[i][t][0] == -1){
            if(t == 1) g[i][t][0] = i;
            else g[i][t][0] = dp(x - 1, t, i);
        }
        return g[i][t][0];
    }
;    if(n ==  fibo[i + 1] - 1){
        if(g[i][t][1] == -1) g[i][t][1] = dp(fibo[i], t, i) + dp(x - fibo[i], t - 1, i);
        return g[i][t][1];
    }
    return dp(fibo[i], t, i) + dp(x - fibo[i], t - 1, i);
}
void full(){
    int ans = 0;
    for(int i = k; i <= 36; i++) ans += dp(n, i, 80) * i;
    cout << ans << '\n';
}
int32_t main()
{
    FastIO
    readfile();
    memset(g, -1, sizeof(g));
    fibo[0] = fibo[1] = 1;
    for(int i = 2; i <= 83; i++) fibo[i] = fibo[i - 1] + fibo[i - 2];
    while(T--){
        cin >> n >> k;
        if(k > 36) cout << 0 << '\n';
        else full();
    }
    return 0;
}
