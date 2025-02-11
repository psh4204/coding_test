#include <bits/stdc++.h>
using namespace std;
int _input, _diffCnt;
set<int> _diffNums;

int main()
{
    for(int inCnt = 0; inCnt < 10; inCnt++)
    {
        cin >> _input;
        _diffNums.insert(_input%42);
    }
    cout << _diffNums.size();
    return 0;
}