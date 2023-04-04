#include <bits/stdc++.h>
#define ll long long
#define oo 99999999999
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM=1e6+9;
ll n;
vector <int> divs[NM];
bool cx[NM];

void readfile(){
    freopen("uocso.inp","r",stdin);
    freopen("uocso.out","w",stdout);
    cin >> n;
    memset(cx,true,sizeof(cx));
}
void xuli(){
    for(int i=2;i<sqrt(NM);i++)
    {
       /// if(cx[i])
        for(int j=2*i;j<NM;j+=i)
        {
            cx[j]=false;
            divs[j].push_back(i);
            /**
            for(int u=0;u<divs[j].size();u++)
            {
                ll v=divs[j][u];
                if(i*v<=j/2) divs[j].push_back(i*v);
            }
            **/
        }
    }
    for(int i=0;i<divs[n].size();i++) cout << divs[n][i] << " ";
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
