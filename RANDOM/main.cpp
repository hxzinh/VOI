#include <bits/stdc++.h>
#define ll long long
#define oo 99999999999
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main()
{
    FastIO
    ll u=rand()%(5-3+1)+3;
    if(u==5) cout << "Phu song Bach Dang" << '\n';
    if(u==4) cout << "Nguyen Trai" << '\n';
    if(u==3) cout << "Dai cao binh ngo" << '\n';
    cout << '\n';
    return 0;
}
