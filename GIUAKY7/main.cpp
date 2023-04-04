#include <bits/stdc++.h>

using namespace std;
int n;
double x;

int main()
{
    cin >> n >> x;
    double tam = 1, s = 0;
    for(int i = 1; i <= n; i++){
        tam = tam * x;
        s = s + tam;
    }
    cout << s;
    return 0;
}
