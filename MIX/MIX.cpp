#include <bits/stdc++.h>
#define int long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

int a[5], b[5], c[5];

void readfile(){
    freopen("MIX.INP", "r", stdin);
    freopen("MIX.OUT", "w", stdout);
    cin >> a[1] >> a[2] >> a[3];
    cin >> b[1] >> b[2] >> b[3];
    cin >> c[1] >> c[2] >> c[3];
}
int ucln(int u, int v){
    int tmp;
    while(u % v != 0){
        tmp = u % v;
        u = v;
        v = tmp;
    }
    return v;
}
void xuli(){
    int s1 = a[1] + a[2] + a[3];
    int s2 = b[1] + b[2] + b[3];
    int s3 = c[1] + c[2] + c[3];
    int bc = s1 * s2 / ucln(s1, s2);
    bc = bc * s3 / ucln(bc, s3);

    int k;
    k = bc / s1;
    a[1] *= k; a[2] *= k; a[3] *= k;
    k = bc / s2;
    b[1] *= k; b[2] *= k; b[3] *= k;
    k = bc / s3;
    c[1] *= k; c[2] *= k; c[3] *= k;

    int sa = a[1] + b[1] + c[1];
    int sb = a[2] + b[2] + c[2];
    int sc = a[3] + b[3] + c[3];

    int tmp = ucln(sa, sb);
    tmp = ucln(tmp, sc);
    cout << sa / tmp << " " << sb / tmp << " " << sc / tmp;
}
int32_t main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
