/*
https://www.acmicpc.net/problem/10988

팰린드롬 확인하기
- 거꾸로 읽어도 단어가되는 단어 확인하라

input
- 1 line의 단어가 주어지며, 소문자 알파벳으로 되어있음. (사이즈 100)

output
- 팬린드롬이면 1, 아니면 0

1차 풀이
- 인풋 받아옴
- 길이가 홀수면 중간값 삭제
- string에서 앞과 뒤만 체크하는 루프 시작
*/

#include <bits/stdc++.h>
using namespace std;


int main()
{
    string str_input, front_copy, back_copy;
    int div_front_idx, div_end_idx = 0;
    cin >> str_input;
    if(str_input.length() == 1)
    {
        cout << 1;
        exit(0);
    }
    else if(str_input.length() %2 == 0) // input이 짝수길이인가?
    {
        div_front_idx = str_input.length()/2;
        div_end_idx = div_front_idx;
    }
    else
    {
        div_front_idx = str_input.length()/2;
        div_end_idx = div_front_idx +1;
    }
    front_copy = str_input.substr(0, div_front_idx);
    back_copy = str_input.substr(div_end_idx, str_input.length());

    for(int loop_idx = 0; loop_idx < front_copy.length(); loop_idx++)
    {
        if(front_copy[loop_idx] != back_copy[front_copy.length() -1 -loop_idx])
        {
            cout<< 0;
            exit(0);
        }
    }
    cout<< 1 ;
    return 0;
}