#include <bits/stdc++.h>

using namespace std;

int a[1000005];

int main(){
    int n; cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    int best = -1000000005, secon = -1000000005;
    for(int i = 1; i <= n; i++){
        if(a[i] > best){
            secon = best;
            best = a[i];
        }
        else if(a[i] > secon) secon = a[i];
    }
    if(secon == -1000000005) cout << "NOT FOUND";
    else cout << secon;

    return 0;
}

