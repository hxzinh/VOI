#include <bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f
#define MASK(x) (1LL << (x))
#define BIT(i, x) ((x) >> (i) & 1)
#define pii pair<int, int>
#define fi first
#define se second
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e5 + 10;
int n, costOver, costNeed, costMove;
int numOver = 0, numNeed = 0;
int a[NM], b[NM];
pii over[NM], need[NM];

void full(){
    for(int i = 1; i <= n; i++){
        if(a[i] < b[i]) need[++numNeed] = make_pair(i, b[i] - a[i]);
        if(a[i] > b[i]) over[++numOver] = make_pair(i, a[i] - b[i]);
    }
    need[numNeed + 1] = make_pair(INF, INF);
    over[numOver + 1] = make_pair(INF, INF);

    int res = 0;
    int x = 1, y = 1, curNeed = need[1].se, curOver = over[1].se;
    while(x <= numNeed || y <= numOver){
        cout << need[x].fi << " " << over[y].fi << '\n';
        if(x > numNeed){
            res += costOver * curOver;
            y++;
            curOver = over[y].se;
            continue;
        }
        if(y > numOver){
            res += costNeed * curNeed;
            x++;
            curNeed = need[x].se;
            continue;
        }

        int cost = costMove * abs(need[x].fi - over[y].fi) * min(curNeed, curOver);
        int nxtOver = costMove * abs(need[x].fi - over[y + 1].fi) * min(curNeed, over[y + 1].se);
        int nxtNeed = costMove * abs(need[x + 1].fi - over[y].fi) * min(need[x + 1].se, curOver);

        if(cost <= nxtOver && cost <= nxtNeed){
            res += cost;
            if(curNeed == curOver){
                x++; y++;
                curNeed = need[x].se; curOver = over[y].se;
                continue;
            }
            if(curNeed > curOver){
                curNeed -= curOver;
                y++;
                curOver = over[y].se;
                continue;
            }
            if(curOver > curNeed){
                curOver -= curNeed;
                x++;
                curNeed = need[x].se;
                continue;
            }
        }

        if(nxtOver <= nxtNeed){
            res += costOver * curOver;
            y++;
            curOver = over[y].se;
            continue;
        }

        if(nxtNeed <= nxtOver){
            res += costNeed * curNeed;
            x++;
            curNeed = need[x].se;
            continue;
        }
    }
    cout << res;
}
int32_t main()
{
    FastIO
    freopen("ROBOT.INP", "r", stdin);
    freopen("ROBOT.OUT", "w", stdout);
    cin >> n >> costOver >> costNeed >> costMove;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];

    full();
    return 0;
}
