#include <bits/stdc++.h>
#define int long long
#define INF 1e9
#define ii pair<int, int>
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e5 + 100;
int n;
int a[NM], b[NM], s[NM];

struct Data {
    int up, down, index;
};
Data k[NM], t[NM];

void readfile(){
    freopen("CLIMBE.INP", "r", stdin);
    freopen("CLIMBE.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
}
bool cmp(const Data &A, const Data &B){
    return A.up < B.up;
}
bool cmp2(const Data &A, const Data &B){
    return A.down > B.down;
}
void xuli(){
    int cnt = 0, dem = 0;
    for(int i = 1; i <= n; i++){
        if(a[i] < b[i]){
            k[++cnt].up = a[i];
            k[cnt].down = b[i];
            k[cnt].index = i;
        } else {
            t[++dem].up = a[i];
            t[dem].down = b[i];
            t[dem].index = i;
        }
    }

    sort(k + 1, k + cnt + 1, cmp);
    sort(t + 1, t + dem + 1, cmp2);

    for(int i = 1; i <= dem; i++) k[++cnt] = t[i];
    for(int i = 1; i <= cnt; i++) s[i] = s[i - 1] + k[i].up;

    int res = k[1].up;
    for(int i = 1; i <= cnt; i++){
        if(res >= s[i]) res += k[i].down;
        else res = s[i] + k[i].down;
    }
    cout << res << '\n';
    for(int i = 1; i <= cnt; i++) cout << k[i].index << " ";
}
int32_t main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
