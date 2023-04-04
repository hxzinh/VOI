#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e5 + 10;
int n, m;
int a[NM], b[NM];
vector<int> vec;

int main()
{
    FastIO
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        vec.push_back(a[i]);
    }
    for(int j = 1; j <= m; j++) {
        cin >> b[j];
        vec.push_back(b[j]);
    }

    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);

    int x = 1, y = 1;
    a[n + 1] = INF; b[m + 1] = INF;
    while(x <= n && y <= m){
        while(a[x] < b[y] && x <= n) x++;
        while(b[y] < a[x] && y <= m) y++;
        if(x <= n && a[x] == b[y]) {
            cout << a[x] << " ";
            x++; y++;
        }
    }
    cout << '\n';

    x = 1; y = 1;
    while(x <= n || y <= m){
        while(a[x] < b[y] && x <= n) cout << a[x++] << " ";
        while(b[y] < a[x] && y <= m) cout << b[y++] << " ";
        if(x <= n && a[x] == b[y]) {
            cout << a[x] << " ";
            x++; y++;
        }
    }
    return 0;
}
