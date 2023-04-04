#include <bits/stdc++.h>
#define int unsigned long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e6 + 10;
const int MOD = 998244353;
int T, n;
int a[NM], b[NM];
bool isPrime[NM];
vector<int> prime;

void add(int &a, int b){
    if(a + b >= MOD) a += b - MOD;
    else a += b;
}
void readfile(){
    freopen("PRIMELCM.INP", "r", stdin);
    freopen("PRIMELCM.OUT", "w", stdout);
    cin >> T;
}
int ucln(int a, int b){
    while(a % b != 0){
        int tam = a % b;
        a = b;
        b = tam;
    }
    return b;
}
void progress(){
    memset(isPrime, true, sizeof(isPrime));
    isPrime[1] = false;
    for(int i = 2; i <= sqrt(1000000); i++){
        for(int j = i * i; j <= 1000000; j += i) isPrime[j] = false;
    }
    ///for(int i = 2; i <= 1000000; i++) if(isPrime[i]) prime.push_back(i);

    a[0] = 1;
    for(int i = 1; i <= 1000000; i++) a[i] = (a[i - 1] * (isPrime[i] == true ? i : 1));
    b[1] = 1;
    for(int i = 2; i <= 1000000; i++) b[i] = ((b[i - 1] * i)) / ucln(b[i - 1], i);
}
void xuli(){
    progress();
    while(T--){
        cin >> n;
        cout << (b[n] / a[n]) % MOD << " ";
    }
}
int32_t main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
