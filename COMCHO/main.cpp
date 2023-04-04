#include <bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 150005;
int n, m, Sub, T, head, last;
int outL = -INF, outR = INF, cnt = 0;
int a[NM];
vector<int> inside;

void init(){
    outL = outR = -INF;
    inside.clear();
}
bool check(int x){
    if(outL > -INF) if(min(outL - head, head - inside[0]) >= x) return true;
    for(int i = 1; i < inside.size() - 1; i++){
        int u = inside[i - 1], v = inside[i];
        if((inside[i] - inside[i - 1] - 1) / 2 >= x) return true;
    }
    int tmp = min(abs(outR - last), abs(last - inside[inside.size() - 2]));
    if(outR < INF) return (tmp >= x);
    else return false;
}
void sub3(){
    sort(a + 1, a + m + 1);
    inside.push_back(head);
    for(int i = 1; i <= m; i++){
        if(a[i] >= head && a[i] <= last){
            inside.push_back(a[i]);
            cnt++;
        } else if(a[i] < head) maximize(outL, a[i]);
        else if(a[i] > last) minimize(outR, a[i]);
    }

    if(cnt == head - last + 1){
        cout << 0 << " ";
        return;
    }

    inside.push_back(last);

    int l = 1, r = n, res = 0;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(check(mid)){
            res = mid;
            l = mid + 1;
        } else r = mid - 1;
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
        sub3();
    }
    return 0;
}
