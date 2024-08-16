/* https://www.acmicpc.net/problem/9012
괄호

문자 '(' ')'로 된 문자열을 받은 후
올바른 괄호문인지 아닌지 체크한다.

Input
- 괄호 덩어리

Output
- YES or NO

Try1.
- 괄호 = 스택
- 스택으로 알맞는 괄호를 체크하자.
*/
#include <bits/stdc++.h>
using namespace std;
int _N = 0;

bool check_VPS(string str)
{
    stack<char> stk;
    for(auto ch: str)
    {
        if(!stk.empty() && ch == ')' && stk.top() == '(')
            stk.pop();
        else
            stk.push(ch);
    }
    if(stk.empty())
        return true;
    else
        return false;
}

int main()
{
    cin >> _N;
    for(int in_idx = 0; in_idx < _N; in_idx++)
    {
        string usr_input;
        cin >> usr_input;
        if(check_VPS(usr_input))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}