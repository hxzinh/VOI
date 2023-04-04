#include<bits/stdc++.h>
using namespace std;

#define inf 0x3f3f3f3f
typedef long long ll;

const int N = 100005;
ll s[N];
int x[N], n;

ll nbe400() {
    ll res(1e18);
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            ll d(0), tv = (x[i] + x[j]) / 2;

            for (int k = 1; k <= n; ++k) {
                d += min(abs(tv - x[k]), 1LL * abs(x[k]));
            }

            res = min(res, d);
        }
    }

    return res;
}

int vta(0);
ll checka(ll tv) {
    int lb1 = upper_bound(x + 1, x + n + 1, tv) - x - 1;
    int lb2 = min(vta, int(upper_bound(x + 1, x + n + 1, tv - tv / 2) - x - 1));
    return s[lb1] - abs(tv) * lb1 + abs(tv) * (lb2 - lb1) - (s[lb2] - s[lb1]) + s[vta] - s[lb2];
}

ll checkd(ll tv) {
    int lb1 = upper_bound(x + 1, x + n + 1, tv) - x - 1;
    int lb2 = max(vta + 1, int(lower_bound(x + 1, x + n + 1, tv - tv / 2) - x));
    return s[n] - s[lb1 - 1] - tv * (n - lb1 + 1) + tv * (lb1 - lb2) - (s[lb1 - 1] - s[lb2 - 1]) + s[lb2 - 1];
}

ll full() {
    ll sd(0);

    for (int i = 1; i <= n; ++i) {
        s[i] = s[i - 1] + abs(x[i]);
        if(x[i] <= 0) {
            vta = i;
        } else {
            sd += x[i];
        }
    }

    ll res(1e18);
    for (int i = 1; i <= vta; ++i) {
        ll tv = (x[1] + x[i]) / 2;

        res = min(res, sd + checka(tv));
        if((x[1] + x[i]) % 2) {
            res = min(res, sd + checka(tv + 1));
        }
    }

    for (int i = vta + 1; i <= n; ++i) {
        ll tv = (x[n] + x[i]) / 2;

        res = min(res, checkd(tv));
        if((x[n] + x[i]) % 2) {
            res = min(res, checkd(tv + 1));
        }
    }

    return res;
}

void process() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }

    sort(x + 1, x + n + 1);

    if(n <= 400) {
        cout << nbe400();
    } else {
        cout << full();
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("TELEPORT.inp", "r", stdin);
    freopen("TELEPORT.out", "w", stdout);

    process();
    return 0;
}
