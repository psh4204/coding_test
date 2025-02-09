#include <bits/stdc++.h>
using namespace std;
int _inNum = 0 ,_ret = 0;

int main()
{
    for(int inCnt = 0; inCnt < 5; inCnt++)
    {
        cin >>_inNum;
        _ret += pow(_inNum,2);
    }
    cout << _ret%10;
    return 0;
}