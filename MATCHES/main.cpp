#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 4e4 + 10;
int n, m;
vector<int> a[50], b[50];

void readfile(){
    freopen("MATCHES.INP", "r", stdin);
    freopen("MATCHES.OUT", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            int u; cin >> u;
            if(j <= n / 2) a[i].push_back(u);
            else b[i].push_back(u);
        }
    }
}
int main()
{
    FastIO
    cout << "Hello world!" << endl;
    return 0;
}
