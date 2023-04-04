#include <bits/stdc++.h>

using namespace std;
int n;
long long a[105];
bool cx = true;

int main()
{
    ///freopen("DAYSO.INP", "r", stdin);
    ///freopen("DAYSO.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = 2; i <= n; i++){
        if(a[i] <= a[i - 1]){
            cout << "FALSE" << '\n' << i;
            cx = false;
            break;
        }
    }
    if(cx == true) cout << "TRUE";
    return 0;
}
