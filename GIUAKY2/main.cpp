#include <bits/stdc++.h>

using namespace std;
int a, b, x;
double s1, s2, s3;

int main()
{
    ///freopen("DIENTICH.INP", "r", stdin);
    ///freopen("DIENTICH.OUT", "w", stdout);
    cin >> a >> b >> x;
    s1 = float(a * x) / 2;
    s2 = float(x) * float(b - x) / 2;
    s3 = float(b) * float(a - x) / 2;
    double kqua = (a * b) - (s1 + s2 + s3);
    cout << fixed << setprecision(1) << kqua;
    return 0;
}
