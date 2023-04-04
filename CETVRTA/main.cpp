#include <bits/stdc++.h>

#define MASK(u) (1LL << (u))
#define BIT(u,i) (((u) >> (i))&1LL)
#define FOR(i,l,r) for(int i = l ; i <= r ; i++)
#define FORD(i,r,l) for(int i = r ; i >= l ; i--)
#define ii pair<int,int>
#define fi first
#define se second
#define FORI(i,V) for(auto i : V)

using namespace std;
ii a[5],b[5];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    freopen("cetvrta.INP","r",stdin);
    freopen("cetvrta.OUT","w",stdout);

    FOR(i,1,3) cin >> a[i].fi >> a[i].se;

    b[1].fi = min({a[1].fi,a[2].fi,a[3].fi});
    b[1].se = min({a[1].se,a[2].se,a[3].se});

    b[2].fi = min({a[1].fi,a[2].fi,a[3].fi});
    b[2].se = max({a[1].se,a[2].se,a[3].se});

    b[3].fi = max({a[1].fi,a[2].fi,a[3].fi});
    b[3].se = min({a[1].se,a[2].se,a[3].se});

    b[4].fi = max({a[1].fi,a[2].fi,a[3].fi});
    b[4].se = max({a[1].se,a[2].se,a[3].se});

    FOR(i,1,4)
    {
        int dem = 0;
        FOR(j,1,3)
        {
            if(a[j].fi == b[i].fi && a[j].se == b[i].se)
            {
                dem++;
                break;
            }
        }
        if(!dem) return cout<<b[i].fi<<" "<<b[i].se,0;
    }
    return 0;
}
