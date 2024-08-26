/* https://www.acmicpc.net/problem/16637
괄호 추가하기

길이가 N인 수식. 사칙연산의 우선순위는 모두 동일. (숫자는 0~9)
괄호가 추가되면 그거만 우선순위가 올라감. 한괄호에는 수식하나만 존재하고 중첩괄호 X.
수식이 정해졌을때 괄호를 추가해서 최대값을 구하는 프그램 작성하기.
괄호를 추가하지않아도 됨.

Input
- N (1~19) 
- 수식. // 식이 틀리는 경우는 절-대 없음.(무조건 홀수개의 N개를 받음)

Output:
- 최대값출력. 일반 int형 값이다.

Try1.
- 꼭 굳이 괄호를 안넣어도 될거같고.. DFS로 풀면 될거같음.
- 계산은 stack으로 처리하면 됨.
- 부호만 인덱스를 배열에 넣어두자.
    - 이 인덱스의 앞,뒤값을 스택에 넣어서 계산하는 형식으로 쭉 풀어보자.
    - 스택에 넣을대 visited배열을 넣어서 값이 이상하게 들어가는걸 막자.

Try2.
- 순열써서 풀었는데, 이걸로 하면 중첩괄호가 되어버림..
    - 괄호친구들을 계산한 후에는 왼쪽에서 부터 차례로 계산되야함
    - 단순 순열로는 하면안되겠네 또
- 또 조합으로 풀어야하네..
    - 조합으로 하나하나 괄호친 후에 왼쪽에서부터 계산. 이런식으로 ㅇㅇ.
- TODO:
- 
*/
#include <bits/stdc++.h>
using namespace std;
int _N, _max = 0;
vector<char>    _math;    // 유저의 수식
vector<int>     _opers;    // 연산인덱스 배열

int calc();

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string input;
    cin >> _N >> input;
    for(int in = 0; in <_N; in++)
    {
        _math.push_back(input[in]);
        if(_math[in] < '0' || _math[in] >'9')
            _opers.push_back(in);
    }

    do
    {
        int num = calc();
        if(num > _max || _max == 0)  _max = num;
    } while (next_permutation(_opers.begin(), _opers.end()));
    cout << _max;

    return 0;
}

int calc()
{
    vector<int> v(_N);
    stack<int> c_stack;
    for(auto oper_idx: _opers)
    {
        int l_idx = oper_idx -1;
        int r_idx = oper_idx +1;
        if(l_idx >= 0 && v[l_idx] == 0)
        {
            c_stack.push((_math[l_idx])-'0');
            v[l_idx] = 1;
        }
        if(r_idx < _N && v[r_idx] == 0)
        {
            c_stack.push((_math[r_idx])-'0');
            v[r_idx] = 1;
        }
        // operation
        int pre_top = c_stack.top(); c_stack.pop();
        switch(_math[oper_idx])
        {
            case '+':
            c_stack.top() += pre_top;
            break;
            
            case '-':
            c_stack.top() -= pre_top;
            break;
            
            case '*':
            c_stack.top() *= pre_top;
            break;
        }
        v[oper_idx] = 1;
    }
    return c_stack.top();
}