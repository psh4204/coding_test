/* https://www.acmicpc.net/problem/2529
부등호

K 개의 부등호에 중복되지않는 숫자로 조합을 구하라.
K는 2~9개 (예시 2: > < , 9: ><><>>><<> ... )
숫자 0~9

Output
- 최대정수
- 최소정수

Try1
- 숫자 0 부터 부등호에 맞는 조합을 찾아야함.
- 재귀문으로 해야할것으로 보임. cnt가 맞춰지면 cout해주는 형식으로 하면 될듯
- 이거도 visited 1만들어주고 0풀어주는 타이밍만 맞추면 바로 될듯.
- 부등호를 _dy,_dx사용하듯 왼쪽수, 오른쪽수 이런식으로 해야겠네
    (0이면 왼쪽, 1이면 오른쪽)
- 일반 구현 후 최대 최소도 구현하자
*/
#include <bits/stdc++.h>
#define TRSH 66
using namespace std;
int _N;
vector<int> _budus; // 부등호들
vector<int> _v(10, TRSH);     // visited (0~9).. 히스토리저장도해야하니 트레이스 인덱스 넣자.
vector<string> _ret;   // 정답을 모조리 때려박자. // TODO

// here: 부등호 카운트, pre_num: 트레이스용 이전숫자.
void search_nums(int here, int pre_num)
{
    // cout << here << ":" << pre_num << "\n";// [[TEST]]

    if(here == _budus.size())
    {
        vector<int> nums;
        string ret; ret.clear();
        int pre_n = pre_num;
        for(int n = 0; n < _budus.size()+1; n++)
        {
            nums.push_back(pre_n);
            pre_n = _v[pre_n];
        }
        // TODO: 리버스 없이 계산값 반대로 넣자.
        for(int ni = nums.size()-1; ni >= 0; ni--)
        {
            ret += (char)(nums[ni]+'0');
        }

        // reverse(nums.begin(), nums.end());
        // for(auto num: nums)
        //     cout << num;
        // cout << ret <<"\n";
        _ret.push_back(ret);
        return;
    }
    for(int n_num = 9; n_num >= 0; n_num--)
    {
        if((_budus[here] == 0 && n_num < pre_num)
        ||(_budus[here] == 1 && n_num > pre_num))
        {
            if(_v[n_num] == TRSH)
            {
                _v[n_num] = pre_num; // visited 겸 trace index남기기
                search_nums(here+1, n_num);
                _v[n_num] = TRSH;
            }
        }
        else if(pre_num == -1)
        {
            _v[n_num] = pre_num; // visited 겸 trace index남기기
            search_nums(here+1, n_num);
            _v[n_num] = TRSH;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> _N;
    _budus.resize(_N);
    for(int n = 0; n < _N; n++)
    {
        char in;
        cin >> in;
        if(in == '<')   _budus[n] = 1;
    }
    search_nums(-1, -1);
    cout << _ret[0] << "\n" << _ret[_ret.size()-1];
    return 0;
}