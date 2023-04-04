#include <bits/stdc++.h>
#define int long long
#define INF 1e9
#define MASK(x) (1LL << (x))
#define BIT(i, x) ((x) >> (i) & 1LL)
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM = 1e6 + 10;
int n, k, sum = 0, divide;
int a[NM], t[NM], pos[NM];
int preSum[NM];
///------------sub2-----------------
bool g[MASK(20)], s[MASK(20)];
int indexx[NM];
///------------sub3-----------------
bool f[105][1005][1005];
///------------sub4-----------------
int p[NM];
bool cx[NM], ok[NM];

void readfile(){
    freopen("SWEET.INP", "r", stdin);
    freopen("SWEET.OUT", "w", stdout);
    cin >> n >> k;
    preSum[0] = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        sum += a[i];
        preSum[i] = preSum[i - 1] + a[i];
    }
    for(int i = 1; i <= n; i++) pos[i] = i;
}
void sub1(){
    int cnt = 0;
    sum = sum / k;
    do{
        int total = 0;
        cnt = 1;
        for(int i = 1; i <= n; i++){
            if(total > sum) break;
            if(total == sum){
                cnt++;
                total = 0;
            }
            total += a[pos[i]];
            t[pos[i]] = cnt;
        }
        if(cnt == k){
            for(int i = 1; i <= n; i++) cout << t[i] << " ";
            return;
        }
    }while(next_permutation(pos + 1, pos + n + 1));
    cout << -1;
}
bool dpBitmask(int id, int mask, int prev_sum){
    if(id > k) return true;
    bool &res = s[mask >> 1];
    if(g[mask >> 1]) return res;
    g[mask >> 1] = true;
    for(int i = 1; i <= n; i++) if(!BIT(i, mask)) {
        int newMask = MASK(i) | mask;
        if(prev_sum + a[i] < sum && dpBitmask(id, newMask, prev_sum + a[i])){
            indexx[i] = id;
            return true;
        }
        if(prev_sum + a[i] == sum && dpBitmask(id + 1, newMask, 0)){
            indexx[i] = id;
            return true;
        }
    }
    return res = false;
}
void sub2(){
    memset(g, false, sizeof(g));
    memset(s, false, sizeof(s));
    sum /= k;
    dpBitmask(1, 0, 0);
    for(int i = 1; i <= n; i++) cout << indexx[i] << " ";
}
bool check(int u, int v, int  i){
    if(u > sum || v > sum || preSum[i] - u - v > sum || i > n) return false;
    return true;
}
bool dp(int i, int l, int r){
    if(f[i][l][r]) return false;
    if(!check(l, r, i)) return false;
    if(i == n) return true;
    f[i][l][r] = true;
    if(dp(i + 1, l + a[i + 1], r)){t[i + 1] = 1; return true;}
    if(dp(i + 1, l, r + a[i + 1])){t[i + 1] = 2; return true;}
    if(dp(i + 1, l, r)){t[i + 1] = 3; return true;}
    return false;
}
void sub3(){
    sum /= k;
    memset(f, false, sizeof(f));
    if(dp(0, 0, 0)) for(int i = 1; i <= n; i++) cout << t[i] << " ";
    else cout << -1;
}
void sub4(){
    sum /= k;
    sort(a + 1, a + n + 1);
    memset(cx, false, sizeof(cx));
    for(int i = 1; i <= k; i++){
        int divide = sum;
        for(int j = n; j >= 0; j--) if(!cx[j]){
            if(divide >= a[j]){
                divide -= a[j];
                t[j] = i;
                cx[j] = true;
            }
        }
        if(divide > 0){cout << -1; return;}
    }
    for(int i = 1; i <= n; i++) cout << t[i] << " ";
}
int32_t main()
{
    FastIO
    readfile();
    /**
    if(sum % k != 0){cout << -1; return 0;}
    if(n <= 10){sub1(); return 0;}
    if(n <= 20){sub2(); return 0;}
    if(n <= 100){sub3(); return 0;}
    else sub4();
    **/
    sub4();
    return 0;
}
