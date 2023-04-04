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

const int NM = 1e3 + 10;
int n, m, k;
ii st, fin;

struct ToaDo {
    int x, y, u, v;
};
ToaDo a[NM];

void readfile(){
    freopen("BUS.INP", "r", stdin);
    freopen("BUS.OUT", "w", stdout);
    cin >> n >> m;
    cin >> st.fi >> st.se >> fin.fi >> fin.se;
    cin >> k;
    for(int i = 1; i <= k; i++){
        cin >> a[i].x >> a[i].y >> a[i].u >> a[i].v;
    }
}
void sub12(){

}
int main()
{
    FastIO
    cout << "Hello world!" << endl;
    return 0;
}
