/* https://www.acmicpc.net/problem/19942
다이어트

재료의 조합에서 각 모든 영양분(단,탄,지,비)이 최소 영양소가 되는 경우를 찾는다.
그 중 가격이 가장 저렴한 조합을 찾는다.

Input
- N (재료수. 3~15)
- 단 탄 지 비 (각재료별 영양분 리스트) (모든합은 1~500. 각영양소는 0~500)

Output
- 최소비용 (없으면 -1)
- 비용기준 재료 오름차순(비용이같으면 재료번호로 오름차순)

Try1
- 재료번호순서 조합은 비트연산으로 정의해서 써보자. (굳이? 싶지만)
- 이번 조합은 DFS로 완전탐색을 한다.
    - 단 비용이 구해진 최소값 보다 크면 return
(Note) 지역변수에 비트를 끄고 키는 거는 위험한 발상. 전역변수로 제어가능하면 전역변수 쓰도록.

Try2.
- 뭘해도 다틀림. (개짜증나네)
- 하... "사전순"으로 출력
    - 이건 map쓰란 말임.
*/
#include <bits/stdc++.h>
using namespace std;
int _N, _ret_min, _ret_combi, _calc_combi;   // min: 최소가격. combi: 조합(비트플래그)
vector<int> _min_vals;          // 최소 {단 탄 지 비}
vector<vector<int>> _ingred;    // {단 탄 지 비 가격}
vector<int> _calc_vals(5);         // DFS에서 사용될 ingred

void get_min_ret(int here)
{
    // 최소값 체크 및 ret 화
    int sum_min = 0;
    for(int yy_cnt = 0; yy_cnt < 5; yy_cnt++)
    {
        if(yy_cnt < 4 && _calc_vals[yy_cnt] < _min_vals[yy_cnt]) break;
        else if((yy_cnt == 4 && _calc_vals[4] < _ret_min) || (yy_cnt == 4 &&_ret_min == 0))
        {
            if(sum_min == 0 ) break;
            _ret_min = _calc_vals[4];
            _ret_combi = _calc_combi;
            return;
        }
        sum_min+= _calc_vals[yy_cnt];
    }

    for(int idx = here; idx < _N; idx++)
    {
        if(_calc_combi & (1<<idx))    continue;   // 이미 접근한 조합인경우 패스
        
        // 해당 재료의 영양소를 더하고, 콤비 값 설정
        for(int yy_cnt = 0; yy_cnt < 5; yy_cnt++)
            _calc_vals[yy_cnt] += _ingred[idx][yy_cnt];
        _calc_combi |= (1<<idx);

        // // [[TESTCODE]]
        // cout << "\n[" << idx <<"]" << _calc_vals[4] << ")\n";
        // for(int j = 0; j < _N; j++)
        // {
        //     if(_calc_combi & (1<<j))
        //         cout << j << " ";
        // } cout << "\n";

        get_min_ret(idx+1);

        // 탐색 후 값 해제
        _calc_combi &= ~(1<<idx);
        for(int yy_cnt = 0; yy_cnt < 5; yy_cnt++)
            _calc_vals[yy_cnt] -= _ingred[idx][yy_cnt];
    }
}

bool custom_cmp(pair<int,int> val1, pair<int,int> val2)
{
    if(val1.second > val2.second)
        return true;
    else if(val1.second == val2.second)
        return val1.first < val2.second;
    return false;
}

int main()
{
    cin >> _N;
    for(int in_cnt = 0; in_cnt < 4; in_cnt++)
    {
        int in = 0; cin >> in;
        _min_vals.push_back(in);
    }
    for(int ingr_cnt = 0; ingr_cnt < _N; ingr_cnt++)
    {
        _ingred.push_back({});
        for(int in_cnt = 0; in_cnt < 5; in_cnt++)
        {
            int in = 0; cin >> in;
            _ingred[ingr_cnt].push_back(in);
        }
    }

    // // [[TEST CODE]]
    // cout << "\n";
    // for(auto ingr:_ingred)
    // {
    //     for(auto yy:ingr)
    //         cout << yy << " ";
    //     cout << "\n";
    // }

    get_min_ret(0);

    if(_ret_combi == 0)
    {
        cout << -1;
        return 0;
    }

    map<int,vector<int>> ret_list;
    for(int idx = 0; idx < _N; idx++)
    {
        if(_ret_combi & (1<<idx))
            ret_list.insert({idx+1, _ingred[idx]});
    }
    cout << _ret_min << "\n";
    for(auto ret: ret_list)
        cout << ret.first << " ";

    return 0;
}