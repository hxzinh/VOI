#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

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

const int NM = 1e6 + 10;
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
        if((i - 1) % k == 0) FL[i] = a[i];
        else FL[i] = __gcd(FL[i - 1], a[i]);
    }
    for(int i = n; i > 0; i--){
        if(i % k == 0 || i == n) FR[i] = a[i];
        else FR[i] = __gcd(FR[i + 1], a[i]);
    }
    for(int i = 1; i <= n - k + 1; i++){
        if(__gcd(FR[i], FL[i + k - 1]) != 1) return true;
    }
    return false;
}
void xuli(){
    while(T--){
        cin >> n;
        ///memset(a, 0, sizeof(a));
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            a[i] = abs(a[i]);
        }

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
