#include <bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f3f3f
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 150005;
int n, m, Sub, T, head, last;
int outL = -INF, outR = INF;
int a[NM];
vector<int> inside;

void init(){
    outL = outR = -INF;
    inside.clear();
}
void xuli(){
    sort(a + 1, a + m + 1);
    int res = 0;
    if(a[1] > head) maximize(res, a[1] - head);
    if(a[m] < last) maximize(res, last - a[m]);
    for(int i = 1; i < m; i++){
        if(a[i] == a[i + 1] || a[i] > last || a[i + 1] < head) continue;
        int m = (a[i] + a[i + 1]) >> 1;
        if(m < head) maximize(res, min(head - a[i], a[i + 1] - head));
        else if(m > last) maximize(res, min(last - a[i], a[i + 1] - last));
        else maximize(res, min(m - a[i], a[i + 1] - m));
    }
    cout << res << " ";
}
int32_t main()
{
    FastIO
    freopen("CAULUONG.INP", "r", stdin);
    freopen("CAULUONG.OUT", "w", stdout);
    cin >> Sub >> T;
    while(T--){
        cin >> n >> m;
        cin >> head >> last;
        for(int i = 1; i <= m; i++){
            cin >> a[i];
        }
        xuli();
    }
    return 0;
}
