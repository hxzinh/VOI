#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define pii pair<int, int>
#define fi first
#define se second
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e5 + 10;
int n;
pii a[NM];
int cnt[1000005], id[1000005];

bool cmp(const pii A, const pii B){
    return (cnt[A.fi] == cnt[B.fi] ? A.fi < B.fi : cnt[A.fi] > cnt[B.fi]);
}
bool cmp2(const pii A, const pii B){
    return (cnt[A.fi] == cnt[B.fi] ? id[A.fi] < id[B.fi] : cnt[A.fi] > cnt[B.fi]);
}
int main()
{
    FastIO
    cin >> n;
    for(int i = 1; i <= n; i++){
        int u; cin >> u;
        a[i] = {u, i};
        if(!id[u]) id[u] = i;
        cnt[u]++;
    }

    sort(a + 1, a + n + 1, cmp);
    for(int i = 1; i <= n; i++) cout << a[i].fi << " ";
    cout << '\n';

    sort(a + 1, a + n + 1, cmp2);
    for(int i = 1; i <= n; i++) cout << a[i].fi << " ";
    return 0;
}
