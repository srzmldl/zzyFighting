#include <iostream>
#include <ctime>
#include <cstdio>
#include <cmath>
#include <cstdlib>
//#include <bits/stdc++.h>
using namespace std;
int main()
{
 srand(clock() % time(0));
 freopen("zkw.in","w",stdout);
 int n=10, lim = 100000;
 cout<<n<<endl;
 for (int i=1;i<=n; i++)
  cout<<abs(rand()*rand()*rand()) % lim +1<<' ';
 cout << endl;
 int q=10;
 cout<<q<<endl;
 for (int i=1;i<=q;i++)
 {
   int c;
   c=rand() % 2 + 1;
   if (c==1)
    cout<<c<<' '<<rand() % 10 + 1 <<' '<<rand() % lim +1<<endl;
   else
    cout<<c<<endl;
 }
 return 0;
}
