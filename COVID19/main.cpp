#include <bits/stdc++.h>
#define int long long
#define INF 1e18
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

using namespace std;
const int NM = 1e7 + 10;
int n, m;
int m1 = 0, carry = 0;
int snt[NM], a[NM], b[NM];
vector<int> isPrime, nt, tm;
bool cx[NM], ok;

void readfile(){
    freopen("COVID19.INP", "r", stdin);
    freopen("COVID19.OUT", "w", stdout);
    cin >> n >> m;
}
void getProgress(){
    memset(cx, true, sizeof(cx));
    for(int i = 2; i <= sqrt(min(n, 1LL * 100000)); i++){
        for(int j = i * i; j <= 100000; j += i) cx[j] = false;
    }
    isPrime.push_back(INF);
    for(int i = 2; i <= min(n, 1LL * 100000); i++) if(cx[i]){
        isPrime.push_back(i);
        snt[++m1] = i;
    }
}
void process() {
    getProgress();
    int i = 0;
    snt[0] = INF;
    if(m % n == 0 && sqrt(m) == n) ok = true;
    while(n > 1) {
       while(n % snt[i] != 0) i++;

        if(i >= m1) {
            break;
        }

        while(n % snt[i] == 0) {
            n /= snt[i];
            ++a[i];
        }

        nt.push_back(i);
    }

    if(n > 1) {
        nt.push_back(m1);
        snt[m1++] = n;
    }

    i = 0;
    while(m > 1) {
        while(i < m1 && m % snt[i]) ++i;

        if(i >= m1) break;

        while(m % snt[i] == 0) {
            m /= snt[i];
            ++b[i];
        }
    }

    if(m > 1) {
        if(m % n == 0 && m / n == 1) ++carry;
        else {
            nt.push_back(m1);
            snt[m1++] = m;
        }
    }

    int ans = 0;
    for (int &i : nt) {
        if(a[i] && !b[i]) {
            ans += a[i];
            a[i] = 0;
        }
    }

    int ntMult(0);

    for (int &i : nt) {
        if(a[i] && b[i] && a[i] < b[i]) {
            int d(0);
            for (int j = a[i]; j < b[i]; j *= 2, ++d);

            ntMult = max(ntMult, d);
        }
    }

    int mult = (1LL << ntMult);
    for (int &i : nt) {
        if(a[i] && b[i]) {
            int mult1(mult);

            while(mult1 > 1) {
                while(a[i] * mult1 > b[i]) {
                    --a[i], ++ans;
                }

                if(a[i] * mult1 < b[i]) {
                    ++a[i], --ans;
                }

                a[i] *= 2;
                mult1 /= 2;
            }

            ans += a[i] - b[i];
        }
    }

    if(ok) cout << 1;
    else cout << ans + ntMult;
}
int32_t main()
{
    FastIO
    readfile();
    process();
    return 0;
}
