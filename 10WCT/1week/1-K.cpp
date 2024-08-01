/*
https://www.acmicpc.net/problem/1213
팬린드롬 만들기

알파벳 대문자의 영어를 받으면 그것의 순서를 적절히 섞어서 팬림드롬으로 만들어 줘야함

예시 (오름차순으로 만들어야함)
- AABB -> ABBA
- AAABB -> ABABA
- ABACABA -> AABCBAA
- ABCD -> I'm Sorry Hansoo

Try1
- 영어대문자 문장을 받으면 map에 차곡차곡 쌓으며 카운팅한다.
- 팬린드롬 체크
    - Output 규칙을 보아하니, 모든 알파벳이 짝수개 거나, 단한개만 홀수개여야만 함.
    - 안되면 그냥 미안 한수 띄워준다.
- 문장 만들기
    - 앞문장을 만들면 뒷문장은 reverse써서 만들면됨.
    - map에 있던 알파벳을 반씩만 앞에 차곡히 쌓는다.
    - 홀수개만 마지막에 반으로 나눠 쌓는다.
    - 만약 홀수개가 있었다면, 홀수번째 친구를 하나 중간값으로 넣어준다.
    - 앞문장을 리버스해서 그대로 뒷문장만들어 넣으면 끝.
==> 틀렸습니다.

Try2
- 왤까. 왜틀렸지?
- 리턴값에서 와.. 중간에 Null 문자때문에 string 안보이게 하나 더 있었음.
    - 이게 _odd_char의 빈값이 들어가서 그런거였음. 익셉션 처리하니까 잘됨.
    - 길이체크 꼭 하고 이상한거 없는지 꼭 보고 제출하자. 
*/
#include <bits/stdc++.h>
using namespace std;
map<char, int> _alphabets;
int _odd_count = 0;
char _odd_char;

int main()
{
    // Init and Receive.
    string user_input;
    cin >> user_input;
    for(auto ch: user_input)
    {
        if(ch >='A' && ch <= 'Z')
            _alphabets[ch] += 1;
        else
        {
            cout << "I'm Sorry Hansoo\n";
            exit(0);
        }
    }
    for(auto alpha: _alphabets)
    {
        if(alpha.second % 2 == 1)
        {
            _odd_char = alpha.first;
            _odd_count++;
        }
    }
    if((_odd_count > 1)) // 홀수알파벳이 2개이상일때 Fail 
    {
        cout << "I'm Sorry Hansoo\n";
        exit(0);
    }
    string first_words, second_words;
    // Make Output
    for(auto alpha: _alphabets)
    {
        if((alpha.first == _odd_char) && (alpha.second > 1)
        ||((alpha.first != _odd_char)) )
        {
            for(int loop_cnt = 0; loop_cnt < alpha.second/2; loop_cnt++)
                first_words+=alpha.first;
        }
    }
    second_words = first_words;
    string ret;
    reverse(second_words.begin(), second_words.end());
    if(_odd_count == 0)
    {
        ret = first_words + second_words;
    }
    else
    {
        ret = first_words + _odd_char + second_words;
    }
    cout << ret;
    return 0;
}