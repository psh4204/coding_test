/*https://www.acmicpc.net/problem/2870
수학숙제

N개의 소문자글자, 숫자를 전부찾은 후 비내림차순으로 정리(오름차순).
숫자 앞에 0이 있다면 0생략가능.

Input
- 줄의개수_N
- 문자열 (~100글자.소문자+숫자조합)

Output
- 찾은숫자수만큼 M줄로 오름차순으로 각 숫자하나씩 출력.

Try1
- 문자를 받은 후 각 문자가 숫자인지 처리해야하는 로직 필요
    - `0` ~ `9` 체크. 그후 연속되는지 체크. 
        - 연속이 안된다면 그 값을 stoi(data+`\0`)처리
Try2
- out of range 처리 해야함 (글자 100글자인데.)

*/
#include <bits/stdc++.h>
using namespace std;
int _N = 0;
vector<string> _ret;
string _str_num;
int _num_size = 0;
char _pre_ch = 0;

bool custom_cmp(string first, string second)
{
    if(first.length() < second.length())
    {
        return true;
    }
    else if(first.length() == second.length())
    {
        return first < second;
    }
    else if(first.length() > second.length())
    {
        return false;
    }
}

void set_num_and_clear()
{
    if(_num_size > 0)
    {
        _ret.push_back(_str_num);
    }
    _str_num.clear();
    _pre_ch = 0;
    _num_size = 0;
}

int main()
{
    cin >> _N;
    for(int usr_idx = 0; usr_idx < _N; usr_idx++)
    {
        string usr_input;
        cin >> usr_input;
        for(auto ch: usr_input)
        {
            // 숫자일경우
            if(ch >= '0' && ch <= '9')
            {
                if(_str_num == "0")
                {
                    _str_num = ch;
                    continue;
                }
                _str_num += ch;
                _num_size++;
            }
            // 문자일경우
            else
            {
                set_num_and_clear(); // str_num 있으면 숫자화
            }
            _pre_ch = ch;
        }
        set_num_and_clear(); // 마지막 str_num도 처리.
    }
    sort(_ret.begin(), _ret.end(), custom_cmp);
    for(auto n: _ret)
        cout << n << '\n';
    return 0;
}