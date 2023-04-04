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

const int NM = 5e4 + 10;
int n, k;
pii a[NM], ans;
double result = 0, mid = 1.00;


int getRand(int l, int r){
    return rand() % (r - l + 1) + l;
}
void backtrack(int x, int cnt, int sum, int cost){
    if(x > n){
        if(cnt == k){
            if(maximize(result, double((sum * 1.00) / (cost * 1.00)))){
                int u = __gcd(sum, cost);
                ans.fi = sum / u; ans.se = cost / u;
            }
        }
        return;
    }
    backtrack(x + 1, cnt, sum, cost);
    backtrack(x + 1, cnt + 1, sum + a[x].fi, cost + a[x].se);
    return;
}
void sub1(){
    backtrack(1, 0, 0, 0);
    cout << ans.fi << " " << ans.se;
}
bool cmp(const pii &A, const pii &B){
    return (A.fi - A.se * mid) > (B.fi - B.se * mid);
}
bool check(double x){
    sort(a + 1, a + n + 1, cmp);
    int cnt = 0;
    int sum = 0, cost = 0;
    for(int i = 1; i <= n; i++){
        int newSum = sum + a[i].fi;
        int newCost = cost + a[i].se;
        if(cnt == k) break;
        if(cnt < k){
            cnt++;
            sum = newSum;
            cost = newCost;
        }
    }

    int u = __gcd(sum, cost);
    ans.fi = sum / u; ans.se = cost / u;
    db res = db(sum) - db(cost) * x;
    return res >= 0;
}
void xuli(){
    pii trace;
    db l = 0, r = 1e9;
    for(int i = 0; i < 70; i++){
        mid = (l + r) / 2.00;
        if(check(mid)) {
            l = mid;
            trace = ans;
        } else r = mid;
    }
    cout << trace.fi << " " << trace.se;
}
int32_t main()
{
    FastIO
    freopen("DIAMOND.INP", "r", stdin);
    freopen("DIAMOND.OUT", "w", stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i].fi >> a[i].se;
    }

    //for(int i = 1; i <= n; i++) cout << getRand(10, 100) << " " << getRand(10, 100) << '\n';

    if(n <= 20) sub1();
    else xuli();
    return 0;
}
