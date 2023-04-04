#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i,a,b) for(int i = a; i <= b; i++)
#define FORD(i,a,b) for(int i = a; i >= b; i--)
#define REP(i,a) for(int i = 0; i < a; i++)
#define MASK(i) (1LL << (i))
#define BIT(i, a) (((a) >> (i)) & 1)
#define fi first
#define se second
#define ALL(v) v.begin(), v.end()
/*
    (\_/)
    (｡•ᵕ•)
    / > 💖
*/
using namespace std;

template<class T> T Abs(const T &x) { return (x < 0 ? -x : x); }
template<class X, class Y>
bool minimize(X &x, const Y &y) {
    X eps = 1e-9;
    if (x > y + eps) {
        x = y;
        return true;
    } else return false;
}
template<class X, class Y>
bool maximize(X &x, const Y &y) {
    X eps = 1e-9;
    if (x + eps < y) {
        x = y;
        return true;
    } else return false;
}

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

using ii = pair <int, int>;
using ll = long long;
using ld = long double;

const int INF = int(1e9) + 7;
const long long oo = 1e18 + 7;

const int Nmax = 5007;
int numCol, numRow, a[Nmax][Nmax];
long long f[Nmax][Nmax], g[Nmax][Nmax];
vector <ii> rightPos;
bool cmp(ii x, ii y){
    return x.fi * x.fi + x.se * x.se < y.fi * y.fi + y.se * y.se;
}
long long findAns(void){
    FOR(i, 1, numRow) FOR(j, 1, numCol) f[i][j] = g[i][j] = a[i][j];
    long long best = -oo;
    REP(k, rightPos.size()){
        int posfi = rightPos[k].fi;
        int posse = rightPos[k].se;
        if(!posfi && !posse) continue;
        FOR(i, max(1, 1 - posfi), min(numRow, numRow - posfi))
        FOR(j, max(1, 1 - posse), min(numCol, numCol - posse))
        g[i][j] = max(g[i][j] ,f[i + posfi][j + posse] + a[i][j]);
        if(k == rightPos.size() - 1 || (k < rightPos.size() && cmp(rightPos[k], rightPos[k + 1])))
            FOR(i, 1, numRow) FOR(j, 1, numCol) f[i][j] = g[i][j];
    }
    long long sum = 0;
    int cntPositive = 0;
    FOR(i, 1, numRow) FOR(j, 1, numCol)
        if(a[i][j] > 0){
            cntPositive++;
            sum += a[i][j];
        }
    FOR(i, 1, numRow) FOR(j, 1, numCol){
        if(cntPositive > 2 || f[i][j] != sum) best = max(best, f[i][j]);
    }
    return best;
}
void readfile(){
    FASTIO
    freopen("BONUS.INP", "r", stdin);
    freopen("BONUS.OUT", "w", stdout);
    cin >> numRow >> numCol;
    FOR(i, 1, numRow) FOR(j, 1, numCol) cin >> a[i][j];
    FOR(i, 1, numRow) FOR(j, 1, numCol){
        //if(abs(1 - i) == abs(i - 1) && abs(1 - j) == abs(j - 1)) continue;
        rightPos.push_back({i - 1, j - 1});
        rightPos.push_back({i - 1, 1 - j});
        rightPos.push_back({1 - i, j - 1});
        rightPos.push_back({1 - i, 1 - j});
    }
    sort(ALL(rightPos), cmp);
    long long ans = findAns();
    FOR(i, 1, numRow) FOR(j, 1, numCol) a[i][j] = - a[i][j];
    long long best = findAns();
    cout << max(best, ans);
}
int32_t main(){
    readfile();
    return 0;
}
