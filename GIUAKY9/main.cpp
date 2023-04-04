#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("QUIZ.INP", "r", stdin);
    freopen("QUIZ.OUT", "w", stdout);
    int n, k;
    cin >> n >> k;
    int res = 0;
    for(int i = 2; i <= n; i++){
        int cnt = 1;
        for(int j = 1; j <= i / 2; j++)
            if(i % j == 0) cnt++;
        if(cnt == k) res++;
    }
    cout << res;
    return 0;
}
