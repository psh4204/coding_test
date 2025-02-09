#include <bits/stdc++.h>
using namespace std;
int _a, _b;

int main()
{
    while (cin >> _a >> _b)
    {
        if(_a > 0 && _a < 10 && _b >0 && _b < 10)
            cout << _a+_b << "\n";
        else
            break;
    }
    
    return 0;
}