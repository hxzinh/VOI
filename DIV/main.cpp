#include <bits/stdc++.h>
#define ll long long
#define oo 99999999999
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
string s;
bool cx[11],ok[11];
int res=0,sum=0;

void prepare(string x,int tong){
    memset(cx,false,sizeof(cx));
    ///cx[0]=true;
    cx[1]=true; /// chia het cho 1
    int pos=x.length()-1;
    int tam=2,k=10;
    int t = int(s[pos]-48);
    if(t % 5 == 0) cx[5]=true; /// chia het cho 5
    if(t % 2 == 0) cx[2]=true; /// chia het cho 2
    t = int(s[--pos] - 48)*10 + t;
    if(t % 4 == 0) cx[4]=true; /// chia het cho 4
    t = int(s[--pos] - 48)*100 + t;
    if(t % 8 == 0) cx[8]=true; /// chia het cho 8
    if(tong % 3 == 0) cx[3]=true; /// chia het cho 3
    if(cx[2] && cx[3]) cx[6]=true; /// chia het cho 6
    if(tong % 9 == 0) cx[9]=true; /// chia het cho 9
    int u=0;
    for(int i=0;i<x.length();i++){
        u=u*3+int(x[i]-48);
        while(u > 7) u-=7;
    }
    if(u % 7 == 0) cx[7]=true; /// chia het cho 7
}
void readfile(){
    freopen("div.inp","r",stdin);
    freopen("div.out","w",stdout);
    cin >> s;
    if(s[0] == '-') s.erase(s.begin());
    for(int i=0;i<s.length();i++) sum+=int(s[i]-48);
    prepare(s,sum);
    for(int i=0;i<s.length();i++){
        int t = int(s[i]-48);
        if(cx[t]) res++;
    }
    cout << res;
}
int main()
{
    FastIO
    readfile();
    return 0;
}
