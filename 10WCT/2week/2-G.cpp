/* https://www.acmicpc.net/problem/2910
빈도정렬

주어진 숫자 의 빈도를 구하여 정렬해야함.
- C: 주어진 모든 숫자는 이 C의 이하다.
- 빈도를 중심으로 내림차순으로 정렬된다.
- 빈도가 같다면 먼저 나온 수가 앞에 있어야한다.

Input
- 메시지_길이 C (길이: 1~1K, C: 1~1M)
- N N N ... 

Output
- 빈도정렬

Try1
- map으로 값 받아온다
- map을 vector화 시킨 후 sort를 진행
    - 이때 전용 compare문을 작성한다.
*/
#include <bits/stdc++.h>
using namespace std;
int _M, _C; // 메시지길이, C

map<int, pair<int,int>> _num_cont_times; // (숫자, (연속카운트, 첫순서))

bool custom_cmp(pair<int, pair<int,int>> front, pair<int, pair<int,int>> back)
{
    if(front.second.first > back.second.first)      // 빈도가 더많으면 true
        return true;
    else if(front.second.first < back.second.first) // 빈도가 더 적으면 false
        return false;
    else                                            // 빈도가 같으면
    {
        if(front.second.second < back.second.second)
            return true; // 먼저나온 값이 앞에간다.
        else
            return false;
    }
}

int main()
{
    cin >> _M >> _C;
    for(int in_cnt = 1; in_cnt <= _M; in_cnt++)
    {
        int usr_num = 0;
        cin >> usr_num;
        _num_cont_times[usr_num].first++;
        if(_num_cont_times[usr_num].second == 0)
            _num_cont_times[usr_num].second = in_cnt;
    }
    vector<pair<int,pair<int,int>>> n_c_t(_num_cont_times.begin(), _num_cont_times.end());
    sort(n_c_t.begin(), n_c_t.end(), custom_cmp);
    for(auto num_datas: n_c_t)
    {
        for(int cont_idx = 0; cont_idx < num_datas.second.first; cont_idx++)
            cout << num_datas.first << " ";
    }
    return 0;
}
