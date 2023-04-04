#include <bits/stdc++.h>
#define ll long long
#define INF INFINITY
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM = 3e3 + 10;
int n;
string s[55];
vector<int> block[NM];
int numBlocked[NM], near[11];

void readfile(){
    freopen("EQUIVALENT.INP", "r", stdin);
    freopen("EQUIVALENT.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> s[i];
}
string minStr(string x){
    int sz = x.length();
    for(int i = 0; i < sz; i++){
        block[i].clear();
        numBlocked[i] = 0;
    }
    for(int i = 0; i <= 10; i++) near[i] = -1;
    for(int i = 0; i < sz; i++){
        for(char d = x[i] - 1; d <= x[i] + 1; d++){
            int m = int(d) - 48;
            if(m == -1) continue;
            if(near[m] != -1){
                block[near[m]].push_back(i);
                numBlocked[i]++;
            }
        }
        near[int(x[i]) - 48] = i;
    }
    priority_queue<pair<char, int>, vector<pair<char, int>>, greater<pair<char, int>>> pq;
    for(int i = 0; i < sz; i++)
        if(numBlocked[i] == 0) pq.push(make_pair(x[i], i));
    string res;
    while(!pq.empty()){
        res.push_back(pq.top().first);
        int pos = pq.top().second;
        pq.pop();
        for(int u : block[pos]){
            if(--numBlocked[u] == 0) pq.push(make_pair(x[u], u));
        }
    }
    return res;
}
void xuli(){
    set<string> ans;
    vector<string> res;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < s[i].length(); j++){
            string newS = s[i].substr(j) + s[i].substr(0, j);
            ans.insert(minStr(newS));
        }
    }
    cout << ans.size();
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
