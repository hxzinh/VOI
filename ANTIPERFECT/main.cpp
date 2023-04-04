#include <bits/stdc++.h>
#define ll long long
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

const int NM = 1e5 + 10;

int n, q, a[NM];
vector <int> perfect;

bool check(int x) {
    int id = lower_bound(ALL(perfect), x) - perfect.begin();
    return perfect[id] == x;
}

void xuli()
{
    int pf = 2;
    for (int i = 2; i <= 30; ++i){
        pf *= 2;
        perfect.push_back((pf - 1) * (pf / 2));
    }

    while (q--) {
        int type, l, r, w; cin >> type >> l >> r >> w;
        if (type == 1){
            if (check(w)) w++;
            for (int i = l; i <= r; ++i) a[i] = w;
        }
        if (type == 2){
            for (int i = l; i <= r; ++i) a[i] += w;
            bool ok;
            int m = -1;
            do {
                ok = false;
                m++;
                for (int i = l; i <= r; ++i)
                    if (check(a[i] + m)) ok = true;
            } while (ok);

            for (int i = l; i <= r; ++i) a[i] += m;
        }
    }

    for (int i = 1; i <= n; ++i) cout << a[i] << " ";
}

int main(){
    FastIO
    freopen("ANTIPERFECT.INP", "r", stdin);
    freopen("ANTIPERFECT.OUT", "w", stdout);
    cin >> n >> q;

    xuli();
    return 0;
}
