#include <bits/stdc++.h>

using namespace std;
int n;

int main()
{
    int s = 0;
    cin >> n;
    for(int i = 1; i <= n / 2; i++)
        if(n % i == 0) s = s + i;
    if(s > n) cout << s;
    else cout << 0;
    return 0;
}
