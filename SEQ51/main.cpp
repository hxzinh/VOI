#include <bits/stdc++.h>
#define ll long long
#define oo 99999999999
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM = 1e5 + 10;
int n;
int a[NM];

void readfile(){
    ///freopen("SEQ.INP", "r", stdin);
    ///freopen("SEQ.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
}
void xuli(){
    int res = 0;
    for(int i = 1; i < n; i++){
        int cnt = 1;
        int ans = a[i];
        for(int j = i + 1; i <= n; j++){
            if(a[j] < cnt + 1) break;
            else cnt++;
        }
        res = max(res, cnt);
    }
    cout << res;
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
