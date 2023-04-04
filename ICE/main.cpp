#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define pii pair<int, int>
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

const int NM = 5e3 + 10;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int n;
int cnt[NM][NM], id[NM][NM];
string a[NM];

struct Data {
    int x, y, cost;
} q[20000005];

void xuli() {
    int maxSize = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) if(a[i][j] == '0') {
            if(i - 1 >= 0 && a[i - 1][j] == '1') {
                id[i][j] = 0;
                q[maxSize] = {i, j, 0};
                maxSize++;
                continue;
            }

            if(i + 1 < n && a[i + 1][j] == '1') {
                id[i][j] = 0;
                q[maxSize] = {i, j, 0};
                maxSize++;
                continue;
            }

            if(j - 1 >= 0 && a[i][j - 1] == '1') {
                id[i][j] = 0;
                q[maxSize] = {i, j, 0};
                maxSize++;
                continue;
            }

            if(j + 1 < n && a[i][j + 1] == '1') {
                id[i][j] = 0;
                q[maxSize] = {i, j, 0};
                maxSize++;
                continue;
            }

        } else if(a[i][j] == '1') id[i][j] = INF;
    }

    int curId = 0;
    while(curId < maxSize) {
        int x = q[curId].x, y = q[curId].y, cost = q[curId].cost;
        curId++;

        //cout << x << " " << y << " " << cost << '\n';
        if(cost != id[x][y]) continue;

        if(x - 1 >= 0 && a[x - 1][y] == '1') {
            if(cost + 1 < id[x - 1][y] && cnt[x - 1][y] < 2) {
                cnt[x - 1][y]++;
                if(cnt[x - 1][y] == 2) {
                    id[x - 1][y] = cost + 1;
                    q[maxSize] = {x - 1, y, id[x - 1][y]};
                    maxSize++;
                }
            }
        }

        if(x + 1 < n && a[x + 1][y] == '1') {
            if(cost + 1 < id[x + 1][y] && cnt[x + 1][y] < 2) {
                cnt[x + 1][y]++;
                if(cnt[x + 1][y] == 2) {
                    id[x + 1][y] = cost + 1;
                    q[maxSize] = {x + 1, y, id[x + 1][y]};
                    maxSize++;
                }
            }
        }

        if(y - 1 >= 0 && a[x][y - 1] == '1') {
            if(cost + 1 < id[x][y - 1] && cnt[x][y - 1] < 2) {
                cnt[x][y - 1]++;
                if(cnt[x][y - 1] == 2) {
                    id[x][y - 1] = cost + 1;
                    q[maxSize] = {x, y - 1, id[x][y - 1]};
                    maxSize++;
                }
            }
        }

        if(y + 1 >= 0 && a[x][y + 1] == '1') {
            if(cost + 1 < id[x][y + 1] && cnt[x][y + 1] < 2) {
                cnt[x][y + 1]++;
                if(cnt[x][y + 1] == 2) {
                    id[x][y + 1] = cost + 1;
                    q[maxSize] = {x, y + 1, id[x][y + 1]};
                    maxSize++;
                }
            }
        }
    }

    int res = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) if(a[i][j] == '1') maximize(res, id[i][j]);

    cout << res;
}
int32_t main()
{
    FastIO
    freopen("ICE.INP", "r", stdin);
    freopen("ICE.OUT", "w", stdout);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];

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
