#include <bits/stdc++.h>
using namespace std;

int main()
{
    int _n = 0;
    cin >> _n;
    for(int cnt = 1; cnt <= _n; cnt++)
    {
        for(int spcCnt = 0; spcCnt < _n-cnt; spcCnt++)
            cout << " ";
        for(int strCnt = 0; strCnt < cnt; strCnt++)
            cout << "*";
        cout <<"\n";
    }

    return 0;
}
