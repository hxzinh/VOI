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

const int MOD = (int)1e9 + 7;

void add(int &x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
}
void sub(int &x, int y) {
    x -= y;
    if (x < 0) x += MOD;
}

string S;
stack <char> st, st2;

int main()
{
    FastIO
    freopen("BRACKETS.INP", "r", stdin);
    freopen("BRACKETS.OUT", "w", stdout);
    cin >> S;

    for (int i = 0; i < S.size(); ++i) {
        if (st.empty() && (S[i] == ')' || S[i] == ']' || S[i] == '}')) st2.push(S[i]);
        else if (S[i] == ')') {
            if (st.top() == '(') st.pop();
            else {
                cout << "No";
                return 0;
            }
        }
        else if (S[i] == ']') {
            if (st.top() == '[') st.pop();
            else {
                cout << "No";
                return 0;
            }
        }
        else if (S[i] == '}') {
            if (st.top() == '{') st.pop();
            else {
                cout << "No";
                return 0;
            }
        }
        else st.push(S[i]);
    }

    if (st.size() != st2.size()) {
        cout << "No";
        return 0;
    }

    while (!st.empty()) {
        char x = st.top();
        char y = st2.top();
        st.pop(), st2.pop();
        if (!((x == '(' && y == ')') || (x == '[' && y == ']') || (x == '{' && y == '}'))) {
            cout << "No";
            return 0;
        }
    }

    cout << "Yes";

    return 0;
}
