#include <bits/stdc++.h>
#define ll long long
#define oo 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
string a,b;
int f[55][55];

void readfile(){
    freopen("ADN.INP","r",stdin);
    freopen("ADN.OUT","w",stdout);
    cin >> a;
    cin >> b;
    for(int i = 1; i <= a.length(); i++)
        for(int j = 1;j <= b.length(); j++) f[i][j] = oo;
    f[0][0] = 0;
}
void xuli(){
    for(int i = 1; i <= a.length(); i++) f[i][0] = i;
    for(int i = 1; i <= b.length(); i++) f[0][i] = i;

    for(int i = 1; i <= a.length(); i++){
        for(int j = 1; j <= b.length(); j++){
            if(a[i - 1] == b[j - 1]) f[i][j] = f[i - 1][j - 1];
            f[i][j] = min(f[i][j], min({f[i - 1][j], f[i][j - 1], f[i - 1][j - 1]}) + 1);
        }
    }
    if(f[a.length()][b.length()] <= 2) cout << "Yes";
    else cout << "No";
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
