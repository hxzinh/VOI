#include <bits/stdc++.h>
#define int long long
#define INF 1e18
#define ALL(v) (v).begin(), (v).end()
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template <typename T>
inline void Read(T& x) {
    bool Neg = false;
    char c;
    for (c = getchar(); c < '0' || c > '9'; c = getchar())
        if (c == '-') Neg = !Neg;
    x = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
        x = x * 10 + c - '0';
    if (Neg) x = -x;
}
template <typename T>
inline void Write(T x) {
    if (x < 0) { putchar('-'); x = -x; }
    T p = 1;
    for (T temp = x / 10; temp > 0; temp /= 10) p *= 10;
    for (; p > 0; x %= p, p /= 10) putchar(x / p + '0');
}
template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e6 + 10;
int n, k;
int res = 0, ans = -INF;
int f[NM];
bool cx[NM];
vector<int> t;

struct Data {
    int start, day, rent;

    bool inline operator < (const Data &A) const {
        return start + day < A.start + A.day;
    }
};
Data a[NM];

void readfile(){
    freopen("FACILITY.INP", "r", stdin);
    freopen("FACILITY.OUT", "w", stdout);
    Read(n); Read(k);
    for(int i = 1; i <= n; i++){
        Read(a[i].start); Read(a[i].day); Read(a[i].rent);
    }

    sort(a + 1, a + n + 1);
    memset(cx, true, sizeof(cx));
}
void backtrack(int d){
    maximize(ans, res);
    for(int i = 1; i <= n; i++) if(cx[i]) {
        if(a[i].start < d) continue;
        res += a[i].rent;
        cx[i] = false;
        backtrack(a[i].start + a[i].day + k);
        res -= a[i].rent;
        cx[i] = true;
    }
}
int dp(int x, int d){
    if(x > n) return 0;
    if(a[x].start < d) return dp(x + 1, d);
    int &res = f[x];
    if(res != -INF) return res;
    maximize(res, a[x].rent + dp(x + 1, a[x].start + a[x].day + k));
    maximize(res, dp(x + 1, d));
    return res;
}
void sub23(){
    for(int i = 1; i <= n; i++) f[i] = -INF;
    ans = dp(1, 0);
    Write(ans);
}
int finding(int i, int l, int r){
    int res = 0;
    while(l <= r){
        int m = (l + r) >> 1;
        if(a[m].start + a[m].day + k - 1 < a[i].start){
            l = m + 1;
            res = m;
        } else r = m - 1;
    }
    return res;
}
void sub4(){
    a[0].day = a[0].start = INF;
    for(int i = 1; i <= n; i++) f[i] = a[i].rent;
    for(int i = 1; i <= n; i++){
        int maxDay = finding(i, 0, i);
        f[i] = max(f[i - 1], f[maxDay] + a[i].rent);
        maximize(ans, f[i]);
    }
    Write(ans);
}
void xuli(){
    if(n <= 10){
        backtrack(0);
        Write(ans);
    } else if(n <= 10000) sub23();
    else sub4();
}
int32_t main()
{
    FastIO
    readfile();
    sub4();
    return 0;
}
