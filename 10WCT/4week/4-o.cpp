/* https://www.acmicpc.net/problem/15926
괄호왕

올바른 괄호
- ()
- (x)(y)
- xy

받은 문자열에서 연속하는 올바른괄호구간을 길게 자를거임.

Input
- 문자열 길이 (1~200,000)
- 괄호로 된 문자열

Output
- 가장 길게 연속하는 올바른 괄호구간
- 찾을 수 없으면 0 출력.

Hint: max값은 마지막에 체크하고, stack 외에 배열로 따로 1과 0으로 체크.
- ..?

[깨우치다!!]
- 스택에 괄호 '('를 담아서 히스토리를 남기고, ')' 가 들어오면 stack top의 히스토리 인덱스를 비트에 1로 남기는 기법.
10
(()()(()))
s0123456789A
l1111111111
ans: 10

12
(()(()()(()(
ans:4
s0123456789ABC
l011011110110
*/
#include <bits/stdc++.h>
using namespace std;
int _max, _N;
vector<int> _bits(200001); // 연속 괄호 체크용 리스트
stack<int> _open_gwals; // '('의 위치만 넣는 스택

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> _N;
    for(int in_cnt = 0; in_cnt < _N; in_cnt++)
    {
        char input;
        cin >> input;
        if(input == '(')
            _open_gwals.push(in_cnt);
        else
        {
            if(!_open_gwals.empty())
            {
                _bits[in_cnt] = 1;
                _bits[_open_gwals.top()] = 1;
                _open_gwals.pop();
            }
        }
    }
    int cnt = 0;
    for(auto b: _bits)
    {
        if(b == 1)
        {
            cnt++;
            _max = max(cnt, _max);
        }
        else
            cnt = 0;
    }
    cout << _max;
    return 0;
}