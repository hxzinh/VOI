#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 2e3 + 10;
int n, m, p;

int a[NM][NM];
int power[2 * NM], ans[2 * NM][55], trace[2 * NM][55];
int cost[11][11];
int costTrans[10][55][55], diaRes[2 * NM], diaCost[2 * NM][55], Trans[10][55][55];

void progress(){
    for(int i = 0; i < 10; i++)
        for(int j = 0; j <= i; j++) cost[i][j] = cost[j][i] = min(i - j, j + 10 - i);

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < p; j++){
            for(int k = 0; k < p; k++){
                costTrans[i][j][k] = INF;
                for(int t = 0; t < 10; t++){
                    if(t * j % p == k && costTrans[i][j][k] > cost[i][t]){
                        costTrans[i][j][k] = cost[i][t];
                        Trans[i][j][k] = t;
                    }
                }
            }
        }
    }

    power[0] = 1 % p;
    for(int i = 1; i <= n + m; i++) power[i] = power[i - 1] * 10 % p;
    memset(ans, INF, sizeof(ans));
    memset(trace, -1, sizeof(trace));
}
int getCost(int x, int val, int mul){
    int u, v;
    if(x <= m) u = 1, v = x;
    else u = x - m + 1, v = m;

    int res = 0;
    while(v > 0 && u <= n){
        if(costTrans[a[u][v]][mul][val] == INF) return INF;
        res += costTrans[a[u][v]][mul][val];
        u++; v--;
    }
    return res;
}
int getDigit(int x, int val, int mul){
    return Trans[x][mul][val];
}
void xuli(){
    progress();
    int num = n + m - 1;
    for(int i = 1; i <= num; i++)
        for(int j = 0; j < p; j++) diaCost[i][j] = getCost(i, j, power[num - i]);

    ans[0][0] = 0;
    for(int i = 1; i <= num; i++){
        for(int j = 0; j < p; j++){
            for(int k = 0; k < p; k++){
                if(diaCost[i][k] != INF){
                    if(minimize(ans[i][(j + k) % p], ans[i - 1][j] + diaCost[i][k])) trace[i][(j + k) % p] = k;
                }
            }
        }
    }
    cout << ans[num][0] << '\n';

    int tmp = 0;
    for(int i = num; i > 0; i--){
        diaRes[i] = trace[i][tmp];
        tmp = (tmp - trace[i][tmp] + p) % p;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++) cout << Trans[a[i][j]][power[num - (i + j - 1)]][diaRes[i + j - 1]];
        cout << '\n';
    }
}
int main()
{
    FastIO
    freopen("CLETTER.INP", "r", stdin);
    freopen("CLETTER.OUT", "w", stdout);
    cin >> n >> m >> p;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            char u;
            cin >> u;
            a[i][j] = u - '0';
        }
    }

    xuli();
    return 0;
}
