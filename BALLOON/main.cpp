#include <bits/stdc++.h>
#define ll long long
#define oo 99999999999
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM = 2e5 + 10;
int n, m, k;
int a[NM];
int s[NM][205];

void readfile(){
    freopen("BALLOON.INP", "r", stdin);
    freopen("BALLOON.OUT", "w", stdout);
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= k; j++) s[i][j] = 0;
}
void xuli(){

}
int main()
{
    FastIO
    cout << "Hello world!" << endl;
    return 0;
}
