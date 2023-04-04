#include <bits/stdc++.h>
#define ll long long
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

const int NM = 1e4 + 10;
int n, P;
string s;
int cnt[200005][10];

int f[NM];

struct Bignum {
    static const int MAX_DIGIT = 1000;
    static const int BASE = (int) 1e9;
    int digits[MAX_DIGIT], numDigit;

    Bignum(ll x = 0) {
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

        ll x(0);
        int i(s.length() - 1), l(i + 1);
        for (int i = l - 1; i >= 8; i -= 9) {
            digits[numDigit++] = stoll(s.substr(i - 8, 9));
        }

        if(l % 9) {
            digits[numDigit++] = stoll(s.substr(0, l % 9));
        }
    }

    Bignum& operator += (const Bignum &x) {
        int carry(0);
        numDigit = max(numDigit, x.numDigit);

        for (int i = 0; i < numDigit; ++i) {
            digits[i] += x.digits[i] + carry;

            if (digits[i] >= BASE) {
                digits[i] -= BASE;
                carry = 1;
            } else {
                carry = 0;
            }
        }

        if (carry)
            digits[numDigit++] = carry;

        return *this;
    }

    Bignum operator + (const Bignum &x) const {
        Bignum res(*this);
        return res += x;
    }

    Bignum& operator -= (const Bignum &x) {
        int carry(0);
        for (int i = 0; i < numDigit; ++i) {
            digits[i] -= x.digits[i] + carry;
            if (digits[i] < 0) {
                digits[i] += BASE;
                carry = 1;
            } else carry = 0;
        }

        while (numDigit > 1 && !digits[numDigit - 1]) --numDigit;

        return *this;
    }

    Bignum operator - (const Bignum &x) const {
        Bignum res(*this);
        res -= x;
        return res;
    }

    Bignum& operator *= (int x) {
        if (!x) {
            *this = Bignum(0);
            return *this;
        }

        ll remain = 0;
        for (int i = 0; i < numDigit; ++i) {
            remain += 1LL * digits[i] * x;
            digits[i] = remain % BASE;
            remain /= BASE;
        }

        while (remain > 0) {
            digits[numDigit++] = remain % BASE;
            remain /= BASE;
        }

        return *this;
    }

    Bignum operator * (int x) const {
        Bignum res(*this);
        res *= x;
        return res;
    }

    Bignum operator * (const Bignum &x) const {
        Bignum res(0);
        for (int i = 0; i < numDigit; ++i) {
            if (digits[i] > 0)
                for (int j = 0; j < x.numDigit; ++j) {
                if(x.digits[j] > 0) {
                    ll tmp = 1LL * digits[i] * x.digits[j];
                    int pos(i + j);

                    while (tmp > 0) {
                        tmp += res.digits[pos];
                        res.digits[pos] = tmp % BASE;

                        tmp /= BASE;
                        pos++;
                    }
                }
            }
        }

        res.numDigit = MAX_DIGIT - 1;
        while (res.numDigit > 1 && !res.digits[res.numDigit - 1]) --res.numDigit;

        return res;
    }

    ll operator % (ll x) const {
		ll res(0);
		for (int i = numDigit - 1; i >= 0; i--)
            res = (res * BASE + digits[i]) % x;

		return res;
	}

	Bignum operator / (ll x) const {
		Bignum res(0);
		ll rem(0);
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

    #define DEF_OPER(o) bool operator o (const Bignum &x) const { return compare(x) o 0; }
    DEF_OPER(<) DEF_OPER(>) DEF_OPER(>=) DEF_OPER(<=) DEF_OPER(==) DEF_OPER(!=)
    #undef DEF_OPER

    string toString(void) const {
        string res;
        for (int i = 0; i < numDigit; ++i) {
            int tmp = digits[i];
            for (int j = 0; j < 9; ++j) {
                res.push_back('0' + tmp % 10);
                tmp /= 10;
            }
        }

        while (res.size() > 1 && res.back() == '0') {
            res.pop_back();
        }

        reverse(res.begin(), res.end());
        return res;
    }
};

void xuli(){
    Bignum u = s, k = P;

    s = "#" + s;
    for(int i = 1; i <= n; i++)
        for(int j = 0; j < 10; j++) s[i][j] = s[i - 1][j] + (int32_t(s[i] - '0') == j);

    int i = 0;
    while(k < u){
        k = k * ++i;

    }
}
int main()
{
    FastIO
    freopen("DIVSUB.INP", "r", stdin);
    freopen("DIVSUB.OUT", "w", stdout);
    cin >> n >> P;
    cin >> s;

    xuli();
    return 0;
}
