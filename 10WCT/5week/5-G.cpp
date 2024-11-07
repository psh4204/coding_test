/* https://www.acmicpc.net/problem/1644
소수의 연속합

자연수가 주어졌을때 연속된 소수의 합으로 나타낼 수 잇는 경우의수는?
- 자연수안에 소속된 "연속된 소수의 개수" (3+5+7 O. 3+5+5+7 X. 3+7 X.)

입력
- 숫자
출력
- 카운트

풀이
- 소수의 특성. 그 어느 수에도 나눠지지 않음.
- 나눠지지 않는 수를 쌓은 후, 그 수의 합이 주어진 자연수와 일치하는지 체크
- 소수집합을 만들어야함.
    - 2로 시작해서, 다음 값에 +1 혹은 *2 씩 한후, 집합의 값과 안나눠지는 수를 쌓는다.
    - 동시에 합을 체크한다.
    - 어차피 빅오가 팩토리얼이라고 쳐도, 2~11 사이 선으로 수가 마무리 될거임.

// 다시풀기 (소수 구한 후 그리드로 푸는 문제임.)

*/
#include <bits/stdc++.h>
using namespace std;
struct num_t{
    int n;
    int sum_n;
};
int _N;
vector<num_t> _nums;

int main()
{
    cin >> _N;
    _nums.push_back({n:2,sum_n:2}); // num, sum
    while(true)
    {
        cout << _nums[_nums.size()-1].n << " " << _nums[_nums.size()-1].sum_n << "\n"; // TEST
        // 현재 소수의 합이 입력갑과 같거나 크다면 루프탈출.
        if(_nums[_nums.size()-1].sum_n >= _N) break;
        // 아니라면 소수 만들어서 다음 합 구하기.
        bool is_make_num = false;
        num_t n_num = {_nums[_nums.size()-1].n,0};
        while(!is_make_num)
        {
            n_num.n++;
            for(int n_cnt = 0; n_cnt < _nums.size(); n_cnt++)
            {
                cout << "... " << n_num.n << "     cnt: " << n_cnt << "\n"; // TEST
                if(n_num.n % _nums[n_cnt].n != 0)
                {
                    cout << "(!) " << n_num.n << " old_sum: " << _nums[_nums.size()-1].sum_n << "\n";
                    n_num.sum_n = n_num.n + _nums[_nums.size()-1].sum_n;
                    _nums.push_back(n_num);
                    is_make_num = true;
                    break;
                }
            }
        }
    }
    if(_nums[_nums.size()-1].sum_n == _N)
        cout << _nums.size();
    else
        cout << 0;
    return 0;
}
