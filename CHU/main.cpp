#include <bits/stdc++.h>

using namespace std;

int n;
string s;
int a[1000005];

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> s;
        for(int j = 0; j < s.length(); j++){
            if(s[j] >= '0' && s[j] <= '9') a[i] += s[j] - '0';
        }
        cout << a[i] << '\n';
    }
    return 0;
}
