/* https://www.acmicpc.net/problem/4949
균형잡힌 세상

문자열 내에 소괄호와 대괄호의 균형이 맞춰져있는지 체크해본다.
마지막 문자열에는 .이 온다.

Input
- .이 올때까지 문자열을 받는다.

Ouput
- yes or no

Try1.
- stack을 쓰자.
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    while(1)
    {
        string usr_input;
        stack<char> stk;
        getline(cin, usr_input);
        if(usr_input[0] == '.')
            break;
        for(int idx = 0; idx < usr_input.length()-1; idx++) // 마지막 문자열을 제외하고 괄호체크
        {
            char ch = usr_input[idx];
            if(ch == '(' || ch == '[')
            {
                stk.push(ch);
            }
            else if(!stk.empty())
            {
                if(ch == ')')
                {
                    if(stk.top() == '(')
                        stk.pop();
                    else
                        stk.push(ch);
                }
                else if(ch == ']')
                {
                    if(stk.top() == '[')
                        stk.pop();
                    else
                        stk.push(ch);
                }
            }
            else if(ch == ')' || ch == ']')
            {
                stk.push(ch);
            }
        }
        if(stk.empty())
            cout << "yes\n";
        else
            cout << "no\n";
    }
    return 0;
}