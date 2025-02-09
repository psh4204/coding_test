#include <bits/stdc++.h>
using namespace std;
string _S;
int _tc, _repeat;

int main()
{
    cin >> _tc;
    for(int nCnt = 0; nCnt < _tc; nCnt++)
    {
        cin >> _repeat >> _S;
        for(int sNum = 0; sNum < _S.length(); sNum++)
        {
            for(int rptCnt = 0; rptCnt < _repeat; rptCnt++)
                cout << _S[sNum];
        }
        cout << "\n";
    }
    return 0;
}