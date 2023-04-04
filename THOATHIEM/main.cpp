#include <bits/stdc++.h>
#define INF 1e9
#define int long long
#define FASTIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
int n, m, p;

void readfile(){
    freopen("THOATHIEM.INP", "r", stdin);
    freopen("THOATHIEM.OUT", "w", stdout);
    cin >> n >> m >> p;
}
void sub12(){
    vector<int> a;
    int cnt = 0;
    for(int i = n + 1; i <= m; i++){
        if(i % p == 0 && i >= p) a.push_back(i);
    }

    int u = n, res = 0;
    while(!a.empty()){
        int nxt = a[0];
        if(nxt - u <= 1){
            res++;
            a.erase(a.begin());
            u += 2;
            continue;
        }
        int dis = nxt - u;
        res += dis / 2 + 1;
        u += dis + 1;
    }
    int dis = m - u;
    if(dis % 2 != 0) res += dis / 2 + 1;
    else res += dis / 2;
    cout << res;
}
void full(){
    int cnt = (m / p) - (n / p);
    int res = 0;
    res += (cnt - 1) * (p % 2 == 0 ? p / 2 : p / 2 + 1);
    int k = (p > n ? p : p * (n / p + 1));
    res += (k - n) / 2 + 1;
    k = p * (m / p) + 1;
    res += (m - k) % 2 == 0 ? (m - k) / 2 : (m - k) / 2 + 1;
    cout << res;
}
int32_t main()
{
    FASTIO
    readfile();
    full();
    return 0;
}
