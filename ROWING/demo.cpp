void Shiba_Read()
{
    cin >> n >> h;
    for (int i = 1; i <= n; ++i) cin >> a[i].fi >> a[i].se;
}

void Shiba_Process()
{
    for (int i = 1; i <= n; ++i) adj[0][i] = adj[i][0] = SQR(a[i].se);
    for (int i = 1; i <= n; ++i) adj[n + 1][i] = adj[i][n + 1] = SQR(h - a[i].se);
    adj[0][n + 1] = adj[n + 1][0] = SQR(h);

    for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j)
        adj[i][j] = (a[i].fi - a[j].fi) * (a[i].fi - a[j].fi) + (a[i].se - a[j].se) * (a[i].se - a[j].se);

    for (int i = 1; i <= n + 1; ++i) F[i] = 2e18;

    priority_queue <li, vector <li>, greater <li>> pq;
    pq.push({0, 0});

    while (!pq.empty())
    {
        int u = pq.top().se;
        long long dp = pq.top().fi;
        pq.pop();

        if (dp != F[u]) continue;

        for (int v = 0; v <= n + 1; ++v)
        if (minimize(F[v], max(F[u], adj[u][v]))) pq.push({F[v], v});
    }

    cout << int(sqrt(F[n + 1]));
}
