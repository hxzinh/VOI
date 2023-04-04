#include <bits/stdc++.h>
#define ll long long
#define oo 99999999999
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main()
{
    FastIO
    int x, y, u, v, l, r;
    cin >> x >> y >> u >> v >> l >> r;
    if(y > v){
        swap(y, v);
        swap(x, u);
    }
    if(l < u && r < v && l > x && r > y) cout << "YES";
    else cout << "NO";
    return 0;
}
