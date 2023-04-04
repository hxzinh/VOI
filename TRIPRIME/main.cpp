#include <bits/stdc++.h>
#define ll long long
#define oo 99999999999
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM = 1e8 + 10;
int n, tam;
bool cx[NM];

void readfile(){
    freopen("TRIPRIME.INP", "r", stdin);
    freopen("TRIPRIME.OUT", "w", stdout);
    cin >> n;
    tam = n;
}
void xuli(){
    int cnt = 0;
    for(int i = 2; i <= sqrt(n); i++){
        if(!cx[i]){
            cx[i] = true;
            for(int j = i * i; j <= sqrt(n); j += i) cx[i] = true;
            if(tam % i == 0){
                cnt++;
                while(tam % i == 0) tam /= i;
            }
        }
    }
    if(tam == 1 && cnt == 3 || !cx[tam] && cnt == 2) cout << "YES";
    else cout << "NO";
}
int32_t main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
