#include <bits/stdc++.h>

using namespace std;

int n, a[105];
bool cx[105];

void IN(){
    for(int i = 1; i <= n; i++) cout << a[i] << " ";
    cout << '\n';
}
void Dem(){
    int dem = 0;
    for(int i = 1; i <= n; i++)
        if(a[i] % 2 == 0){
            dem++;
            cx[i] = true;
        }
    cout << dem << '\n';
    for(int i = 1; i <= n; i++) if(cx[i]) cout << a[i] << " ";
    cout << '\n';
}
void Chanlonnhat(){
    int u = -1;
    for(int i = 1; i <= n; i++) u = max(u, a[i]);
    cout << u << '\n';
}
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

    IN();
    Dem();
    Chanlonnhat();
    return 0;
}
