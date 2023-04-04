#include <bits/stdc++.h>

using namespace std;
int n, m;
bool cx[10005];

int main()
{
    freopen("SONT.INP", "r", stdin);
    freopen("SONT.OUT", "w", stdout);
    cin >> n >> m;
    cx[1] = false;
    for(int i = 2; i <= sqrt(m); i++) if(cx[i] == false) {
        for(int j = i * i; j <= m; j = j + i) cx[j] = true;
    }
    int dem = 0;
    for(int i = n; i <= m; i++){
        if(cx[i] == false){
            cout << i << " ";
            dem++;
        }
        if(dem == 10){
            dem = 0;
            cout << '\n';
        }
    }
    return 0;
}
