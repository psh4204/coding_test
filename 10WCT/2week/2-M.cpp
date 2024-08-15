/* https://www.acmicpc.net/problem/1436
영화감독 숌

영화 666의 N번째 영화이름을 만들자. 시리즈는 항상 차례로 만들어진다.
종말의 숫자를 만들어야한다: 666 .. 6이 적어도 3번이상 반복되는 숫자가 들어가야 된다.
- 1 -> 666 / 2 -> 1666 / 3 -> 2666/ 6 -> 5666 / 187 -> 186666 / 500 -> 1666699

Try1.
- 한자리수 는 이해가 가는데, 3자리수에서 187이 왜 66이 될까.
- 예시랑 규칙이 너무 난해한데
- 666이 들어간 수 중에서 가장 작은 값부터 보여달라는 거로 보이네
- 왼쪽의 어느부분이 6이되는 순간에 오른쪽 끝이 0으로 채워지고 1씩 카운트되듯 하면 될듯?
*/
#include <bits/stdc++.h>
using namespace std;
int _N = 0; // 1~10,000
string _head, _body, _str_ret;
bool _is_using_tail = false;

void make_head()
{
    if(_body.length() == 3) // body == "666"
    {
        if(_head.empty())
        {
            _head = "0";
        }
        else
        {
            int h_num = stoi(_head);
            h_num ++;
            _head = to_string(h_num);
        }
    }
}

void make_body()
{
    if(!_head.empty() && _head.back() == '6')
    {
        // if head has '6' -> head의 6을 없앤 후 tail 만들기.
        for(int idx = _head.length()-1; idx >= 0; idx--)
        {
            if(_head[idx] == '6')
            {
                _head.pop_back();
                _body.push_back('0');
            }
            else
            {
                break;
            }
        }
        _is_using_tail = true;
    }
    else if(_is_using_tail)
    {
        // tail +1
        string pre_body = _body;
        int b_num = stoi(_body);
        b_num++;
        _body = to_string(b_num);
        if(_body[2] != '6') // tail 을 다 썼다면, head 복구, tail reset.
        {
            _body = pre_body;
            for(int h_idx = 0; h_idx < pre_body.length()-3; h_idx++)
            {
                _body.pop_back();
                _head.push_back('6');
            }
            make_head();
            _is_using_tail = false;
        }
    }
}

int main()
{
    _body = "666";
    cin >> _N;
    for(int n = 0; n < _N; n++)
    {
        make_head();
        make_body();
    }
    _str_ret = _head + _body;
    cout << stoi(_str_ret) << '\n';
    return 0;
}