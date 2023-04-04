#include <bits/stdc++.h>
#define ll int
#define INF 1e8
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM = 1e6 + 10;
int n, numPrime = 0;
int a[NM]; ll s[NM];
bool cx[NM];
vector<int> isPrime;

void readfile(){
    freopen("EASYTASK.INP", "r", stdin);
    freopen("EASYTASK.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
}
void progress(int x){
    memset(cx, true, (x + 7) * sizeof(bool));
    cx[1] = false;
    for(int i = 2; i <= sqrt(x); i++){
        if(cx[i]){
            for(int j = i * i; j <= x; j += i)
                cx[j] = false;
        }
    }
    for(int i = 1; i <= x; i++)
        if(cx[i]) isPrime.push_back(i);
    numPrime = isPrime.size() - 1;
}
void xuli(){
    progress(n);
    int minn = INF, res = -INF;
    for(int u : isPrime){
        minn = min(minn, s[u - 1]);
        res = max(res, s[u] - minn);
    }
    cout << res;
}
int32_t main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
