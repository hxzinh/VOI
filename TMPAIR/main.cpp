#include <bits/stdc++.h>
#define int long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e6 + 10;
int n;
int t[NM];

void readfile(){
    freopen("TMPAIR.INP", "r", stdin);
    freopen("TMPAIR.OUT", "w", stdout);
    cin >> n;
}
void sub12(){
    int res = 0;
    for(int i = 1; i <= n / 2; i++){
        if((n - i) % i == 0)
            if(i == n - i) res++;
            else res += 2;
    }
    cout << res;
}
void full(){
    vector<int> uoc;
    int tmp = n;
    for(int i = 2; i <= sqrt(n); i++){
        while(tmp % i == 0){
            tmp /= i;
            t[i]++;
        }
        if(n % i == 0) uoc.push_back(i);
    }
    for(int u : uoc) cout << u << " " << t[u] << '\n';
}
int32_t main()
{
    FastIO
    readfile();
    full();
    return 0;
}
