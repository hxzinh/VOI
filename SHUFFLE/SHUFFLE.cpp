#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define ALL(v) (v).begin(), (v).end()
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e5 + 10;
int n, k, t;
vector<int> val, sw;

void readfile(){
    freopen("SHUFFLE.INP", "r", stdin);
    freopen("SHUFFLE.OUT", "w", stdout);
    cin >> n >> k >> t;
    for(int i = 1; i <= n; i++) val.push_back(i);
}
void xuli(){
    sw.insert(sw.begin(), ALL(val));
    for(int i = 1; i <= t; i++){
        int l, m, d;
        cin >> l >> m >> d;
        sw.erase(sw.begin() + l - 1, sw.begin() + l + m - 1);
        sw.insert(sw.begin() + d - 1, val.begin() + l - 1, val.begin() + l + m - 1);
        val.clear();
        val.insert(val.begin(), ALL(sw));
    }
    for(int i = 0; i < k; i++) cout << sw[i] << " ";
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
