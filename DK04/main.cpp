#include <bits/stdc++.h>
#define ll long long
#define oo 99999999999
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main()
{
    FastIO
    double n, b;
    int a;
    cin >> n;
    a = n;
    b = 0.5 + a;
    if(a < b) cout << a + 1;
    else cout << a;
    return 0;
}
