#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b, c, n;
    cin >> a >> b >> c >> n;
    c += n;
    if(c >= 60){
        b += c / 60;
        c = c % 60;
    }
    if(b >= 60){
        a += b / 60;
        b = b % 60;
    }
    cout << a << " " << b << " " << c;
    return 0;
}
