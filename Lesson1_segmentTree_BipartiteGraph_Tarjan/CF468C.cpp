#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

int main()
{
    ull a;
    cin >> a;
    ull s = 45 * 18;
    for (int i = 1; i <= 17; ++i)
        s = (s * 10) % a;
    s = (s + 1) % a;
    ull k = (a - s) % a;
    cout << 1 + k << ' ' << (ull)1e18 + k << endl;
    
    return 0;
}
