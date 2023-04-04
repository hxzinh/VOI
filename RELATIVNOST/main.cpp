#include <bits/stdc++.h>
#define ll long long
#define INF 1e18
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int MOD = 1e4 + 7;
const int NM = 1e5 + 10;
int n, k, q;
int g[NM], c[NM];
int f[1005][1005];
int sum[NM << 2], H[NM << 2][22];


int combine(int id){
    int l = 2 * id, r = 2 * id + 1;
    sum[id] = sum[l] * sum[r] % MOD;
    memset(H[id], 0, k * sizeof(int));
    for(int i = 0; i < k; i++)
        for(int j = 0; j < k - i; j++) H[id][j + i] += H[l][i] * H[r][j];
    for(int j = 0; j < k; j++) H[id][j] %= MOD;
}
void build(int i, int l, int r){
    if(l > r) return;
    if(l == r){
        sum[i] = (g[l] + c[l]) % MOD;
        H[i][1] = g[l] % MOD;
        H[i][0] = c[l] % MOD;
        return;
    }
    int m = (l + r) >> 1;
    build(2 * i, l, m);
    build(2 * i + 1, m + 1, r);
    combine(i);
}
void update(int i, int l, int r, int pos){
    if(l > pos || r < pos) return;
    if(l == r){
        sum[i] = (g[pos] + c[pos]) % MOD;
        H[i][0] = c[pos] % MOD;
        H[i][1] = g[pos] % MOD;
        return;
    }
    int m = (l + r) >> 1;
    if(pos > m) update(2 * i + 1, m + 1, r, pos);
    else update(2 * i, l, m, pos);
    combine(i);
}

int getRes(){
    int res = sum[1];
    for(int i = 0; i < k; i++) res = res - H[1][i];
    return (res % MOD + MOD) % MOD;
}


void add(int &a, int b){
    if(a + b >= MOD) a += b - MOD;
    else a += b;
}
void sub1(){
    f[0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < k; j++){
            f[i][j] = f[i - 1][j] * c[i] % MOD;
            if(j) add(f[i][j], f[i - 1][j - 1] * g[i] % MOD);
            ///f[i][j] = ((f[i - 1][j - 1] * g[i]) % MOD + (f[i - 1][j] * c[i] % MOD)) % MOD;
        }
    }

    int sum = 1;
    for(int i = 1; i <= n; i++) sum = sum * ((g[i] + c[i]) % MOD) % MOD;

    int res = 0;
    for(int i = 0; i < k ; i++) add(res, f[n][i]);
    cout << (sum - res + MOD) % MOD << " ";
}
int32_t main(){
    FastIO
    freopen("RELATIVNOST.INP", "r", stdin);
    freopen("RELATIVNOST.OUT", "w", stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> g[i];
    for(int i = 1; i <= n; i++) cin >> c[i];
    cin >> q;

    build(1, 1, n);
    while(q--){
        int i, u, v;
        cin >> i >> u >> v;
        g[i] = u; c[i] = v;
        update(1, 1, n, i);
        cout << getRes() << " ";
    }
    return 0;
}
