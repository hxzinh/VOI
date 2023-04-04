#include <bits/stdc++.h>
#define int long long
#define INF 1e9
#define INDEX(x, y, z) ((z) * r * c + (x) * c + (y))
#define MASK(x) (1LL << (x))
#define BIT(i, x) ((x) >> (i) & 1)
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 21;
const int MOD = 998244353;
int dx[] = {1, -1, 0, 0, 0, 0};
int dy[] = {0, 0, 1, -1, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};
int r, c, h;
int ans = 0;
int g[7][7][2], cnt[MASK(20)], f[1005][MASK(10)];
bool cx[5][5][5];

void add(int &a, int b){
    if(a + b >= MOD) a += b - MOD;
    else a += b;
}
void Minus(int &a, int b){
    if(a - b < 0) a -= b + MOD;
    else a -= b;
}
void backtrack(int x, int y, int z, int mask){
    if(z >= h){
        ans++;
        return;
    }
    if(x >= r){
        backtrack(0, 0, z + 1, mask);
        return;
    }
    if(y >= c){
        backtrack(x + 1, 0, z, mask);
        return;
    }

    backtrack(x, y + 1, z, mask);
    if(BIT(INDEX(x, y, z), mask)) return;
    mask |= MASK(INDEX(x, y, z));
    if(x + 1 < r && !BIT(INDEX(x + 1, y, z), mask)){
        int newMask = mask | MASK(INDEX(x + 1, y, z));
        backtrack(x, y + 1, z, newMask);
    }

    if(y + 1 < c && !BIT(INDEX(x, y + 1, z), mask)){
        int newMask = mask | MASK(INDEX(x, y + 1, z));
        backtrack(x, y + 1, z, newMask);
    }
    if(z + 1 < h && !BIT(INDEX(x, y, z + 1), mask)){
        int newMask = mask | MASK(INDEX(x, y, z + 1));
        backtrack(x, y + 1, z, newMask);
    }
}
void sub1(){
    backtrack(0, 0, 0, 0);
    cout << ans;
}

void prepare(int x, int y, int z, int mask){
    if(z >= 1){
        cnt[mask]++;
        ans++;
        return;
    }
    if(x >= r){
        prepare(0, 0, z + 1, mask);
        return;
    }
    if(y >= c){
        prepare(x + 1, 0, z, mask);
        return;
    }

    prepare(x, y + 1, z, mask);
    if(BIT(INDEX(x, y, z), mask)) return;
    mask |= MASK(INDEX(x, y, z));
    if(x + 1 < r && !BIT(INDEX(x + 1, y, z), mask)){
        int newMask = mask | MASK(INDEX(x + 1, y, z));
        prepare(x, y + 1, z, newMask);
    }

    if(y + 1 < c && !BIT(INDEX(x, y + 1, z), mask)){
        int newMask = mask | MASK(INDEX(x, y + 1, z));
        prepare(x, y + 1, z, newMask);
    }
    if(z + 1 < 1 && !BIT(INDEX(x, y, z + 1), mask)){
        int newMask = mask | MASK(INDEX(x, y, z + 1));
        prepare(x, y + 1, z, newMask);
    }
}
void sub34(){
    prepare(0, 0, 0, 0);
    f[1][0] = 1;
    for(int i = 1; i <= h; i++){
        for(int mask = 0; mask < MASK(r * c); mask++) if(f[i][mask]){
            int tmp = (MASK(r * c) - 1) ^ mask;
            for(int level_mask = tmp; level_mask >= 0; level_mask--){
                level_mask &= tmp;
                if(cnt[level_mask] == 0) continue;
                int new_tmp = ((MASK(r * c) - 1) ^ mask) ^ level_mask;
                for(int new_mask = new_tmp; new_mask >= 0; new_mask--){
                    new_mask &= new_tmp;
                    f[i + 1][new_mask] = (f[i + 1][new_mask] + (f[i][mask] * cnt[level_mask]) % MOD) % MOD;
                }
            }
        }
    }

    int res = 0;
    for(int mask = 0; mask < MASK(r * c); mask++) add(res, f[h][mask]);
    cout << f[h + 1][0];

    ///for(int mask = 0; mask <= MASK(r * c); mask++) cout << cnt[mask] << " " << mask << '\n';
}
int32_t main()
{
    FastIO
    freopen("BRICKS.INP", "r", stdin);
    freopen("BRICKS.OUT", "w", stdout);
    cin >> r >> c >> h;

    sub34();
    return 0;
}
