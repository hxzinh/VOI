#include <bits/stdc++.h>
#define int long long
#define ll long long
#define db double
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define popcount(x) __builtin_popcount(x)
#define set(x) setprecision(x)
#define MASK(x) (1LL << (x))
#define BIT(x, i) ((x) >> (i) & 1)
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e3 + 10;
int n;
int a[7];

bool isTri(int a, int b, int c){
    return (a + b > c) && (b + c > a) && (a + c > b);
}
db Square(ll u, ll U, ll v, ll V, ll w, ll W) {
    db X = (w * w + u * u - V * V);
    db Y = (v * v + w * w - U * U);
    db Z = (u * u + v * v - W * W);
    db T = (u * v * w);
    return sqrt(X * Y * Z + 2 * 2 * T * T - u * u * Y * Y - v * v * X * X - w * w * Z * Z) / 12;
}
void xuli(){
    sort(a + 1, a + 7);

    bool ok = false;
    do {
        ll BC = a[1];
        ll CA = a[2];
        ll AB = a[3];
        ll OA = a[4];
        ll OB = a[5];
        ll OC = a[6];
        bool ABC = isTri(BC, CA, AB);
        bool OBC = isTri(BC, OB, OC);
        bool OCA = isTri(CA, OC, OA);
        bool OAB = isTri(AB, OA, OB);
        db V_OABC = Square(OA, BC, OB, CA, OC, AB);
        if (ABC && OBC && OCA && OAB && V_OABC > 0){
            cout << "Yes" << '\n';
            ok = true;
            break;
        }
    } while(next_permutation(a + 1, a + 7));

    if(!ok) cout << "No" << '\n';
}
int32_t main()
{
    FastIO
    freopen("SUMMARY.INP", "r", stdin);
    freopen("SUMMARY.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        // << i << " ";
        for(int j = 1; j <= 6; j++) cin >> a[j];
        //xuli();
    }

    do {
        for(int i = 1; i <= 5; i++) cout << a[i] << " ";
        cout << '\n';
    } while(next_permutation(a + 1, a + 6));
    return 0;
}
