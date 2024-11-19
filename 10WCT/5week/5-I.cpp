/* https://www.acmicpc.net/problem/3273
두 수의 합

수열, a1+ a2 = x 가 되는 a1,a2 쌍의 수 구하는 프로그램.

입력
- 수열의 크기 n (1~100,000)
- 수열
- x(1~200,000)

출력
- 쌍의 수

풀이
- 투포인터 문제.
- 조합으로 풀어야함.
*/
#include <bits/stdc++.h>
using namespace std;
int _N, _X, _l_idx, _r_idx;
long long _ret;
vector<int> _nums;

int main()
{
    cin >> _N;
    _nums.resize(_N,0);
    for(int n_cnt = 0; n_cnt < _N; n_cnt++)
        cin >> _nums[n_cnt];
    cin >> _X;
    sort(_nums.begin(), _nums.end());
    _r_idx = _nums.size()-1; 
    while(_l_idx < _r_idx)
    {
        if(_nums[_l_idx] + _nums[_r_idx] == _X)
        {
            _r_idx--;
            _ret++;
        }
        else if(_nums[_l_idx] + _nums[_r_idx] > _X)
            _r_idx--;
        else
            _l_idx++;
    }
    cout << _ret;
    return 0;
}