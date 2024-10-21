/* https://www.acmicpc.net/problem/10828
스택

정수저장 스택을 구현한 후 입력되는 명령을 처리하는 프로그램 작성하기
명령 총 5가지
- push X: 정수 X를 스택에 넣는 연산
- pop: 스택의 가장위정수를 없앤 후 출력. 정수가없으면 -1.
- size: 스택의 사이즈 출력
- empty: 스택이 비어있으면 1, 아니면 0 출력
- top: 스택의 가장위의 정수 출력. 없으면 -1.

입력
- N (1~10000)
- 명령어리스트

출력
- 명령어 받은 후 처리 및 출력

풀이
- 명령어는 if로 만든 state머신으로 짜자
- 스택에 그대로 처리하고, 시키는대로 출력하자
*/
#include <bits/stdc++.h>
using namespace std;
int _N;
stack<int> _stack;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> _N;
    for(int n_idx = 0; n_idx < _N; n_idx++)
    {
        string op;
        cin >> op;
        if(op == "push")
        {
            int num;
            cin >> num;
            _stack.push(num);
        }
        else if(op == "pop")
        {
            if(_stack.empty())
                cout << -1 << "\n";
            else
            {
                cout << _stack.top() << "\n";
                _stack.pop();
            }
        }
        else if(op == "size")
        {
            cout << _stack.size() << "\n";
        }
        else if(op == "empty")
        {
            cout << _stack.empty() << "\n";
        }
        else if(op == "top")
        {
            if(_stack.empty())
                cout << -1 << "\n";
            else 
                cout << _stack.top() << "\n";
        }
    }
    return 0;
}