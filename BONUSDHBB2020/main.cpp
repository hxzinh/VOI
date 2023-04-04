#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define MASK(x) (1LL << (x))
#define BIT(i, x) ((x) >> (i) & 1)
#define ALL(v) (v).begin(), (v).end()
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1205;
int n, m;
int result = -INF;
int a[NM][NM], s[NM];
int trace[NM], b[NM];

void backtrack(int x){
    if(x > m){
        int tmp = INF;
        for(int i = 1; i <= n; i++) minimize(tmp, s[i]);
        if(maximize(result, tmp))
            for(int i = 1; i <= n; i++) trace[i] = b[i];
        return;
    }
    for(int i = 1; i <= n; i++){
        s[i] += a[i][x];
        int curMask = b[i];
        b[i] |= MASK(x - 1);
        backtrack(x + 1);
        s[i] -= a[i][x];
        b[i] = curMask;
    }
    return;
}
void sub1(){
    backtrack(1);
    cout << result << '\n';
    for(int i = 1; i <= n; i++){
        cout << __builtin_popcount(trace[i]) << " ";
        for(int u = 1; u <= m; u++) if(BIT(u - 1, trace[i])) cout << u << " ";
        cout << '\n';
    }
}
void sub2{

}

int main()
{
    FastIO
    freopen("BONUS.INP", "r", stdin);
    freopen("BONUS.OUT", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) cin >> a[i][j];

    sub1();
    return 0;
}
