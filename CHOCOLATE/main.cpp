#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 2e5 + 10;
int n, m, k, x0, y0;
vector<int> road[1005][1005];

int Change(char u){
    if(u == 'L') return 0;
    if(u == 'R') return 1;
    if(u == 'U') return 2;
    if(u == 'D') return 3;
}
void xuli(){

}
void readfile(){
    freopen("CHOCOLATE.INP", "r", stdin);
    freopen("CHOCOLATE.OUT", "w", stdout);
    cin >> n >> m >> k >> x0 >> y0;
    for(int i = 1; i <= k; i++){
        char u; cin >> u;
        int v = Change(u);
        if(v == 1) {
            road[x0][y0].push_back(v)
    }
}
int main()
{
    FastIO
    cout << "Hello world!" << endl;
    return 0;
}
