#include <bits/stdc++.h>
#define ll long long
#define oo 99999999999
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM = 2e5 + 10;
int n, k, cnt = 0;
int a[NM];

struct Data {
    int bin, cnt;
};
Data t[NM];

void readfile(){
    freopen("BITSTR.INP", "r", stdin);
    freopen("BITSTR.OUT", "w", stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        char u; cin >> u;
        if(int(u - 48) != t[cnt].bin) t[++cnt].bin = int(u - 48);
        t[cnt].cnt++;
    }
}
void xuli(){
    for(int i = 1; i <= cnt; i++) cout << t[i].cnt << " ";
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
