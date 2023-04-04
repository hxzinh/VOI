#include <bits/stdc++.h>
#define ll long long
#define oo 99999999999
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM = 1e6 + 10;
int n,k;
int d[NM];
bool ok[NM];

void readfile(){
    freopen("RUN.INP","r",stdin);
    freopen("RUN.OUT","w",stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> d[i];
    }
    memset(ok, false, sizeof(ok));
}
void xuli(){
    if(k == n){
        cout << n << '\n';
        for(int i = 1; i <= n; i++) cout << i << " ";
        return;
    }
    int res = 0, dem = -1;
    d[0] = d[n];
    for(int i = 1; i <= n; i++){
        if(d[i] < d[i - 1]){
            ok[i] = true;
            res++;
            dem++;
        }
    }
    if(dem > k) {cout << 0; return;}
    cout << res << '\n';
    for(int i = 1; i <= n; i++){
        if(ok[i]) cout << i << " ";
    }
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
