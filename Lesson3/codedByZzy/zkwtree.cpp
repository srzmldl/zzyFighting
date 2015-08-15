#include <bits/stdc++.h>

using namespace std;
#define MAXN 100
int a[MAXN],g[4*MAXN];
int q,c,x,t;
int base;
int n;
void change(int temp,int x)
{
    g[temp]=x;
    temp>>=1;
    for (;temp;temp>>=1)
        g[temp]=max(g[temp<<1],g[(temp<<1)^1]);
}
int main()
{
    freopen("zkw.in", "r", stdin);
    freopen("zkw.out","w",stdout);
    cin>>n;

    for(base=1;base<=n+1;base<<=1);
    memset(g,0,sizeof(g));
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        change(base+i,a[i]);
    }
    cin >> q;
    for (int i=1;i<=q;i++)
    {
        cin>>c;
        if (c==1)
        {
            cin>>t>>x;
            a[t]=x;
            change(t+base,x);
        }
        else
            cout<<g[1]<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
