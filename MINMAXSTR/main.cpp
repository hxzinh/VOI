#include <bits/stdc++.h>

using namespace std;
int n, m;
int a[10005];

int main()
{
    freopen("MUAKEO.INP", "r", stdin);
    freopen("MUAKEO.OUT", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++) if(a[i] > a[j]) {
            int tam = a[i];
            a[i] = a[j];
            a[j] = tam;
        }
    }
    int res = 0;
    for(int i = 1; i <= n; i++){
        if(m >= a[i]){
            res++;
            m -= a[i];
        } else break;
    }
    cout << res << '\n' << m;
    return 0;
}
