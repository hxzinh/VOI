#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    long long sum = 0;
    for(int i = 1; i <= n / 2; i++){
        if(n % i == 0) sum += i;
    }
    if(sum == n) cout << n << " la so hoan hao";
    else cout << n << " khong phai so hoan hao";
    return 0;
}
