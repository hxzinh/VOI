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

const int NM = 1e5 + 10;
int n;
string s;
int f[NM];

int Mex(vectorint U){
    int res = 0;
    sort(ALL(U));
    for(int x  U) if(x == res) res++;
    return res;
}
int getVal(int u){
    if(f[u] > -1) return f[u];
    int res = 0;
    vector<int> U;
    for(int i = u + 1; i <= n; i++){
        if(s[i] != '0') break;
    }
}
void xuli(){
    memset(f, -1, (n + 1)*sizeof(int));
}
int main()
{
    FastIO
    while(T--){
        cin >> s;
        n = s.size();
        s = '$' + s;

        xuli();
    }
    return 0;
}
