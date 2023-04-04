#include <bits/stdc++.h>

using namespace std;

vector<int> pos[100005];

long long Tinh(long long k, long long d, int l)
{
    return k*l + d*l*(l-1)/2;
}

int n, d;
struct SegmentTree
{

    int n;
    vector <long long> sum,lazy,csc;
    vector<int> ID;
    vector<bool> cx;


    SegmentTree(int _n = 0)
    {
        n = _n;
        sum.assign(4*n+1,0);
        lazy.assign(4*n+1,0);
        csc.assign(4*n+1,0);
        cx.assign(4*n+1, 0);
    }

    void reset()
    {
        for(int id: ID)
        {
            sum[id] = 0;
            lazy[id] = 0;
            csc[id] = 0;
            cx[id] = 0;
        }
        ID.clear();
    }

    void PushDown(int id, int l, int r)
    {
        int m =(l+r)/2;
        long long D = lazy[id] +(m-l+1)*csc[id];

        lazy[2*id] += lazy[id];
        csc[2*id] += csc[id];
        sum[2*id] += Tinh(lazy[id], csc[id], m-l+1);

        lazy[2*id+1] += D;
        csc[2*id+1] += csc[id];
        sum[2*id+1] += Tinh(D, csc[id], r-m);

        lazy[id] = csc[id] = 0;
    }

    long long get(int id, int l, int r, int u, int v)
    {
        if(!cx[id])
        {
            cx[id] = 1;
            ID.push_back(id);
        }

        if(u > r || v < l) return 0;
        if(u <= l && r <= v) return sum[id];
        PushDown(id, l, r);
        int m =(l+r)/2;
        return get(2*id, l, m, u, v) + get(2*id+1, m+1, r, u, v);
    }

    void update(int id, int l, int r, int u, int v, int k, int d)
    {
        if(!cx[id])
        {
            cx[id] = 1;
            ID.push_back(id);
        }

        if(u > r || v < l) return;
        if(u <= l && r <= v)
        {
            lazy[id] += k;
            csc[id] += d;
            sum[id] += Tinh(k, d, r-l+1);
            return;
        }

        PushDown(id, l, r);
        int m =(l+r)/2;
        update(2*id, l, m, u, v, k, d);
        update(2*id+1, m+1, r, u, v, k + max(0, m-max(u, l)+1)*d, d);
        sum[id] = sum[2*id] + sum[2*id+1];
    }

    void update(int l, int r, int k, int d)
    {
        update(1, 1, n, l, r, k, d);
    }

    long long get(int l, int r)
    {
        return get(1, 1, n, l, r);
    }

};

int a[1000006];
int main()
{

    cin >> n;

    SegmentTree st(2*n+1);

    for(int i = 1; i <= n; ++i) cin >> a[i] , d = max(d,a[i]);

    for(int i = 1; i <= d; ++i) pos[i].push_back(0);
    for(int i = 1; i <= n; ++i) pos[a[i]].push_back(i);
    for(int i = 1; i <= d; ++i) pos[i].push_back(n+1);


    long long ans = 0;
    for(int u = 1; u <= d; ++u)
    for(int i = 1; i < pos[u].size(); ++i)
    {
        int L = 2*(i-1) - pos[u][i] + n + 2;
        int R = 2*(i-1) - pos[u][i-1] + n+1;
        ans += st.get(max(1, L-1), R-1);
        st.update(L, R, 1, 1);
        st.update(R+1, 2*n+1, R-L+1, 0);
        if(i == pos[u].size() - 1)
        st.reset();
    }

    cout << ans;

    return 0;
}