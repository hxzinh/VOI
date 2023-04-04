#include <bits/stdc++.h>
#define ll long long
#define f float
#define d double
#define oo 99999999999
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM=100;
int n;
int k[NM];

void readfile(){
    freopen("divisible.inp","r",stdin);
    freopen("divisible.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++) cin >> k[i];
    sort(k+1,k+n+1);
}
void xuli(){
    double sum=f(0);
    for(int i=1;i<=n;i++){
        sum += f(1)/f(k[i]+1);
    }
    if(sum == 1){
        for(int i=2;i<=n;i++){
            if(k[i] == k[i-1]){
                cout << "NO";
                return;
            }
        }
        cout << "YES";
    }
    if(sum > 1) cout << "NO";
    if(sum < 1) cout << "YES";
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
