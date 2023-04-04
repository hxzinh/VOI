#include <bits/stdc++.h>
#define ii pair<int,int>
#define fi first
#define se second

using namespace std;

int V[600005], D[600005];
int n,m;
int tren, duoi, trai, phai, bx, by;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("exper.inp","r",stdin);
    freopen("exper.out","w",stdout);

    cin >> n >> m;

    int x = 300000;
    int y = 300000;

    long long S = 0;
    for(int i = 1; i <= n; i++)
    {
        int u,v;
        cin >> u >> v;
        u = u + 300000;
        v = v + 300000;
        V[u]++;
        D[v]++;
        S = S + abs(u-x) + abs(y-v);
        if(u < x) duoi++;
        if(u > x) tren++;
        if(u == x) bx++;

        if(v > y) phai++;
        if(v < y) trai++;
        if(v == y) by++;
    }

    while(m--)
    {
        char t;
        cin >> t;
        if(t == 'N')
        {
            trai += by;
            S = S + trai;
            y++;
            by = D[y];
            S = S - phai;
            phai -= by;
        }
        if(t == 'S')
        {
            phai += by;
            S = S + phai;
            y--;
            by = D[y];
            S = S - trai;
            trai -= by;
        }

        if(t == 'E')
        {
            duoi += bx;
            S = S + duoi;
            x++;
            bx = V[x];
            S = S - tren;
            tren -= bx;
        }
        if(t == 'W')
        {
            tren += bx;
            S = S + tren;
            x--;
            bx = V[x];
            S = S - duoi;
            duoi -= bx;
        }

        cout << S << '\n';
    }


    return 0;
}