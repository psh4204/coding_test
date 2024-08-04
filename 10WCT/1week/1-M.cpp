/*
https://www.acmicpc.net/problem/3986
좋은 단어: 팬린드롬, 쌍찾기

좋은단어 예시
ABAB
AABB

Input
- 단어개수 N
- 단어 ...

Output
- 좋은단어

Try1
- 좋은단어의 조건을 걸어보자.
    - 길이가 짝수인지 부터 체크
    - 팬린드롬 체크부터 하자 (앞뒤 짤라서 체크). 맞으면 정답카운트
    - 아니라면 무조건 짝을 맞췃다는 말인데, 
        - A와 B를 각 string별로 카운트를 센다
        - 새로운 알파벳이나올때 카운트 리셋. 만약 홀수번째에서 리셋되면 return.
        - 마지막까지 루프 다돌면 정답카운트
==> TC3에서 막힘. 뭐지?

Try2
- 지금보니까 괄호문제네
- A, B들 각 스택으로 쌓되, 같은 알파벳이 나오면 삭제.
- 마지막에 값이 남으면 예쁜글자 아님
*/
#include <bits/stdc++.h>
using namespace std;
int _N, _pretty_cnt = 0;

int check_pretty_words(string input)
{
    stack<char> ch_stack;
    for(int ch_cnt = 0; ch_cnt < input.length(); ch_cnt++)
    {
        if(ch_stack.empty())
        {
            ch_stack.push(input[ch_cnt]);
        }
        else if(input[ch_cnt] != ch_stack.top())
        {
            ch_stack.push(input[ch_cnt]);
        }
        else if(input[ch_cnt] == ch_stack.top())
        {
            ch_stack.pop();
        }
    }

    if(ch_stack.empty())
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    cin >> _N;
    for(int input_cnt = 0; input_cnt < _N; input_cnt++)
    {
        string input;
        cin >> input;
        _pretty_cnt += check_pretty_words(input);
    }
    cout << _pretty_cnt;
    return 0;
}