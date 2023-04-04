#include <bits/stdc++.h>
#define int long long
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

const int NM = 1e6 + 10;
int n;
int a[NM];
bool cx[NM];
vector<int> isPrime;
queue<int> q;

void Prime(){
    for(int i = 2; i <= min(int32_t(sqrt(n)), 1000); i++) if(!cx[i]) {
        for(int j = i * i; j <= min(n, 1000000LL); j += i) cx[j] = true;
    }

    for(int i = 2; i <= min(n, 1000000LL); i++) if(!cx[i]) isPrime.push_back(i);
}
void xuli(){
    Prime();

    for(int u : isPrime) if(n % u == 0){
        q.push(u);
        while(n % u == 0) n /= u;
        if(n <= 1) break;
    }

    while(q.size()){
        cout << q.front() << " ";
        q.pop();
    }

    if(n > 1) cout << n;
}
int32_t main()
{
    FastIO
    cin >> n;

    xuli();
    return 0;
}
