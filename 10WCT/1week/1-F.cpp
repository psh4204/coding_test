/*
https://www.acmicpc.net/problem/11655
ROT13

숫자를 제외한 영어 문자를 ROT13(현재문자에서 ++13)해서 출력

ROT: 해당영문에서 ++13.

input: 숫자,대문자,소문자,공백으로만 이루어진 문장
output: ROT13이 적용된 문장

풀이1
- input 받은 후 string 저장
- string 에서 'a'~'z', 'A'~'Z' 값에 대해 ROT13함수 진행
- ROT13()
    - ((input값 - 'a' 혹은 'A') %26) + 'a'혹은'A'
*/
#include <bits/stdc++.h>
using namespace std;

void ROT13(char& ch, char input_a)
{
    int cnvt_ch = ch-'\0';
    int cnvt_input_a = input_a-'\0';
    ch = ((cnvt_ch - cnvt_input_a + 13)%26 + cnvt_input_a) + '\0';
}

int main()
{
    string input;
    getline(cin, input);
    for(auto& ch: input)
    {
        if(ch >= 'a' && ch <= 'z')
            ROT13(ch, 'a');
        else if(ch >= 'A' && ch <= 'Z')
            ROT13(ch, 'A');
    }
    cout << input;
    return 0;
}