#include <bits/stdc++.h>
#define int long long
#define db double
#define INF 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define pil pair<int, long long>
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define popcount(x) __builtin_popcount(x)
#define set(x) setprecision(x)
#define MASK(x) (1LL << (x))
#define BIT(x, i) ((x) >> (i) & 1)
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e6 + 10;
int n, cost;
int top = 0;
int a[NM], f[NM];
pair<int, int> lines[NM];

long long eval(pil line, long long x) {
    return line.fi * x + line.se;
}
bool bad(pil a, pil b, pil c){
    return ((double)(b.se - a.se) / (a.fi - b.fi) >= (double)(c.se - a.se) / (a.fi - c.fi));
}
long long getMin(long long coord) {
    int l = 0, r = top - 1;
    long long ans = eval(lines[l], coord);
    while (l < r) {
        int mid = (l + r) >> 1;
        long long x = eval(lines[mid], coord);
        long long y = eval(lines[mid + 1], coord);
        if (x > y) l = mid + 1; else r = mid;
        ans = min(ans, min(x, y));
    }
    return ans;
}

bool insertLine(pil newLine) {
    int l = 1, r = top - 1, k = top;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (bad(lines[mid - 1], lines[mid], newLine)) {
            k = mid; r = mid - 1;
        }
        else l = mid + 1;
    }
    top = k + 1;
    lines[k] = newLine;
    return 1;
}
void xuli(){
    insertLine(make_pair(0, 0));
    for(int i = 1; i < n; i++){
        f[i] = getMin(a[i]) + (a[i] * a[i]) + cost;
        insertLine(make_pair(-2 * a[i], f[i] + (a[i] * a[i])));
    }
    cout << f[n - 1];
}
int32_t main()
{
    FastIO
    freopen("FROG3.INP", "r", stdin);
    freopen("FROG3.OUT", "w", stdout);
    cin >> n >> cost;
    for(int i = 1; i <= n; i++) cin >> a[i];

    xuli();
    return 0;
}
