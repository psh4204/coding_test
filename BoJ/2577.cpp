#include <bits/stdc++.h>
using namespace std;
long long _A, _B, _C, _Ret; 
string _strRet;
vector<int> _nums(10,0);

int main()
{
    cin >> _A >> _B >> _C;
    _Ret = _A * _B * _C;
    _strRet = to_string(_Ret);

    for(auto chNum: _strRet)
        _nums[chNum-'0']++;
    
    for(auto val: _nums)
        cout << val << "\n";

    return 0;
}