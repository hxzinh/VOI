#include <bits/stdc++.h>

using namespace std;
int main(){    freopen("NKMAXSEQ.in","r",stdin);    int n, p, x;
    int u[50001], Id[50001];    cin >> n >> p;    int min = 0, imin = 0;    u[0] = 0;    for(int i = 1;i<=n;i++)    {        cin >> x;        u[i] = u[i - 1] + x;        //prefix sum        if(u[i]<min) {            min = u[i];            imin = i;        }        Id[i] = imin;               //id of minium 1 -> i    }    int i = Id[n], j = n, t = 0;    while(true){
        while(i < j && j - i > t && u[j] - u[i] < p) j--;        if(j - i > t)            t = j - i;        if(i == 0) break;        i = Id[i - 1];    }    if(t==0)       printf("-1");    else printf("%d",t);   // getch();}