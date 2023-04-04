#include <bits/stdc++.h>

using namespace std;

int n, T;
int a[15], s[15];

int main()
{
    cin >> T;
    a[0] = 1; s[0] = 1;
    for(int i = 1; i <= 11; i++) a[i] = a[i - 1] * 3;
    for(int i = 1; i <= 11; i++) s[i] = s[i - 1] + a[i];
    while(T--){
        cin >> n;
        int res = 0;
        while(n > 0){
            for(int i = 0; i <= 12; i++){
                if(s[i] >= n){
                    res += a[i];
                    n -= a[i];
                    break;
                }
            }
        }
        cout << res << '\n';
    }
    return 0;
}
