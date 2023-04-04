#include <bits/stdc++.h>
#define ll long long
#define oo 99999999999
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM = 1e3 + 10;
int n, k;
int a[NM];
map<int, int> cnt;

void readfile(){
    freopen("WATER.INP", "r", stdin);
    freopen("WATER.OUT", "w", stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
}
void xuli(){
    ll res = 0;
    for(int i = 1; i <  n; i++){
        for(int j = i + 1; j <= n; j++) res += cnt[k - a[i] - a[j]];
        for(int j = 1; j < i; j++) cnt[a[i] + a[j]]++;
    }
    cout << (res > 0 ? res : 0);
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
