#include <bits/stdc++.h>

using namespace std;
float a,b,v;

void readfile()
{
    freopen("ECH.INP","r",stdin);
    freopen("ECH.OUT","w",stdout);
    cin >> a;
    cin >> b;
    cin >> v;
}
void songay()
{
    float ngay;
    ngay=0;
    ngay=v/(a-b);
    if (ngay>trunc(ngay))
    {
        ngay=trunc(ngay)+1;
    }
    cout << ngay;
}
int main()
{
    readfile();
    songay();
    return 0;
}
