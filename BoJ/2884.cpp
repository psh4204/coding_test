#include <bits/stdc++.h>
using namespace std;
int _hours, _mins;

int main()
{
    cin >> _hours >> _mins;
    if(_mins < 45)
    {
        _mins = 60+_mins - 45;
        _hours = _hours == 0 ? 23 : _hours-1;
    }
    else
    {
        _mins -=45;
    }
    cout << _hours << " " << _mins;
    return 0;
}