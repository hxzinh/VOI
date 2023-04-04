#include <bits/stdc++.h>
#define ll long long
#define oo 99999999999
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
int n;
int a[105], s[105][105];

void readfile(){
    ///freopen("XORTABLE.INP", "r", stdin);
    ///freopen("XORTABLE.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
}
void xuli(){
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) s[i][j] = a[i] ^ a[j];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) cout << s[i][j] << " ";
        cout << '\n';
    }
}
int main()
{
    FastIO
    readfile();\
    xuli();
    return 0;
}
