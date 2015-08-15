#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
#define MAXN 100
int a[MAXN];
int i,n,c,q,x,y,ans,j;
int main()
{
   freopen("zkw.in","r",stdin);
   freopen("zkw1.out","w",stdout);
   cin>>n;
   for (int i=1;i<=n;i++)
    cin>>a[i];
   cin>>q;
   cout << 1;
   for (int i=1;i<=q;i++)
    {
       cin>>c;
       if (c==1)
        {
          cin>>x>>y;
          a[x]=y;
        }
        else
         {
          ans=0;
		  for (int j=1;j<=n;j++)
		   ans=max(ans,a[j]);
		  cout<<ans<<endl;
		  }
    }
   fclose(stdin);
   fclose(stdout);
   return 0;
}
