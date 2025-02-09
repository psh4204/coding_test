#include <bits/stdc++.h>
using namespace std;
int _n,_x, _inNum;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> _n >> _x;
    for(int inCnt = 0; inCnt < _n; inCnt++)
    {
        cin >> _inNum;
        if(_inNum < _x)    cout << _inNum << " ";
    }
    
    return 0;
}