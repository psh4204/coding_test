/*
https://www.acmicpc.net/problem/10988

팰린드롬 확인하기
- 거꾸로 읽어도 단어가되는 단어 확인하라

input
- 1 line의 단어가 주어지며, 소문자 알파벳으로 되어있음. (사이즈 100)

output
- 팬린드롬이면 1, 아니면 0

1차 풀이: 맞춤
- 인풋 받아옴
- 길이가 홀수면 중간값 삭제
- string에서 앞과 뒤만 체크하는 루프 시작

2차 풀이
- reverse라는 함수가 있음. 
- sort는 정렬이지만- reverse는 단순히 뒤집기함수임.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str_input, copy;
    cin >> str_input;
    copy = str_input;
    reverse(copy.begin(), copy.end());
    if(str_input == copy)
        cout<< 1 ;
    else
        cout<< 0;
    
    return 0;
}