#include <bits/stdc++.h>
#define int long long
#define INF 1e18
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void sub1(){
    int cnt = 0;
    int n, m, l, r;
    cin >> n >> m >> l >> r;
    /**
    for(int i = l; i <= r; i++){
        if(i % n == 0 || i % m == 0) cnt++;
    }
    **/

    int numL = (r / n) - (l / n);
    int numR = (r / m) - (l / m);
    int bc = (n == m ? n : n * m);
    int numX = (r / bc) - (l / bc);
    cout << numL + numR - numX;
}
void readfile(){
    freopen("LUCKY.INP", "r", stdin);
    freopen("LUCKY.OUT", "w", stdout);
    sub1();
}
int32_t main()
{
    FastIO
    readfile();
    return 0;
}
