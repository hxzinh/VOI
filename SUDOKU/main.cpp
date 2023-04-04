#include <bits/stdc++.h>

#define ii pair<int,int>
#define fi first
#define se second

using namespace std;
int demh[10][10];
int demc[10][10];
int ha , co;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("sudoku.INP","r",stdin);
    freopen("sudoku.OUT","w",stdout);

    for(int i = 1 ;i <= 9 ; i++)
    for(int j = 1 ;j <= 9 ; j++)
    {
        char u;
        cin >> u;
        demh[i][u-'0']++;
        demc[j][u-'0']++;
        if(demh[i][u-'0'] == 2 ) ha = i;
        if(demc[j][u-'0'] == 2 ) co = j;
    }

    cout<<ha<<" "<<co<<" ";
    for(int i = 1 ; i <= 9 ; i++) if(demh[ha][i] == 0)
    {
        cout<<i;
        return 0;
    }
    return 0;
}