#include <bits/stdc++.h>
#define int long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e7 + 10;
int n;
int f[NM];
bool cx[2 * NM];
vector<int> isPrime;

void readfile(){
    freopen("GOLDBACH.INP", "r", stdin);
    freopen("GOLDBACH.OUT", "w", stdout);
    cin >> n;
}
void xuli(){
    int cnt = 0;
    for(int i = 2; i <= sqrt(20000000); i++) if(!cx[i]) {
        for(int j = i * i; j <= 20000000; j += i) cx[j] = true;
    }

    for(int i = 3; i <= 2 * n; i++) if(!cx[i]){
        cnt++;
        isPrime.push_back(i);
    }

    int res = 1;
    int r = isPrime.size() - 1;
    for (int l = 0; l < isPrime.size(); l++){
        if(l > r) break;
        while (isPrime[l] + isPrime[r] > 2 * n && r >= 0) --r;
        if (r < l) break;
        res += (r - l + 1);
    }
    if(n <= 1) cout << 0;
    else cout << res;
}
int32_t main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
