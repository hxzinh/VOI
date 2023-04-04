#include <bits/stdc++.h>
#define ll long long
#define oo 99999999999
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
ll n;

void readfile()
{
    freopen("LUCK.INP","r",stdin);
    freopen("LUCK.OUT","w",stdout);
    cin >> n;
}
void xuli()
{
    string res="";
    while(n!=0)
    {
        if(n%2==0)
        {
            res='7'+res;
            n=(n-2)/2;
        }
        else
        {
            res='4'+res;
            n=(n-1)/2;
        }
    }
    cout << res;
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
