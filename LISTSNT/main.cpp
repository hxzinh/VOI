#include <bits/stdc++.h>
#define ll long long
#define int long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
    inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
    inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

ll n;
int cnt[10];
bool ok[10];
stack<int> q;

int32_t main()
{
    FastIO
    cin >> n;

    while(n != 0){
        int u = n % 10;
        n /= 10;
        if(u != 2 && u != 3 && u != 5 && u != 7) continue;

        cnt[u]++;
        q.push(u);
    }

    for(int i = 0; i < 10; i++) if(cnt[i]) cout << i << " " << cnt[i] << '\n';
    cout << '\n';
    while(q.size()){
        int u = q.top();
        q.pop();

        if(ok[u]) continue;
        ok[u] = true;
        cout << u << " " << cnt[u] << '\n';
    }

    return 0;
}
