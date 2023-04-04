#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int MOD = 1e9 + 7;
int T, n, k;
int f[11][1000005];

void add(int &a, int b){
    if(a + b >= MOD) a += b - MOD;
    else a += b;
    return;
}
void readfile(){
    freopen("TASKSELECT.INP", "r", stdin);
    freopen("TASKSELECT.OUT", "w", stdout);
    cin >> T;
}
void sub1(){
    f[0][0] = 1;
    for(int i = 0; i < 10; i++){
        for(int sum = 0; sum <= 100; sum++) if(f[i][sum] > 0){
            for(int j = sum + 1; j <= 1000; j++) add(f[i + 1][sum + j], f[i][sum]);
        }
    }

    while(T--){
        cin >> k >> n;
        cout << f[k][n] << '\n';
    }
}
int main()
{
    FastIO
    readfile();
    sub1();
    return 0;
}
