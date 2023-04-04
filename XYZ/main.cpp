#include <bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define fi first
#define se second
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e2 + 10;
int n;
int ans = INF;

struct Point {
    int x, y, z;
};
Point a[NM];

struct Data {
    int mmax, mmin, cnt;
};

void backtrack(int x, Data s1, Data s2, Data s3){
    if(x > n){
        if(s1.cnt >= 1 && s2.cnt >= 1 && s3.cnt >= 1){
            int tmp = (s1.mmax - s1.mmin) + (s2.mmax - s2.mmin) + (s3.mmax - s3.mmin);
            minimize(ans, tmp);
        }
        return;
    }
    Data u = {max(s1.mmax, a[x].x), min(s1.mmin, a[x].x), s1.cnt + 1};
    Data v = {max(s2.mmax, a[x].y), min(s2.mmin, a[x].y), s2.cnt + 1};
    Data k = {max(s3.mmax, a[x].z), min(s3.mmin, a[x].z), s3.cnt + 1};
    backtrack(x + 1, u, s2, s3);
    backtrack(x + 1, s1, v, s3);
    backtrack(x + 1, s1, s2, k);
    return;
}
void sub1(){
    Data u = {-INF, INF, 0}, v = {-INF, INF, 0}, k = {-INF, INF, 0};
    backtrack(1, u, v, k);
    cout << ans;
}
int32_t main()
{
    FastIO
    freopen("XYZ.INP", "r", stdin);
    freopen("XYZ.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i].x >> a[i].y >> a[i].z;
    }

    if(n <= 10) sub1();
    return 0;
}
