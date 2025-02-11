#include <bits/stdc++.h>
using namespace std;
vector<bool> _students(31,false);

int main()
{
    for(int cnt = 0; cnt < 28; cnt++)
    {
        int studentNum = 0;
        cin >> studentNum;
        _students[studentNum] = true;
    }
    for(int idCnt = 1; idCnt <= 30; idCnt++)
    {
        if(!_students[idCnt])
            cout << idCnt << "\n";
    }
    return 0;
}