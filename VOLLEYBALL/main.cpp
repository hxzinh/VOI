#include <bits/stdc++.h>
#define ll long long
#define oo 99999999999
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
int k;

void readfile(){
    freopen("VOLLEYBALL.INP", "r", stdin);
    freopen("VOLLEYBALL.OUT", "w", stdout);
    cin >> k;
    for(int i = 1; i <= k; i++){
        int a, b, t;
        cin >> t >> a >> b;
        int ansA = t - a + (t - b > 2 ? 0 : 2 - (t - b));
        int ansB = t - b + (t - a > 2 ? 0 : 2 - (t - a));
        cout << min(ansA, ansB) << " ";
    }
}
int main()
{
    FastIO
    readfile();
    return 0;
}
