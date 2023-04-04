#include <bits/stdc++.h>

using namespace std;
int n, kqua = n;

int main()
{
    ///freopen("LUUTRU.INP", "r", stdin);
    ///freopen("LUUTRU.OUT", "w", stdout);
    cin >> n;
    cout << "Tap cac uoc so cua " << n << " la: ";
    for(int i = 1; i <= n / 2; i++){
        if(n % i == 0){
            cout << i << ", ";
            kqua = kqua + i;
        }
    }
    cout << n << '\n';
    cout << "Tong uoc cua " << n << " la " << kqua;
    return 0;
}
