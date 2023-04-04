    #include <bits/stdc++.h>
    #define ll long long
    #define oo 1e18
    #define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define MASK(x) (1LL << (x-1))

    using namespace std;
    const int NM=1e5+10;
    ll n,m,k,l;
    ll mask[NM];
    ll s[NM][75];
    ///---------------------------------------------------------------------///
    struct Data
    {
        ll v,w;
    };
    vector <Data> a[NM];
    ///------------------------------------------------------------------------///
    struct DHAKA
    {
        ll u,cost,mask;
        bool inline operator < (const DHAKA &A) const
        {
            return cost > A.cost || (cost==A.cost && __builtin_popcount(mask)<__builtin_popcount(A.mask));
        }
    };
    priority_queue <DHAKA> pq;
    /**
    bool operator < (const DHAKA &A,const DHAKA &B)
    {
        if(A.cost==B.cost) return __builtin_popcount(A.mask) > __builtin_popcount(B.mask);
        else return A.cost > B.cost;
    } **/

    void readfile()
    {
        freopen("DHAKA.INP","r",stdin);
        ///freopen("DHAKA.OUT","w",stdout);
        cin >> n >> m >> k >> l;
        for(int i=1;i<=n;i++)
        {
            ll t;
            cin >> t;
            for(int j=1;j<=t;j++)
            {
                ll u;
                cin >> u;
                mask[i]=mask[i]|MASK(u);
            }
        }
        for(int i=1;i<=m;i++)
        {
            ll u,v,w;
            cin >> u >> v >> w;
            a[u].push_back({v,w});
            a[v].push_back({u,w});
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=63;j++)
                s[i][j]=oo;
        }
    }
    void dijtra()
    {
        s[1][mask[1]]=0;
        pq.push({1,0,mask[1]});
        while(!pq.empty())
        {
            ll u=pq.top().u, cost=pq.top().cost, bt=pq.top().mask;
            cout << u << " " << cost << " " << bt  << '\n';
            pq.pop();
            if(s[u][bt]!=cost) continue;
            for(int i=0;i<a[u].size();i++)
            {
                ll v=a[u][i].v;
                ll w=a[u][i].w;
                ll NewMask=bt|mask[v];
                if(s[v][NewMask]>s[u][bt]+w)
                {
                    s[v][NewMask]=s[u][bt]+w;
                    pq.push({v,s[v][NewMask],NewMask});
                }
            }
        }
        ll ans=oo;
        for(int i=0;i<=63;i++) if(s[n][i]!=oo && __builtin_popcount(i)>=l) ans=min(ans,s[n][i]);
        if(ans==oo) cout << -1;
        else cout << ans;
    }
    void xuli()
    {
        dijtra();
    }
    int main()
    {
        FastIO
        readfile();
        xuli();
        return 0;
    }
