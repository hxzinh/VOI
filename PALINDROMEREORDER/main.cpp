#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

string s;
int a[30];
stack<char> ans, odd;
queue<char> res;

int main()
{
    FastIO
    cin >> s;

    int numOdd = 0;
    for(int i = 0; i < s.size(); i++) a[s[i] - 'A']++;
    for(int i = 0; i < 26; i++) if(a[i] % 2 != 0) numOdd++;

    if(numOdd >= 2) cout << "NO SOLUTION";
    else {
        char u;
        for(int i = 0; i < 26; i++) if(a[i]) {
            if(a[i] % 2 == 0)
            for(int j = 1; j <= a[i]; j += 2){
                ans.push(char(i + 'A'));
                res.push(char(i + 'A'));
            }
            else for(int j = 1; j <= a[i]; j++) odd.push(char(i + 'A'));
        };

        while(res.size()){
            cout << res.front();
            res.pop();
        }
        while(odd.size()){
            cout << odd.top();
            odd.pop();
        }
        while(ans.size()){
            cout << ans.top();
            ans.pop();
        }
    }
    return 0;
}
