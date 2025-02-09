#include <bits/stdc++.h>
using namespace std;
int _n = 0, _ret = 0;
string _nums;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> _n >> _nums;
    for(int n_cnt = 0; n_cnt < _n; n_cnt++)
    {
        _ret += (_nums[n_cnt] - '0');
    }
    cout << _ret;
    return 0;
}
