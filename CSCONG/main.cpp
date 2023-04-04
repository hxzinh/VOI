#include <bits/stdc++.h>
#define int long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 3e3 + 10;
int n;
int a[NM], f[NM][NM], s[NM];

void readfile(){
    freopen("INP", "r", stdin);
    freopen("OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
}
void sub1(){
    int res = 0;
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++) if(a[j] > a[i]) {
            int d = a[j] - a[i];
            int dist = 2;
            int tam = a[j];
            for(int k = j + 1; k <= n; k++){
                if(a[k] - tam == d){
                    dist++;
                    tam = a[k];
                }
            }
            maximize(res, dist);
        }
    }
    cout << res;
}
void sub2(){
    for(int i = 1; i <= n; i++)
        for(int d = 1; d <= 1000; d++) f[i][d] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j < i; j++) if(a[i] > a[j]) {
            maximize(f[i][a[i] - a[j]], f[j][a[i] - a[j]] + 1);
        }
    }

    int res = 0;
    for(int d = 1; d <= 1000; d++)
        for(int i = 1; i <= n; i++) maximize(res,f[i][d]);
    cout << res;
}
int32_t main()
{
    FastIO
    readfile();
    if(n <= 100) sub1();
    else sub2();
    return 0;
}
