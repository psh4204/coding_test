/* 8단 변속기
1~8단 연속변속 = ascending
8~1단 연속변속 = descending
둘다 아니면    = mixed

변속순서가 주어졌을 때 위의 판단을 하는 프로그램 작성.

입력
- 8개의 숫자
출력
- ascending, descending, mixed 중 1개

풀이
- 루프문으로 받은 후, 다른 루프문에서 체크한다.
*/

#include<bits/stdc++.h>
using namespace std;
enum ret_type{
    ascending = 0,
    descending,
    mixed,
};
string _str_ret[3] = {
    "ascending",
    "descending",
    "mixed",
};

vector<int> _inputs(8,0);
ret_type _ret, _prev_ret;

int main(int argc, char** argv)
{
    for(int in_cnt = 0; in_cnt < 8; in_cnt++)
    {
        cin >> _inputs[in_cnt];        
    }
    
    for(int n_cnt = 0; n_cnt < 8; n_cnt++)
    {
        if(_inputs[n_cnt] == n_cnt+1)
            _ret = ascending;
        else if((8-_inputs[n_cnt]) == n_cnt)
            _ret = descending;
        else
            _ret = mixed;

        if((_ret == mixed) || (n_cnt != 0 && _ret != _prev_ret))
        {
            _ret = mixed;
            break;
        }
        else
            _prev_ret = _ret;
    }
    cout << _str_ret[_ret];
    return 0;
}