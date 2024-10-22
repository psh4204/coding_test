/* https://www.acmicpc.net/problem/1874
스택 수열

임의의 수열을 스택을 통해 만들수 있는지 없는지 체크해라.
숫자는 오름차순으로 준비되며, 스택을 통해 임의의 수열 만들기를 해봐라.

입력
- n (수열길이 1~100,000)
- 숫자 (n줄)

출력
- 가능: +,- n줄
- 불가능: NO

풀이
- 실제 사용되는 자료형
    - 1,2,3,4 ... 오름차순 수열 혹은 for 카운트
    - stack
    - ans 임의수열
- 1,2,3... 숫자와 stack을 통해 해당 수열(ans)가 나오는지 체크
- 현재 숫자 < 임의수열: push (+) ... 마지막 '==' 처리
- 현재 숫자 == 임의수열: push and pop (+, -) 
- 현재 숫자 > 임의수열: pop (-)
- 매 pop하기전 stack의 top과 ans값을 비교. 만약 다르면 NO.exit(0)

// TODO: 복습
*/
#include <bits/stdc++.h>
using namespace std;
int _n;
stack<int> _stack;
vector<int> _randnums;
vector<char> _trace;

inline void push_num(int& num)
{
    _stack.push(num);
    _trace.push_back('+');
    num++;
}

inline void pop_num(int rand_num)
{
    if(_stack.top() != rand_num)
    {
        cout << "NO\n";
        exit(0);
    }
    _stack.pop();
    _trace.push_back('-');
}

int main()
{
    int num = 1;
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> _n;
    for(int in_idx = 0; in_idx < _n; in_idx++)
    {
        int in;
        cin >> in;
        _randnums.push_back(in);
    }

    for(int loop_idx = 0; loop_idx < _n; loop_idx++)
    {
        if(_randnums[loop_idx] >= num)
        {
            while(_randnums[loop_idx] >= num)
                push_num(num);
            pop_num(_randnums[loop_idx]);
        }
        else if(_randnums[loop_idx] < num)
        {
            pop_num(_randnums[loop_idx]);
        }
    }
    for(auto ch: _trace)
        cout << ch << "\n";
    return 0;
}