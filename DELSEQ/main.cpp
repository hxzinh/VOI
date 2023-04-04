#include <bits/stdc++.h>
#define int long long
#define INF 1e18
#define MASK(x) (1LL << (x))
#define BIT(x, i) ((x) >> (i) & 1)
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 2e3 + 10;
int n;
int kqua = 0;
int a[NM];
int s[NM][NM], f[NM][MASK(11)];
bool cx[NM];

void readfile(){
    freopen("DELSEQ.INP", "r", stdin);
    freopen("DELSEQ.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
}
void sub2(){
    int res = 0;
    for(int i = 1; i <= n; i++) res += a[i];
    int tmp = res;
    for(int i = 1; i <= n; i++) maximize(res, tmp - a[i]);

    for(int i = 2; i <= n; i += 2){
        int sum = 0;
        for(int j = 1; j <= i; j++) sum += a[j];
        maximize(res, tmp - sum);
        for(int j = i + 1; j <= n; j++){
            sum += a[j] - a[j - i];
            maximize(res, tmp - sum);
        }
    }
    cout << res;
}
void sub3(){
    int len = 0;
    for(int i = 1; MASK(i - 1) <= n; i++) len++;
    for(int i = 0; i <= n; i++)
        for(int mask = 0; mask <= MASK(len - 1); mask++) f[i][mask] = -INF;

    f[0][0] = 0;
    for(int i = 0; i < n; i++){
        for(int mask = 0; mask <= MASK(len - 1); mask++) if(f[i][mask] > -INF){
            maximize(f[i + 1][mask], f[i][mask] + a[i + 1]);
            for(int k = 1; MASK(k - 1) <= n; k++) if(!BIT(mask, k - 1)){
                int newMask = mask | MASK(k - 1);
                if(i + MASK(k - 1) <= n)
                    maximize(f[i + MASK(k - 1)][newMask], f[i][mask]);
            }
        }
    }

    int res = -INF;
    for(int mask = 0; mask <= MASK(len); mask++){
        for(int i = 1; i <= n; i++) maximize(res, f[i][mask]);
    }
    cout << res;
}
int32_t main()
{
    FastIO
    readfile();
    sub3();
    return 0;
}
