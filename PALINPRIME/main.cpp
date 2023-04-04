#include <bits/stdc++.h>
#define ll long long
#define oo 99999999999
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM = 1e7 + 10;
int l, r;
bool cx[NM];
vector<int> snt;

void readfile(){
    freopen("PALINPRIME.INP", "r", stdin);
    freopen("PALINPRIME.OUT", "w", stdout);
    cin >> l >> r;
}
void prime(){
    cx[1] = true;
    for(ll i = 2; i <= sqrt(r); i++){
        for(ll j = i * i; j <= r; j += i) cx[j] = true;
    }
}
bool check(int x){
    string a = "";
    a += char(x % 10 + 48);
    x /= 10;
    while(x != 0){
        a += char(x % 10 + 48);
        x /= 10;
    }
    for(int d = 0, c = a.length() - 1; d < c; d++, c--){

        if(a[d] != a[c]) return false;
    }
    return true;
}
void xuli(){
    prime();
    ll res = 0;
    for(int i = l; i <= r; i++){
        if(!cx[i]){
           if(check(i)) res += i;
        }
    }
    cout << res;
}
int32_t main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
