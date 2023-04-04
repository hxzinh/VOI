#include <bits/stdc++.h>
#define ll long long
#define oo 99999999999
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM = 150;
string k;

void readfile(){
    freopen("easy.inp","r",stdin);
    freopen("easy.out","w",stdout);
    cin >> k;
}
void xuli(){
    string s;
    int d = 0, dem = 0;
    while(true){
        if(dem > 2 || dem == k.length()) break;
        d = d*10 + int(k[dem]-48);
        dem++;
    }
    while(cin >> s){
        if(k.length() > 3 || d > 100) cout << s << " ";
        else{
            if(s.length() > d) cout << s[0] << s.length()-2 << s[s.length()-1] << " ";
            else cout << s << " ";
        }
    }
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
