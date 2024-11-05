/* 문자열 폭발
https://www.acmicpc.net/problem/9935

폭발문자열 포함시 폭발문자열 삭제 후 나머지는 이어붙여짐.
새로 생긴 문자열에 폭발문자열이 포함되어 있음.
폭발은 폭발 문자열이 없어질때까지 이어짐.
문자열은 영어 소문자-대문자-0~9.

폭발 후 아무것도 없으면 'FRULA' 출력.

입력
- 문자열 1~1,000,000
- 폭발문자열 1~36길이

출력
- 모든 폭발 후 남은 문자열 출력

풀이
- 폭발 = 스택
    - 스택에 문자를 계속 넣은 후, 
- 제한시간 2초(넉넉)

(주의!) stack의 크기로 loop를 돌릴땐, 지역변수로 stack size 따로 빼놔야함
- pop() 하면 실제 size가 줄기때문에, 실제로 원하던 동작을 하지 않음.

(반례)
mirkovC4mnizCC44mm
C4m

1mku2mku3mku4mku5mku
mku

1aabbcc2
acb

AABCBABCBABCCABCC
ABC
*/
#include<bits/stdc++.h>
using namespace std;
string _FRULA = "FRULA";
string _input,_boom;
stack<char> _stk;

int main()
{
    cin >> _input >> _boom;
    for(int in_cnt = 0; in_cnt < _input.length(); in_cnt++)
    {
        _stk.push(_input[in_cnt]);
        if(_stk.top() == _boom[_boom.size()-1] && _stk.size() >= _boom.size())
        {
            stack<char> sub_stk;
            bool is_correct = true;
            for(int b_cnt = 0; b_cnt < _boom.size(); b_cnt++)
            {
                // // - TEST -
                // cout << _stk.top() << " " << _boom[_boom.size()-1-b_cnt] << "\n";
                // // - ---- -
                
                sub_stk.push(_stk.top());
                _stk.pop();
                if(sub_stk.top() != _boom[_boom.size()-1-b_cnt])
                {
                    is_correct = false;
                    break;
                }
            }
            if(is_correct) continue;
            int sub_stk_size = sub_stk.size();
            for(int subs_cnt = 0; subs_cnt < sub_stk_size; subs_cnt++)
            {
                // // TEST
                // cout << _stk.top() << " " << sub_stk.top() << "(RC)\n";
                // // ---
                _stk.push(sub_stk.top());
                sub_stk.pop();
            }
        }
    }
    int stk_size = _stk.size();
    if(stk_size > 0)
    {
        _input.clear();
        
        for(int s_cnt = 0; s_cnt < stk_size; s_cnt++)
        {
            // // TEST
            // cout << _stk.top() << " " << s_cnt << "\n";
            // // ---
            _input.push_back(_stk.top());
            _stk.pop();
        }
        reverse(_input.begin(), _input.end());
        cout << _input;
    }
    else
        cout << _FRULA;
    return 0;
}