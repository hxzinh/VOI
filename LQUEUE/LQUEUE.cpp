#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 2e5 + 10;
int n, k, m;
int f[NM];
vector<int> a;

void readfile(){
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        int u; cin >> u;
        a.push_back((u >= k));
        if(i == 1) f[i] = (u >= k);
        else f[i] = f[i - 1] + (u >= k);
    }
    cin >> m;
}
void sub1(){
    int head = 0;
    while(m--){
        int u; cin >> u;
        if(u == 1){
            int v; cin >> v;
            a.push_back((v >= k));
        }
        if(u == 2) head++;
        if(u == 3){
            int t; cin >> t;
            int res = 0;
            for(int i = head; i < t + head; i++) res += a[i];
            cout << res << '\n';
        }
    }
}
void full(){
    int head = 0, last = n - 1;
    while(m--){
        int u; cin >> u;
        if(u == 1){
            int v; cin >> v;
            a.push_back((v >= k));
            f[++last] = f[last - 1] + (v >= k);
        }
        if(u == 2) head++;
        if(u == 3){
            int t; cin >> t;
            int res;
            if(t + head > head) res = f[t + head - 1] - f[head - 1];
            else res = 0;
            cout << res << '\n';
        }
    }
}
int main()
{
    FastIO
    readfile();
    full();
    return 0;
}
