// Flower_On_Stone
#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second

using namespace std;

const int MAX_N = 5005;
const int MAX_NODE = 4000005;
const int ALPHABET_SIZE = 26;

int n, k;
vector<pair<int, int>> adj[MAX_N * 2];
long long dp[MAX_N * 2][MAX_N], tmp[MAX_N];
int id[MAX_NODE], curId = 0;
int sizeTree[MAX_N * 2];

int getId(int x)
{
    if (id[x] == 0)
    {
        id[x] = ++curId;
    }
    return id[x];
}

struct TrieTree
{
    struct TrieNode
    {
        int cnt, stop, depth;
        int children[ALPHABET_SIZE];
    };
    TrieNode nodes[MAX_NODE];
    int root, numNode;
    int newNode()
    {
        numNode++;
        nodes[numNode].cnt = nodes[numNode].stop = 0;
        for (int i = 0; i < ALPHABET_SIZE; i++)
        {
            nodes[numNode].children[i] = 0;
        }
        return numNode;
    }
    void init()
    {
        numNode = -1;
        root = newNode();
    }
    int addWord(string &s)
    {
        int current = root, sz = s.size();
        for (int i = 0; i < sz; i++)
        {
            int nch = s[i] - 'a';
            if (nodes[current].children[nch] == 0)
            {
                int tmp = newNode();
                nodes[current].children[nch] = tmp;
            }
            current = nodes[current].children[nch];
        }
        nodes[current].stop++;
        return current;
    }
    void dfs(int node, int parent, int depth)
    {
        nodes[node].depth = depth;
        int numChild = 0;
        for (int i = 0; i < ALPHABET_SIZE; i++)
        {
            if (nodes[node].children[i] > 0)
            {
                numChild++;
            }
        }
        if (nodes[node].stop > 0 || numChild > 1)
        {
            if (parent != node)
            {
                adj[getId(parent)].push_back(make_pair(getId(node), depth - nodes[parent].depth));
            }
            parent = node;
        }
        if (nodes[node].stop > 0)
        {
            sizeTree[getId(node)] = nodes[node].stop;
        }
        for (int i = 0; i < ALPHABET_SIZE; i++)
        {
            if (nodes[node].children[i] > 0)
            {
                dfs(nodes[node].children[i], parent, depth + 1);
            }
        }
    }
} trie;

void dfs(int node)
{
    for (ii t : adj[node])
    {
        int u = t.fi, w = t.se;
        dfs(u);
        for (int i = 0; i <= sizeTree[node]; i++)
        {
            for (int j = 0; j <= sizeTree[u]; j++)
            {
                tmp[i + j] = max(tmp[i + j], dp[node][i] + dp[u][j] + 1LL * j *(j-1)/2 * w);
            }
        }
        sizeTree[node] += sizeTree[u];
        for (int i = 0; i <= sizeTree[node]; i++)
        {
            dp[node][i] = tmp[i];
            tmp[i] = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("PRESEQ.INP", "r", stdin);
    freopen("PRESEQ.OUT", "w", stdout);
    cin >> n >> k;
    trie.init();
    for (int i = 1; i <= n; i++)
    {
        string str;
        cin >> str;
        trie.addWord(str);
    }
    trie.dfs(0, 0, 0);
    dfs(1);
    cout << dp[1][k];
    return 0;
}
