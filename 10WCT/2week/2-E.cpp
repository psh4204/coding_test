/* https://www.acmicpc.net/problem/1992
쿼드트리

영상을 위(왼,오), 아래(왼,오) 로 4분할 하여 압축하는 방식.
위의 순서대로 0,1로 된 영상을 쿼드프리하여 나타내시오.

Input
- N: 영상 가로세로 픽셀 수 (1~64)
- 영상 arr

Output
- (왼위,오위,왼아래, 오아래) 이런식 // (0(0011)(0(0111)01)1)

Try 1
- 괄호 문제니까 스택.
- 4방향간 깊이탐색해야하는걸로보임(재귀써야해서)
- 재귀함수 내에 4방향간 재귀문 삽입하여 순회하도록 하기.
- 4방향전부 연속한 숫자가 나오면 그 숫자 String에 하나 쌓은 후 끝.
- 같은 수가 안나오면 바로 해당 재귀함수 시작.
- 4방향 재귀함수가 시작할땐 여는괄호, 재귀함수가 끝나면 닫는괄호.
- 생각해보니, 스택에 그냥 값을 쌓고, 연속된 숫자가 나오는지는 그냥 리턴할때 처리하면 되는거 아님?
- 스택순서대로 쌓기는 어느정도 끝냈음. 그럼 처리하는 코드를 짜보자
    - 숫자가 4번연속되는지 체크한다. 연속되면 그 숫자 cout. 하지않으면 숫자그대로 보여준다.
    - 괄호처리는 어떻게 해야할까?



4
1100
1100
1100
0011


==> 테케 확인했는데도 다맞은데 다틀렸다 뜸.. 질문올렸고 뭐가 문제인지 확인해보자.

*/
#include <bits/stdc++.h>
using namespace std;
int _N = 0;
vector<char> _ret; // (ret);

void div_arr_and_push_value(pair<int,int> pre_l_up, pair<int,int> pre_r_dwn, int pre_arr_len, vector<vector<char>>& arr)
{
    if(pre_arr_len <= 1)
    {
        _ret.push_back(arr[pre_l_up.first][pre_r_dwn.second]);
        return;
    }
    _ret.push_back('(');
    int curr_arr_len = pre_arr_len/2;
    // 왼위
    div_arr_and_push_value(pre_l_up,{pre_r_dwn.first- curr_arr_len, pre_r_dwn.second- curr_arr_len}, curr_arr_len, arr);
    // 오위
    div_arr_and_push_value({pre_l_up.first, curr_arr_len},{pre_r_dwn.first- curr_arr_len, pre_r_dwn.second}, curr_arr_len, arr);
    // 왼아래
    div_arr_and_push_value({pre_l_up.first + curr_arr_len, pre_l_up.second},{pre_r_dwn.first,pre_r_dwn.second-curr_arr_len}, curr_arr_len, arr);
    // 오른아래
    div_arr_and_push_value({pre_l_up.first + curr_arr_len, curr_arr_len},pre_r_dwn, curr_arr_len, arr);

    // 압축처리
    int last_idx = _ret.size()-1;
    char str_num = _ret[last_idx];
    for(int same_cnt = 0; same_cnt < 4; same_cnt++)
    {
        // 4번연속안겹치는 게 확인되면 닫는괄호 후 break;
        if(_ret[last_idx - same_cnt] != str_num)
        {
            _ret.push_back(')');
            break;
        }
        if(same_cnt == 3)
        {
            // 여는 괄호와 해당 숫자를 전부 날려준다.
            for(int pop_cnt = 0; pop_cnt < 5; pop_cnt++)
                _ret.pop_back();
            // 그 숫자를 준다.
            _ret.push_back(str_num);
        }
    }
}

int main()
{
    cin >> _N;
    vector<vector<char>> arr(_N);
    for(int usr_idx = 0; usr_idx < _N; usr_idx++)
    {
        string usr_str;
        cin >> usr_str;
        for(auto ch: usr_str)
            arr[usr_idx].push_back(ch);
    }
    int arr_size = arr.size();
    int r_idx = arr_size-1;
    div_arr_and_push_value({0,0},{r_idx, r_idx}, arr_size, arr);
    
    for(auto ch: _ret)
        cout << ch;
    return 0;
}