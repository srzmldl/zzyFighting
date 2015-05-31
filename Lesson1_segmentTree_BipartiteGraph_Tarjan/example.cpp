#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstdlib>

const int oo = ~0U>>1;
using namespace std;

int main()
{
    int a, b;
    double c;
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cin >> a >> b >> c;
    cout << a + b + c;
    
    return 0;
}
