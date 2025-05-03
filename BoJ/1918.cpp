/*  후위 표기식
https://www.acmicpc.net/problem/1918

후위표기식은 스택

중위표기식을 받았을때, 후위표기식으로 수정하는 프로그램을 작성하라

입력
- 중위표기식 (알파벳 대문자, +,-,*,/,(,) 이렇게 나옴. 길이는 100을 안넘김)

출력
- 후위표기식으로 바꾼 식을 출력하라

풀이
- 스택으로 했어야했던거같음
- A * (B + C)
    - A B C
    - * ( + )
- A+B*C-D/E
    - A B C * + D E / -

규칙
1. 사칙연산 우선순위 (+=-) < (*=/)
2. 숫자는 Print 바로한다
3. 스택에는 연산자만 넣는데,
    push: top의 우선순위가 현재 연산자보다 낮을경우에만 push
    pop: top의 우선순위가 현재 연산자보다 높거나 같을때만 pop
4. 괄호관련
    push: 여는 괄호는 그냥 push
    pop: 닫는 괄호가 나오면, 여는괄호가 나올때까지 pop 후 여는괄호도 삭제
*/
#include <bits/stdc++.h>
using namespace std;
char g_input;
stack<char> g_stack;

int main()
{
    while((cin >> g_input) && (g_input != EOF))
    {
        switch(g_input)
        {
            case '(':
                g_stack.push(g_input);
            break;
            case ')':
            {
                while(g_stack.top() != '(')
                {
                    cout << g_stack.top();
                    g_stack.pop();
                }
                g_stack.pop();
            }
            break;
            case '+':
            {
                while(!g_stack.empty() && g_stack.top() != '(')
                {
                    cout << g_stack.top();
                    g_stack.pop();
                }
                g_stack.push(g_input);
            }
            break;
            case '-':
            {
                while(!g_stack.empty() && g_stack.top() != '(')
                {
                    cout << g_stack.top();
                    g_stack.pop();
                }
                g_stack.push(g_input);
            }
            break;
            case '*':
            {
                while(!g_stack.empty() && g_stack.top() != '(' 
                        && (g_stack.top() == '/' || g_stack.top() == '*'))
                {
                    cout << g_stack.top();
                    g_stack.pop();
                }
                g_stack.push(g_input);
            }
            break;
            case '/':
            {
                while(!g_stack.empty() && g_stack.top() != '(' 
                        && (g_stack.top() == '/' || g_stack.top() == '*'))
                {
                    cout << g_stack.top();
                    g_stack.pop();
                }
                g_stack.push(g_input);
            }
            break;
            default:
                cout << g_input;
            break;
        }
    }
    while(!g_stack.empty())
    {
        cout << g_stack.top();
        g_stack.pop();
    }
    return 0;
}