#include <bits/stdc++.h>
#define int long long
#define db double
#define INF 0x3f3f3f3f3f3f3f3f
#define ALL(v) (v).begin(), (v).end()
#define pii pair<int, int>
#define fi first
#define se second
#define MASK(x) (1LL << (x))
#define BIT(i, x) ((x) >> (i) & 1)
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e6 + 10;
int n, top = 0;
int a[NM], rMax[NM][25], f[NM], g[NM];
pii lines[NM];

int getRand(int l, int r){
    return rand() % (r - l + 1) + l;
}
void sub1(){
    int res = 0;
    if(n == 3){
        res = 3 * a[1] + 2 * a[2] + a[3];
        minimize(res, 3 * max(a[1], a[2]) + a[3]);
        minimize(res, a[1] + 2 * max(a[2], a[3]));
        minimize(res, 3 * max({a[1], a[2], a[3]}));
    }
    if(n == 2){
        res = 2 * a[1] + a[2];
        minimize(res, max(a[1], a[2]));
    }
    if(n == 1) res = a[1];
    cout << res;
}
int getMax(int u, int v){
    int k = log2(v - u + 1);
    return max(rMax[u][k], rMax[v - MASK(k) + 1][k]);
}
void sub2() {
    for(int i = 1; i <= n; i++) f[i] = INF;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++) {
            int v = i, u = j, k = v - u + 1;
            int ans = getMax(u, v);
            if (f[i] == ans * k + k * g[j - 1] + f[j - 1])
                minimize(g[i], g[j - 1] + ans);
            if (minimize(f[i], ans * k + k * g[j - 1] + f[j - 1]))
                g[i] = g[j - 1] + ans;
        }
    }
    cout << f[n];
}
int eval(pii line, int x){
    return line.fi * x + line.se;
}
bool badLine(pii A, pii B, pii C){
    return db(db(B.se - A.se) / db(A.fi - B.fi)) >= db(db(C.se - A.se) / db(A.fi - C.fi));
}
int getMin(int x){
    int l = 0, r = top - 1;
    int res = eval(lines[l], x);
    while(l < r){
        int mid = (l + r) >> 1;
        int u = eval(lines[mid], x);
        int v = eval(lines[mid + 1], x);
        if(u > v) l = mid + 1;
        else r = mid;
        minimize(res, min(u, v));
    }
    return res;
}
bool insertLine(pii newLine){
    int l = 1, r = top - 1, k = top;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(badLine(lines[mid - 1], lines[mid], newLine)){
            k = mid, r = mid - 1;
        } else l = mid + 1;
    }
    top = k + 1;
    lines[k] = newLine;
    return true;
}
void sub3(){
    insertLine(make_pair(0, 0));
    f[1] = getMin(a[1]) + a[1] * n;
    insertLine(make_pair(-1, f[1]));
    for(int i = 2; i <= n; i++){
        f[i] = getMin(getMax(1, i)) + getMax(1, i) * n;
        insertLine(make_pair(-i, f[i]));
    }
    cout << f[n];
}
void sub5(){
    for(int i = 1; i <= n; i++) f[i] = INF;
    for(int i = 1; i <= n; i++){
        g[i] = INF;
        for(int j = 0; j < i; j++) minimize(g[i], f[j] + getMax(j + 1, i) * (n - j));
        minimize(f[i], g[i]);
    }
    cout << f[n];
}
int32_t main()
{
    FastIO
    freopen("DISCHARG.INP", "r", stdin);
    freopen("DISCHARG.OUT", "w", stdout);
    cin >> n;
    bool cx = true, ok = true;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(i != 1 && a[i] > a[i - 1]) cx = false;
        if(i != 1 && a[i] < a[i - 1]) ok = false;
    }

    for(int i = 1; i <= n; i++) rMax[i][0] = a[i];
    for (int k = 1; MASK(k) <= n; k++)
        for (int i = 1; i + MASK(k) - 1 <= n; i++)
            rMax[i][k] = max(rMax[i][k - 1], rMax[i + MASK(k - 1)][k - 1]);

    if(n <= 3) sub1();
    else if(cx) cout << a[1] * n;
    else if(n <= 1500) sub5();
    else sub3();

    //for(int i = 1; i <= n; i++) cout << getRand(100000000, 1000000000) << " ";
    return 0;
}
