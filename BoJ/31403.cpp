#include <bits/stdc++.h>
using namespace std;
int _a, _b, _c;

int main()
{
    cin >> _a >> _b >> _c;
    cout << (_a + _b - _c) << "\n";
    if(_b >= 0 && _b <10)
        cout << _a*10 + _b - _c << "\n";
    else if(_b >= 10 && _b <100)
        cout << _a*100 + _b - _c << "\n";
    else if(_b >= 100 && _b <1000)
        cout << _a*1000 + _b - _c << "\n";
    else if(_b == 1000)
        cout << _a*10000 + _b - _c << "\n";
    return 0;
}

