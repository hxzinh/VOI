#include <bits/stdc++.h>
#define ll long long
#define oo 99999999999
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM = 2e3 + 10;
int sub, n, T;
int p[NM], next[NM];

void xuli(){

}
void readfile(){
    freopen("RECOVER.INP","r",stdin);
    freopen("RECOVER.OUT","w",stdout);
    cin >> sub >> T;
    while(T--){
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> p[i];
        }
    }
}
int main()
{
    FastIO
    cout << "Hello world!" << endl;
    return 0;
}
