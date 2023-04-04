#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define ALL(v) (v).begin(), (v).end()
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e5 + 10;
int n, m, k;
vector<vector<int>> a, b;

struct Data {
    int x, y, u, v;
};
Data s[NM];

bool check(int x){
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) if(b[i][j] != x) return false;
    return true;
}
void sub1(){
    int res = INF;
    for(int light = 1; light <= 2; light++){
        b.clear();
        b.insert(b.begin(), ALL(a));
        int cnt = 0;
        for(int i = 1; i <= k; i++){
            int u = s[i].u, v = s[i].v, x = s[i].x, y = s[i].y;
            if(b[x][y] != light){
                int cost = abs(b[x][y] - light);
                cnt += cost;
                for(int hihi = x; hihi <= u; hihi++){
                    for(int huhu = y; huhu <= v; huhu++){
                        b[hihi][huhu] = (b[hihi][huhu] + cost) % 3;
                    }
                }
            }
        }
        if(check(light)) minimize(res, cnt);
    }

    cout << (res < INF ? res : -1);
}
int main()
{
    FastIO
    freopen("LIGHT.INP", "r", stdin);
    freopen("LIGHT.OUT", "w", stdout);
    cin >> n >> m >> k;
    a.assign(n + 7, vector<int>(m + 7, 0));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            int u; cin >> u;
            a[i][j] = u;
        }
    }
    for(int i = 1; i <= k; i++){
        int x, y, u, v;
        cin >> x >> y >> u >> v;
        s[i] = {x, y, u, v};
    }

    sub1();
    return 0;
}
