#include <bits/stdc++.h>
#define int long long
#define INF 1e18
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int MOD = 1e9 + 19972207;
const int NM = 1e6 + 10;
int n, k;
bool cx[NM];
vector<int> prime;

void readfile(){
    freopen("DIVSEQ.INP", "r", stdin);
    freopen("DIVSEQ.OUT", "w", stdout);
    cin >> n >> k;
}
int gcd(int x){
    map<int, int> cnt;
    for(int i = 2; i <= sqrt(n) + 1; i++)
        if(!cx[i]){
            int t = n;
            if(n % i == 0) prime.push_back(i);
            while(t % i == 0){
                cnt[i]++;
                t /= i;
            }
            for(int j = i * i; j <= n / 2; j += i) cx[j] = true;
        }
    int res = 0;
    for(int id = 0; id < prime.size(); id++){
        int u = prime[id];
        if(n % (u * u) == 0 && u * u < n / 2) res++;
        int numCnt = cnt[u] * (prime.size() - id - 1);
        res += (numCnt > 0 ? numCnt : cnt[u]);
    }
    return res;
}
void xuli(){
    int numGcd = gcd(n) + 2;
    for(int i = 1; i <= numGcd; i++){

    }
}
int32_t
 main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
