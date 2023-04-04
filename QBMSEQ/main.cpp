#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define pii pair<int, int>
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

const int NM = 1e4 + 10;
int n;
int T[NM];
pii a[NM];

bool check(int x){
    int t = sqrt(2 * x);
    if(t * (t + 1) / 2 == x) return true;
    else return false;
}
void xuli(){
    int res = 0, cnt = 0;
    for(int i = 1; i <= n; i++){
        if(check(a[i].fi)){
            if(a[i] >= a[i - 1]) cnt++;
            else cnt = 1;
        } else cnt = 0;
        maximize(res, cnt);
    }
    cout << res;
}
int main()
{
    FastIO
    freopen("QBMSEQ.INP", "r", stdin);
    freopen("QBMSEQ.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i].fi;
        a[i].se = i;
    }

    xuli();
    return 0;
}
