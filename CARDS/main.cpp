#include <bits/stdc++.h>
#define ll long long
#define BIT(x, i) ((x) >> (i) & 1LL)
#define MASK(x) (1LL << (x))
#define oo 99999999999
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
int n;
string colors = "RGBYW";
bool card[7][7];

bool minimize(int &a, int b){
    if(a > b){
        a = b;
        return 1;
    } else return 0;
}

void readfile(){
    freopen("CARDS.INP", "r", stdin);
    freopen("CARDS.OUT", "w", stdout);
    cin >> n;
    memset(card, false, sizeof(card));
    for(int i = 1; i <= n; i++){
        string u; cin >> u;
        for(int j = 0; j < 5; j++)
            if(colors[j] == u[0]) card[j][u[1] - '1'] = true;
    }
}
bool check(int askColor, int askNum){
    for(int i = 0; i < 5; i++)
    for(int j = 0; j < 5; j++) if(card[i][j]){
        for(int u = 0; u < 5; u++)
        for(int v = 0; v < 5; v++) if(card[u][v]){
            if(i == u && j == v) continue;
            if(i == u){
                if(!BIT(askNum, j) && !BIT(askNum, v)) return false;
            }
            if(j == v){
                if(!BIT(askColor, i) && !BIT(askColor, u)) return false;
            }
            if(i != u && j != v){
                if(!BIT(askNum, j) && !BIT(askNum, v) && !BIT(askColor, i) && !BIT(askColor, u))
                    return false;
            }
        }
    }
    return true;
}
void xuli(){
    int res = 11;
    for(int i = 0; i <= MASK(5) - 1; i++){
        for(int j = 0; j <= MASK(5) - 1 ; j++){
            if(check(i, j))
                minimize(res, __builtin_popcount(i) + __builtin_popcount(j));
        }
    }
    cout << res;
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
