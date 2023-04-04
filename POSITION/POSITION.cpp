#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e5 + 10;
int n, m;
vector<int> ans, p;

vector<int> operator * (const vector<int> &A, const vector<int> &B){
    vector<int> c;
    c.resize(n);
    for(int i = 0; i < n; i++) c[i] = B[A[i]];
    return c;
}
vector<int> Calc(int x){
    if(x == 1) return p;
    vector<int> t = Calc(x / 2);
    if(x % 2 == 0) return t * t;
    else return t * t * p;
}
int main()
{
    FastIO
    freopen("POSITION.INP", "r", stdin);
    freopen("POSITION.OUT", "w", stdout);
    cin >> n >> m;
    p.resize(n);
    for(int i = 0; i < n; i++) cin >> p[i];

    ans = Calc(m);
    for(int u : ans) cout << u << " ";
    return 0;
}
