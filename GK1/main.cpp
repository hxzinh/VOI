#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b, c, n;
    cin >> a >> b >> c >> n;
    a += n / 3600;
    int tam = n / 3600;
    b += (n - tam) / 60;
    int k = (n - tam) / 60;
    c += (n - tam * 3600 - k * 60) / 60;
    cout << a << " " << b << " " << c;
    return 0;
}
