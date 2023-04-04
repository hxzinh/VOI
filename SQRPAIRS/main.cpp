#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e7 + 10;
int n;
int cnt[NM];
vector<int> sqr;

void readfile(){
    freopen("SQRPAIRS.INP", "r", stdin);
    freopen("SQRPAIRS.OUT", "w", stdout);
    cin >> n;
}
void sub1(){
    int res = 0;
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            int tmp = i * j;
            if(int(sqrt(tmp)) * int(sqrt(tmp)) == tmp) res++;
        }
    }
    cout << res;
}
void xuli(){
    for(int i = 4; i <= n * (n - 1); i++){
        int tmp = sqrt(i);
        if(tmp * tmp == i) sqr.push_back(i);
    }

    int res = 0, pos = 0;
    for(int i = 1; i <= n; i++){
        for(int u = pos; u < sqr.size(); u++){
            int k = sqr[u] / i;
            if(k > n) break;
            if(k <= i){
                pos++;
                continue;
            }
            if(sqr[u] % i == 0) res++;
        }
    }
    cout << res;
}
int32_t main()
{
    FastIO
    readfile();
    if(n <= 10000) sub1();
    else xuli();
    return 0;
}
