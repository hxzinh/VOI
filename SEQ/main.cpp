#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define ii pair<int, int>
#define fi first
#define se second
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e5 + 10;
int n, k;
ii a[NM];

bool tmp(const ii &A, const ii &B){
    return (A.fi == B.fi ? A.se < B.se : A.fi < B.fi);
}
void readfile(){
    freopen("SEQ.INP", "r", stdin);
    freopen("SEQ.OUT", "w", stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i].fi;
        a[i].se = i;
    }
    sort(a + 1, a + n + 1, tmp);
}
void xuli(){
    for(int i = n; i > 0; i--){
        int l = 1, r = i;
        while(l <= r){
            int m = (l + r) >> 1;
            if(a[i].fi - a[m].fi == k){
                cout << a[i].se << " " << a[m].se;
                return;
            }
            if(a[i].fi - a[m].fi < k) r = m - 1;
            else l = m + 1;
        }
    }
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
