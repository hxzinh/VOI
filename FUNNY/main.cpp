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

const int NM = 3e5 + 10;
int n, m;
int a[NM], s[NM];

void sub1() {
    int res = 0;
    for(int i = 1; i < n; i++){
        for(int j = i + 1; j <= n; j += 2){
            int m = (i + j) / 2;
            if(s[m] ^ s[i - 1] == s[j] ^ s[m]) res++;
        }
    }
    cout << res;
}
void xuli(){
    int res = 0;
    for(int k = 1; k <= n / 2; k++){
        for(int i = k; i + k <= n; i++){
            if(s[i] ^ s[i - k] == s[i] ^ s[i + k]) res++;
        }
    }
    cout << res;
}
int main()
{
    FastIO
    freopen("FUNNY.INP", "r", stdin);
    freopen("FUNNY.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = 1; i <= n; i++) s[i] = s[i - 1] ^ a[i];

    sub1();
    return 0;
}
