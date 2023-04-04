#include <bits/stdc++.h>

using namespace std;

int main()
{
    ///freopen("LUUTRU.INP", "r", stdin);
    ///freopen("LUUTRU.OUT", "w", stdout);
    int n, kqua;
    cin >> n;
    if(n % 1024 == 0) kqua = n / 1024;
    else kqua = n / 1024 + 1;
    cout << kqua;
    return 0;
}
