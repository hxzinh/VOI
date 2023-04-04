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

const int NM = 1e5 + 10;
int n, k;
int a[NM];
string s;

int toOct(string u){
    int res = 0, cnt = 0;
    for(int i = k - 1; i >= 0; i--){
        if(u[i] == '1') res |= MASK(cnt);
        cnt++;
    }

    return res;
}
void sub12(){
    int res = INF;
    for(int mask = 0; mask < MASK(k); mask++){
        int ans = 0;
        for(int i = 1; i <= n; i++){
            int tmp = mask ^ a[i];
            maximize(ans, __builtin_popcount(tmp));
        }
        minimize(res, ans);
    }
    cout << res;
}
int main()
{
    FastIO
    freopen("STONE.INP", "r", stdin);
    freopen("STONE.OUT", "w", stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> s;
        a[i] = toOct(s);
        //cout << a[i] << '\n';
    }

    sub12();
    return 0;
}
