#include <bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define popcount(x) __builtin_popcount(x)
#define set(x) setprecision(x)
#define MASK(x) (1LL << (x))
#define BIT(x, i) ((x) >> (i) & 1)
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

struct Bignum {
    static const int MAX_DIGIT = 1000;
    static const int BASE = (int) 1e9;
    int digits[MAX_DIGIT], numDigit;

    Bignum(long long x = 0) {
        numDigit = 0;
        memset(digits, 0, sizeof digits);

        if (!x) numDigit = 1;

        while (x > 0) {
            digits[numDigit++] = x % BASE;
            x /= BASE;
        }
    }

    Bignum(string s) {
        numDigit = 0;
        memset(digits, 0, sizeof digits);

        long long x(0);
        int i(s.length() - 1), l(i + 1);
        for (int i = l - 1; i >= 8; i -= 9) {
            digits[numDigit++] = stoll(s.substr(i - 8, 9));
        }

        if(l % 9) {
            digits[numDigit++] = stoll(s.substr(0, l % 9));
        }
    }

    int operator % (int x) const {
		int res(0);
		for (int i = numDigit - 1; i >= 0; i--)
            res = (res * BASE + digits[i]) % x;

		return res;
	}

	Bignum operator / (long long x) const {
		Bignum res(0);
		long long rem(0);
		for (int i = numDigit - 1; i >= 0; i--) {
			res.digits[i] = (BASE * rem + digits[i]) / x;
			rem = (BASE * rem + digits[i]) % x;
		}

		res.numDigit = numDigit;
		while (res.numDigit > 1 && !res.digits[res.numDigit - 1]) --res.numDigit;
		return res;
	}

    #define COMPARE(a, b) (((a) > (b)) - ((a) < (b)))
    int compare(const Bignum &x) const {
        if (numDigit != x.numDigit) {
            return COMPARE(numDigit, x.numDigit);
        }

        for (int i = numDigit - 1; i >= 0; --i) {
            if (digits[i] != x.digits[i]) {
                return COMPARE(digits[i], x.digits[i]);
            }
        }
        return 0;
    }
};

const int NM = 1e5 + 10;
string s;
int a[NM], cnt[NM], dem[NM], id[NM];
bool cx[NM];
vector<int> Prime;

void progress(){
    cx[1] = true;
    for(int i = 2; i <= sqrt(100000); i++) if(!cx[i]) {
        for(int j = i * i; j <= 100000; j += i) cx[j] = true;
    }
    for(int i = 2; i <= 100000; i++) if(!cx[i]){
        Prime.push_back(i);
        id[i] = Prime.size() - 1;
    }

    //cout << Prime.size();
}
void xuli(){
    int numPrime = Prime.size();

    Bignum sum(s);
    int tmp = 0;
    for(int u : Prime){
        while(sum % u == 0){
            sum = sum / u;
            cnt[id[u]]++;
        }
        tmp += (!cnt[id[u]]);
    }

    int L = 1, R = 1;
    bool ok = false;
    while(tmp < numPrime){
        for(int u : Prime){
            int i = id[u];
            if(cnt[i] > dem[i]){
                while(cnt[i] > dem[i]){
                    int k = R++;
                    for(int j = 0; Prime[j] * Prime[j] <= k; j++){
                        if(k % Prime[j] == 0){
                            tmp -= (cnt[j] == dem[j]);
                            while(k % Prime[j] == 0){
                                k /= Prime[j];
                                dem[j]++;
                            }
                            tmp += (dem[j] == cnt[j]);
                        }
                    }

                    if(k > 1){
                        tmp -= (dem[id[k]] == cnt[id[k]]);
                        dem[id[k]]++;
                        tmp += (dem[id[k]] == cnt[id[k]]);
                    }
                }
            } else {
                while(cnt[i] < dem[i]){
                    int k = L++;
                    for(int j = 0; Prime[j] * Prime[j] <= k; j++){
                        if(k % Prime[j] == 0){
                            tmp -= (dem[j] == cnt[j]);
                            while(k % Prime[j] == 0){
                                k /= Prime[j];
                                dem[j]--;
                            }
                            tmp += (dem[j] == cnt[j]);
                        }
                    }

                    if(k > 1){
                        tmp -= (dem[id[k]] == cnt[id[k]]);
                        dem[id[k]]--;
                        tmp += (dem[id[k]] == cnt[id[k]]);
                    }
                }
            }
        }
    }
    cout << L << " " << --R;
}
int32_t main()
{
    FastIO
    freopen("PRODUCT.INP", "r", stdin);
    freopen("PRODUCT.OUT", "w", stdout);
    cin >> s;

    progress();
    xuli();
    return 0;
}
