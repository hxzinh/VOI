#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define mp make_pair
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define popcount(x) __builtin_popcount(x)
#define setp(x) setprecision(x)
#define MASK(x) (1LL << (x))
#define BIT(x, i) ((x) >> (i) & 1)
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e3 + 10;
char color[] = {'R', 'G', 'B'};
int n, m;
vector<int> edges[NM];
int ans[NM], c[NM];
stack<int> st;
bool haveRes = false;

bool dfs(int u, int p, int id) {
    ans[u] = id;
    st.push(u);

    for(int v : edges[u]) if(v != p) {
        if(ans[v] != -1) {
            if(ans[v] == ans[u]) return false;
        } else {
            int num = 3 - __builtin_popcount(c[v]);
            if(num ==   2 && BIT(c[v], id)) continue;

            for(int i = 0; i < 3; i++) if(!BIT(c[v], i) && i != id) {
                if(!dfs(v, u, i)) {
                    int tmp;
                    do {
                        tmp = st.top();
                        st.pop();
                        ans[tmp] = -1;
                    } while(tmp != v);
                    return false;
                }

            }
        }
    }
    return true;
}
void xuli() {
    memset(ans, -1, sizeof ans);

    for(int i = 1; i <= n; i++) {
        if(ans[i] != -1) continue;
        for(int j = 0; j < 3; j++) if(!BIT(c[i], j)) {
            if(dfs(i, -1, j)) break;

            int tmp;
            do {
                tmp = st.top();
                st.pop();
                ans[tmp] = -1;
            } while(tmp != i);

            if(j == 2) {
                cout << "Impossible";
                return;
            }
        }
    }

    bool ok = true;
    for(int i = 1; i <= n; i++) if(ans[i] == -1) {
        ok = false;
        break;
    }

    if(!ok) cout << "Impossible";
    else for(int i = 1; i <= n; i++) cout << color[ans[i]];
}
int32_t main()
{
    FastIO
    freopen("COLOR3.INP", "r", stdin);
    freopen("COLOR3.OUT", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        char u; cin >> u;
        for(int j = 0; j < 3; j++) if(u == color[j]) {
            c[i] |= MASK(j);
            break;
        }
    }
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    xuli();
    return 0;
}

/* Author: hxzinh */

/*
-----code ko bug-----code ko bug-----code ko bug--------------

          _.-/`)
         // / / )
      .=// / / / )
     //`/ / / / /
    // /     ` /
   ||         /
    \\       /
     ))    .'
    //    /
         /
*/
