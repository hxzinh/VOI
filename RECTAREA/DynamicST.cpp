#include<bits/stdc++.h>
using namespace std;

#define inf 0x3f3f3f3f
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
typedef long long ll;

struct Point {
    ll x, y;
} top[100005], bot[100005];

struct data {
	ll x, l, r, type;
};

struct Node {
	ll cnt, len;
	struct Node *L, *R;
};

struct Node* getNode() {
    struct Node* tmp = new struct Node;
    tmp->cnt = tmp->len = 0;
    tmp->L = tmp->R = NULL;

    return tmp;
};

struct Node* root;

data a[200005];
ll k;
int m, n;
bool vi[202][202];

bool cmp(data u, data v) {
	return (u.x != v.x) ? u.x < v.x : u.type < v.type;
}

void update(struct Node* cur, ll l, ll r, ll u, ll v, int type) {
	if(u > v || u > r || v < l) {
        return;
	}

	if(u <= l && r <= v) {
		cur->cnt += type;
		if(type == 1) {
            cur->len = r - l + 1;
		} else
            if(!cur->cnt)
                if(l < r) {
                    cur->len = 0;

                    if(cur->L) {
                        cur->len = cur->L->len;
                    }

                    if(cur->R) {
                        cur->len += cur->R->len;
                    }

                } else {
                    cur->len = 0;
                }

		return;
	}

	ll mid = l - (l - r) / 2;

	if(cur->L == NULL) {
        cur->L = getNode();
	}

	update(cur->L, l, mid, u, v, type);

	if(cur->R == NULL) {
        cur->R = getNode();
	}

	update(cur->R, mid + 1, r, u, v, type);

	if (!cur->cnt && l < r) {
		cur->len = cur->L->len + cur->R->len;
	}
}

ll sub1e6() {
    root = getNode();
	sort(a + 1, a + m + 1, cmp);

	ll res(0);
	for (int i = 1; i <= m; ++i) {
		res += ll(root->len) * ll(a[i].x - a[i - 1].x);
		update(root, 1, k, a[i].l, a[i].r, a[i].type);
	}

	return res;
}

int sub3() {
    for (int i = 0; i < n; ++i) {
        for (int j = top[i].x; j < bot[i].x; ++j) {
            for (int k = top[i].y; k < bot[i].y; ++k) {
                vi[j][k] = 1;
            }
        }
    }

    int res(0);
    for (int i = 0; i <= 100; ++i) {
        for (int j = 0; j <= 100; ++j) {
            res += (vi[i][j]);
        }
    }

    return res;
}

void process() {
    cin >> n;

    ll maxtd(0);
    for (int i = 0; i < n; ++i) {
        cin >> top[i].x >> top[i].y >> bot[i].x >> bot[i].y;

		a[++m] = {top[i].x, top[i].y + 1, bot[i].y, 1};
		a[++m] = {bot[i].x, top[i].y + 1, bot[i].y, -1};
		k = max(k, bot[i].y);

        maxtd = max({maxtd, bot[i].x, bot[i].y});
    }

    if(n <= 100 && maxtd <= 100) {
        cout << sub3();
    } else {
        cout << sub1e6();
    }
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	freopen("RECTAREA.inp", "r", stdin);
    freopen("RECTAREA.out", "w", stdout);

	process();
	return 0;
}