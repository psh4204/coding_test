#include <bits/stdc++.h>
using namespace std;
int _input, _min = 1000000, _max = -1000000, _N;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> _N;
    for(int nCnt = 0; nCnt < _N; nCnt++)
    {
        cin >> _input;
        _min = min(_min, _input);
        _max = max(_max, _input);
    }
    cout << _min << " " << _max;
    return 0;
}