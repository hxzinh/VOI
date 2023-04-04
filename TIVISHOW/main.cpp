#include<bits/stdc++.h>
#define int long long
#define INF 1e18

using namespace std;
const int NM = 1e5 + 10;
int n, m, t, k;
int resA = 0, resB = 0;
int a[NM], b[NM];

void readfile(){
    freopen("TIVISHOW.INP", "r", stdin);
    freopen("TIVISHOW.OUT", "w", stdout);
    cin >> n >> m >> t >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= m; i++) cin >> b[i];
}
int findA(int l, int r, int x){
    int res = n;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(a[mid] > b[x]){
            res = mid;
            r = mid - 1;
        } else l = mid + 1;
    }
    return res;
}
int findB(int l, int r, int x){
    int res = m;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(b[mid] > a[x]){
            res = mid;
            r = mid - 1;
        } else l = mid + 1;
    }
    return res;
}
void xuli(){
    a[0] = -k, b[0] = -k;
    int posA = 0, posB = 0;
    bool sta = true, cx = true;
    while(true){
        if(sta){
            sta = false;
            while((a[posA] <= b[posB] && posA <= n + 1) || posA == 0) posA++;
            if(posA > n || a[posA] >= t){
                if(a[posA - 1] + k < t) resA += t - max(b[posB], a[posA - 1] + k);
                break;
            }
            resA += a[posA] - max(b[posB], a[posA - 1] + k);
        } else {
            sta = true;
            while((b[posB] <= a[posA] && posB <= m + 1) || posB == 0) posB++;
            if(posB > m || b[posB] >= t){
                if(b[posB - 1] + k < t) resB += t - max(a[posA], b[posB - 1] + k);
                break;
            }
            resB += b[posB] - max(a[posA], b[posB - 1] + k);
        }
    }
    cout << resA << " " << resB;
}
int32_t main(){
    readfile();
    xuli();
    return 0;
}
