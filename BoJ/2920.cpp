#include <bits/stdc++.h>
using namespace std;
enum ADM_t{
    ascending,
    descending,
    mixed
};
string ADM[3] = {
    "ascending",
    "descending",
    "mixed"
};
int _input, _past, _ret;

int main()
{
    cin >> _input;
    if(_input == 1)
        _ret = ascending;
    else
        _ret = descending;
    _past = _input;
    for(int inCnt = 7; inCnt >0; inCnt--)
    {
        cin >> _input;
        if(_ret != mixed)
        {
            if(_input > _past)
            {
                if(_ret == descending)
                    _ret = mixed;
            }
            else if(_input < _past)
            {
                if(_ret == ascending)
                    _ret = mixed;
            }
        }
        _past = _input;
    }
    cout << ADM[_ret];
    return 0;
}