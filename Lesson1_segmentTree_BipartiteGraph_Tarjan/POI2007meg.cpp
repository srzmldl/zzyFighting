#include <bits/stdc++.h>
#define MAXN 801234

using namespace std;
typedef int arrayN[MAXN];

int n, num, now, m, base, d[MAXN * 4];
arrayN fir, e, nxt;

struct node
{
    int l, r;
} g[MAXN];

void link(int u, int v)
{
    e[++num] = v, nxt[num] = fir[u];
    fir[u] = num;
}

void dfs(int u)
{
    g[u].l = ++now;
    for (int p = fir[u]; p; p = nxt[p], ++now)
        dfs(e[p]);
    if (fir[u] == 0) ++now;
    g[u].r = now;
}

void change(int x, int value)
{
    d[x += base] = value;
    for (x >>= 1; x; x >>= 1)
        d[x] = d[x << 1] + d[x << 1 ^ 1];
}

int ask(int l, int r)
{
    int tmp = 0;
    for (l += base - 1, r += base + 1; (l ^ r) != 1; l >>= 1, r >>= 1)
    {
        if (!(l & 1)) tmp += d[l + 1];
        if (r & 1) tmp += d[r - 1];
    }
    return tmp;
}

int main()
{
    //freopen("a.in", "r", stdin);
    cin >> n;
    for (int i = 1; i < n; ++i)
    {
        int u, v;
        cin >> u >> v;
        link(u, v);
    }
    dfs(1);
    for (base = 1; base <= now; base <<= 1);
    for (int i = 1; i <= n; ++i)
    {
        change(g[i].l, 1);
        change(g[i].r, -1);
    }
    cin >> m;
    for (int i = 1; i <= m + n - 1; ++i)
    {
        string st;
        cin >> st;
        if (st == "W")
        {
            int k;
            cin >> k;
            cout << ask(1, g[k].l) - 1 << endl;
        } else
        {
            int u, v;
            cin >> u >> v;
            change(g[v].l, 0);
            change(g[v].r, 0);
        }
    }
    return 0;
}
