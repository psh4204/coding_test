/* https://www.acmicpc.net/problem/13144
List of Unique Numbers

길이 N인 수열에서 연속된 1개이상의 수를 뽑았을때, 
같은수가 여러번 등장하지않는 경우의 수는?

입력
- 수열길이 N
- 수열

출력
- 조건을 만족하는 경우의 수

풀이
- 수열에서 연속된 하나이상의 수를 뽑는다 = "수열" 이라는 것을 잊지말자
- 나열 된 수에서 차례로 뽑으라는 말(문제가 이상한거 아님?)
- 1 2 3 4 5
    - 1/ 12/ 123/ 1234/ 12345
    - 2/ 23/ 234/ 2345
    - 3/ 34/ 345
    - 4/ 45
    - 5
    - 15게
- (TC1)
1 2 3 1 2
- 1 / 12/ 123
- 2/ 23/ 231
- 3/ 31/ 312/ 1/ 12/ 2/
- (TC4)
5
1 2 1 3 3
- 1/ 12
- 2/ 21/ 213
- 1/ 13/
- 3
- 3

3
1 2 1
- 1/ 12
- 2/ 21/ 1

4
1 2 1 1
- 1/ 12
- 2/ 21
- 1
- 1
- 해쉬를 사용새서 쭉 카운트 하자.
- (시간초과). 등차수열의 합으로 구하자(경우의 수는 웬만하면 다 이거로 되더라)
    - n(n+1)/2
    - (HINT) 중복구간은 그냥 카운트만/ 마지막에서 등차수열 계산
    - 이렇게 하면 중복 뽑기없이 카운트 가능.
- (시간초과) 해쉬가 너무 느려서, 각 숫자 인덱스 방문배열을 만듦.
- (틀림) 단위초과로 long long 처리 해서 맞음.
*/
#include <bits/stdc++.h>
#define MAX_NUM 100001
#define ll_t      long long
using namespace std;
ll_t _N, _ret;
vector<int> _nums;
vector<int> _idx_v(MAX_NUM, -1);// 해쉬가 너무 느려서, 인덱스 방문배열로 풀었음.

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> _N;
    _nums.resize(_N);
    for(ll_t n_idx = 0; n_idx < _N; n_idx++)
        cin >> _nums[n_idx];
    for(ll_t cur_idx = 0; cur_idx < _N; cur_idx++)
    {
        // cout << "START: " << _nums[cur_idx] << " ";// TEST
        _idx_v[_nums[cur_idx]] = cur_idx;
        ll_t sub_idx = cur_idx +1; // 해당 숫자 현재 인덱스로 방문처리
        while(sub_idx < _N)
        {
            if(_idx_v[_nums[sub_idx]] == cur_idx)
                break;
            // cout << _nums[sub_idx] << " "; // TEST
            _idx_v[_nums[sub_idx]] = cur_idx; // 해당 숫자 현재 인덱스로 방문처리
            sub_idx++;
        }
        // cout << ":END\n"; // TEST
        ll_t sn_size = sub_idx - cur_idx;
        if(sub_idx == _N) // 끝구간인지 체크
        {
            _ret += (sn_size*(sn_size+1))/2;
            break;
        }
        else
            _ret += sn_size;
    }
    cout << _ret;
    return 0;
}