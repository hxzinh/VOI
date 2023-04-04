#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define ii pair<short, short>
#define fi first
#define se second
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}


const int NM = 27;
short n;
ii a[NM];
vector<short> trace;

void readfile(){
    freopen("ICPC.INP", "r", stdin);
    freopen("ICPC.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i].fi;
        a[i].se = i;
    }
}
bool cmp(ii A, ii B){
    return (A.fi == B.fi ? A.se < B.se : A.fi < B.fi);
}
void xuli(){
    sort(a + 1, a + n + 1, cmp);
    short limit = 600, cnt = 0, res = 0, last = 0, time = 0;
    for(int i = 1; i <= n; i++){
        if(a[i].fi <= limit){
            res += time + a[i].fi;
            limit -= a[i].fi;
            time += a[i].fi;
            cnt++;
            trace.push_back(a[i].se);
        } else last = time;
    }
    cout << cnt << " " << res << " " << last;
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
