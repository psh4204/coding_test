/* https://www.acmicpc.net/problem/1644
소수의 연속합

자연수가 주어졌을때 연속된 소수의 합으로 나타낼 수 잇는 경우의수는?
- 자연수안에 소속된 "연속된 소수의 개수" (3+5+7 O. 3+5+5+7 X. 3+7 X.)

입력
- 숫자
출력
- 카운트

다시 풀기
- 소수구하기(에라토스체네스의 해)
- 소수들로 각 연속된 합을 구한뒤, 합이 나오면 PASS, 아니면 FAIL
- 해당 PASS카운트를 정답카운트에 ++;
*/
#include <bits/stdc++.h>
#define MAX_N 4000000
using namespace std;
int _N, _ret_cnt;
vector<int> _snums;
inline bool is_snum(int num)
{
    if(num == 1) return false;
    else if(num == 2) return true;
    else if(num%2 == 0) return false;
    for(int i = 3; i * i <= num; i++)
    {
        if(num%i == 0) return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> _N;
    // cout << "---\n"; // TEST
    for(int n_idx = 1; n_idx <= _N; n_idx++)
    {
        if(is_snum(n_idx))
        {
            // cout << n_idx << ", "; // TEST
            _snums.push_back(n_idx);
        }
    }
    // cout << "\n---\n"; // TEST
    for(int start = 0; start < _snums.size(); start++)
    {
        int sum = 0;
        int next = start;
        while(next < _snums.size() && sum < _N)
        {
            sum += _snums[next];
            next+=1;
        }
        if(sum == _N)
        {
            _ret_cnt++;
        }
    }
    cout << _ret_cnt;
    return 0;
}
