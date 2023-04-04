#include <bits/stdc++.h>
#define int long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 4e5 + 10;
int n, k;
int c[10];

void readfile(){
    freopen("SQUARES.INP", "r", stdin);
    freopen("SQUARES.OUT", "w", stdout);
    cin >> k;
}
void xuli(){
    int cnt = 0;
    bool ok = true;
    for(int i = 1; i <= n; i++){
        memset(c, 0, sizeof(c));
        ok = true;
        int x = i * i;
        while(x != 0){
            c[x % 10]++;
            if(c[x % 10] > 1){ok = false; break;}
            else x /= 10;
        }
        if(ok) cnt++;
        if(cnt == k){
            cout << i * i;
            break;
        }
    }
}
int32_t main()
{
    FastIO
    readfile();
    if(k > 610) cout << -1;
    else xuli();
    return 0;
}
