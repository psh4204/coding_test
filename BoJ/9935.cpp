/*https://www.acmicpc.net/problem/9935
문자열 폭발

상근이녀석이 폭발 문자열을 중간중간 심어뒀고,
문자열이 폭발하면 다른문자열이 사라지고 합쳐진다.

- 폭발문자열을 포함한경우 폭발 후 나머지 합체
- 새로생긴 문자열도 폭발 가능
- 폭발문자열이 없어질때 까지 계속된다

폭발후에 어떤문자열이 남는지 보자
비었으면 "FRULA" 를 출력

입력
- 문자열
- 폭발 문자열

출력
- 폭발 후 문자열

풀이
- 이런거는 스택으로 풀어야함
- 문자열 하나씩 받아오며, 펑 펑 펑
- 스택 몇개 사용해야하네
    - 문자열스택에 문자 하나씩 받아온다
    - 폭발문자끝글자와 같으면 확인스택으로 서로 동일한지 체크
    - 동일하면 삭제 후 다시 문자열스택에 쌓기운동
*/
#include <bits/stdc++.h>
using namespace std;
stack<char> g_inStack;
string g_input, g_bomb, g_answer;
string g_empty = "FRULA";

int main()
{
    cin >> g_input >> g_bomb;
    for(auto ch: g_input)
    {
        g_inStack.push(ch);
        
        if(ch== g_bomb[g_bomb.size()-1])
        {
            // 폭탄 확인 시퀀스
            stack<char> chStack;
            bool isBomb = true;
            for(int bIdx = g_bomb.size()-1; bIdx >= 0; bIdx--)
            {
                if(g_inStack.empty() || g_inStack.top() != g_bomb[bIdx])
                {
                    isBomb = false;
                    break;
                }
                chStack.push(g_bomb[bIdx]);
                g_inStack.pop();
                continue;
            }
            // 폭탄 없으면 다시 복구
            if(isBomb == false)
            {
                while(!chStack.empty())
                {
                    g_inStack.push(chStack.top());
                    chStack.pop();
                }
            }
        }
    }
    if(g_inStack.empty())
    {
        cout << g_empty;
        return 0;
    }
    
    while(!g_inStack.empty())
    {
        g_answer += g_inStack.top();
        g_inStack.pop();
    }
    reverse(g_answer.begin(), g_answer.end());
    cout <<g_answer;

    return 0;
}