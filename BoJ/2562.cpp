#include <bits/stdc++.h>
using namespace std;
int _inNum, _maxNum, _numAddr;

int main()
{
    for(int nCnt = 1; nCnt <= 9; nCnt++)
    {
        cin >>_inNum;
        if(_inNum > _maxNum)
        {
            _maxNum = _inNum;
            _numAddr = nCnt;
        }
    }
    cout << _maxNum << "\n" << _numAddr;
    return 0;
}