#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define MAXN 8005

using namespace std;

struct node
{
    int y1, y2, x;
} a[MAXN];

bool bj[MAXN];
int num, e[MAXN * 12], next[MAXN * 12];
int low, high, fir[MAXN], n, co[MAXN * 2];

void fileOpen()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}

int com(node u, node v) {return u.x < v.x;}

void origin()
{
    memset(fir, 0, sizeof(fir));
    num = 0;
    memset(co, 0, sizeof(co));
}

void link(int u, int v)
{
    e[++num] = v, next[num] = fir[u];
    fir[u] = num;// bj[u][v] = 1;
}

int main()
{
    //fileOpen();
    int task;
    for (scanf("%d", &task); task; --task)
    {
	origin();
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	    scanf("%d%d%d", &a[i].y1, &a[i].y2, &a[i].x);
	sort(a + 1, a + 1 + n, com);
	for (int i = 1; i <= n; ++i)
	{
	    memset(bj, 0, sizeof(bj));
	    for (int j = 2 * a[i].y1 + 1; j <= 2 * a[i].y2 + 1; ++j)
	    {
		if (co[j] && !bj[co[j]]) link(i, co[j]), bj[co[j]] = 1;
		co[j] = i;
	    }
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i)
	{
	    memset(bj, 0, sizeof(bj));
	    for (int p = fir[i]; p; p = next[p])
		bj[e[p]] = 1;
	    for (int p = fir[i]; p; p = next[p])
		if (bj[e[p]])
		    for (int q = fir[e[p]]; q; q = next[q])
			if (bj[e[q]]) ++ans;
	}
	printf("%d\n", ans);
    }
    return 0;
}
