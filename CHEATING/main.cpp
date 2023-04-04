#include <bits/stdc++.h>
#define ll long long
#define oo 99999999999
#define ii pair<int,int>
#define fi first
#define se second
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM=3e5;
ll numProblem,numPerson,times,sub,T;
pair<int,int> point[NM]; ///fi : do kho. se : chi so
int fix[NM]; ///chi so nguoi lam bai thu i

struct Person
{
    int limit,cost,pos;
    Person() {
        limit = 0;
        cost = 0;
        pos = 0;
    }
    bool inline operator < (const Person &A)const {
        return limit > A.limit;
    }
};
Person people[NM];

bool cmp(ii A,ii B){
    if(A.fi == B.fi) return A.se > B.se;
    else return A.fi > B.fi;
}

///kiem tra xem nguoi do co lam dc maxProblem bai ko
bool ok(int maxProblem){
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    int probID=1, personID=1, cost=0;
    while(probID <= numProblem){
        while(personID <= numPerson && people[personID].limit >= point[probID].fi){
            int u = people[personID].limit;
            pq.push({people[personID].cost, people[personID].pos});
            personID++;
        }
        if(pq.empty()) return false;
        int mincost = pq.top().fi, pos = pq.top().se;
        pq.pop();
        cost+=mincost;
        if(cost > times) return false;
        for(int i=0;i<maxProblem;i++){
            fix[point[probID].se] = pos;
            probID++;
            if(probID > numProblem) break;
        }
    }
    return true;
}
int getAns(){
    int res=-1;
    int d=1, c = numProblem, g;
    if(!ok(c)) return -1;
    while(d <= c){
        g=(d+c)/2;
        if(ok(g)){
            res=g;
            c=g-1;
        }
        else d=g+1;
    }
    return res;
}
void xuli(){
    int res = getAns();
    if(res == -1) cout << "NO" << '\n';
    else {
        cout << "YES" << '\n';
        assert(ok(res));
        for(int i=1;i<=numProblem;i++){
            cout << fix[i] << " ";
        }
    }
    cout << '\n';
}
void readfile()
{
    freopen("cheating.inp","r",stdin);
    freopen("cheating.out","w",stdout);
    cin >> sub >> T;
    for(int task=1;task<=T;task++){
        cin >> numPerson >> numProblem >> times;
        for(int i=1;i<=numProblem;i++){
            cin >> point[i].fi;
            point[i].se = i;
        }
        for(int i=1;i<=numPerson;i++){
            cin >> people[i].limit;
        }
        for(int i=1;i<=numPerson;i++){
            cin >> people[i].cost;
        }
        for(int i=1;i<=numPerson;i++){
            people[i].pos = i;
        }
        sort(point+1,point+numProblem+1,cmp);
        sort(people+1,people+numPerson+1);
        xuli();
    }
}
int main()
{
    FastIO
    readfile();
    return 0;
}
