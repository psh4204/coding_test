/* https://www.acmicpc.net/problem/1874
스택수열

1부터 n까지 수를 스택에 넣었다 뽑아서 하나의 수열을 만들수있다.
스택을 이용해 수열을 만들 수 있는지, 어떤식으로 트레이스 해야하는지 체크하는 프로그램 작성

입력
- n (1~100000, 중복없음)
- 임의의 수열

출력
- 만들어야 할 임의의 수열

도전1

안하고 걍 다 던지고 싶다.
이거도 감도 안잡히고 저거도 감안잡히고
코테 2주 못했다고 다 까먹으면 진짜 씨발 하.
*/
#include <bits/stdc++.h>
using namespace std;
int _N;
vector<int> _numlist;   // 임의수열
stack<int> _stack;
stack<int> _ret_stack;
vector<char> _trace;

int main()
{
    cin >> _N;
    _numlist.resize(_N);
    for(int in_idx = 0; in_idx < _N; in_idx++)
    {
        cin >> _numlist[in_idx];
    }

    int num = 1;
    for(int n_idx = 0; n_idx < _N; n_idx++)
    {
        if(_numlist[n_idx] > num)
        {
            for(num; num <= _numlist[n_idx]; num++)
            {
                _stack.push(num);
                _trace.push_back('+');
            }
            while(_stack.size() && _stack.top() == _numlist[n_idx])
            {
                _ret_stack.push(_stack.top());
                _stack.pop();
                _trace.push_back('-');
                n_idx++;
            }
            n_idx--;
        }
        else if(_numlist[n_idx] == num)
        {
            // 스택안써도 값에 쓰임.
            _ret_stack.push(num);
            num++;
        }
        else
        {
            if(!(_stack.size() && _stack.top() == _numlist[n_idx]))
            {
                cout << "NO";
                exit(0);
            }
        }
    }
    
    for(auto ch : _trace)
        cout << ch << "\n";
    
    return 0;
}