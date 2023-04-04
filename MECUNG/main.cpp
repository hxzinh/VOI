#include <bits/stdc++.h>

#define ii pair<int,int>
#define fi first
#define se second

using namespace std;
int n,q;
int a[1004][1004] , cx[1004][1004] , F[1004][1004] , DP[1004][1004];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int Bfs(int x,int y,int ed1,int ed2)
{
    queue <ii> q;
    q.push({x,y});

    F[x][y] = 1;
    while(q.size())
    {
        int x = q.front().fi;
        int y = q.front().se;
        if(x == ed1 && y == ed2)
        {
            return F[ed1][ed2];
        }
        q.pop();
        for(int i = 0 ; i < 4 ; i++)
        {
            int u = x + dx[i];
            int v = y + dy[i];
            if(F[u][v] > F[x][y] + 1 && u <= n && v <= n && a[u][v] != 1 && u > 0 && v > 0)
            {
                DP[u][v] = DP[x][y] + 1;
                F[u][v] = F[x][y] + 1;
                q.push({u,v});
            }
        }
    }
    return -1;
}
void sub1()
{
    while(q--)
    {
        int t;
        cin >> t;
        if(t == 1)
        {
            int u,v;
            cin >> u >> v;
            a[u][v] = 1;
        }
        else
        {
            int u,v,x,y;
            cin >> u >> v >> x >> y;
            for(int i = 1 ; i <= n ; i++)
            for(int j = 1 ; j <= n ; j++)
            F[i][j] = 1e9;

            if(a[u][v] == 1 || a[x][y] == 1)
            {
                cout<<-1<<'\n';
                continue;
            }

            cout<<Bfs(x,y,u,v)<<'\n';
        }
    }
}
int dm = 0;
vector <vector<ii>> V;
vector <ii> Lt(int x,int y)
{
    vector <ii> P;
    if(a[x][y] == 1)
    {
        P.push_back({x,y});
        cx[x][y] = 1;
        F[x][y] = dm;
        return P;
    }
    queue <ii> q;
    q.push({x,y});

    cx[x][y] = 1;
    DP[x][y] = 1;
    while(q.size())
    {
        int x = q.front().fi;
        int y = q.front().se;
        P.push_back({x,y});
        F[x][y] = dm;
        q.pop();
        for(int i = 0 ; i < 4 ; i++)
        {
            int u = x + dx[i];
            int v = y + dy[i];
            if(cx[u][v] == 0 && u <= n && v <= n && a[u][v] != 1 && u > 0 && v > 0)
            {
                DP[u][v] = DP[x][y] + 1;
                cx[u][v] = 1;
                q.push({u,v});
            }
        }
    }
    return P;
}
void sub2()
{
    int d = 0;
    for(int i = 1 ; i <= n ; i++)
    for(int j = 1 ; j <= n ; j++)
    if(!F[i][j])
    {
        dm++;
        V.push_back({Lt(i,j)});
    }

    while(q--)
    {
        int t;
        cin >> t;
        if(t == 1)
        {
            int u,v;
            cin >> u >> v;
            a[u][v] = 1;
        }
        else
        {
            int u,v,x,y;
            cin >> u >> v >> x >> y;

            if(F[u][v] != F[x][y])
            {
                cout<<-1<<'\n';
                continue;
            }

            cout<<max(DP[u][v],DP[x][y]) - min(DP[u][v],DP[x][y]) + 1<<'\n';
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("MECUNG.INP","r",stdin);
    freopen("MECUNG.OUT","w",stdout);

    cin >> n >> q;
    for(int i = 1 ; i <= n ; i++)
    for(int j = 1 ; j <= n ; j++)
    {
        char u;
        cin >> u;
        a[i][j] = u - '0';
        F[i][j] = 0;
    }

    if(n <= 100 &&  q <= 100) return sub1(),0;
    sub2();

    return 0;
}
