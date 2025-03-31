/*FizzBuzz
https://www.acmicpc.net/problem/28702

FizzBuzz문제는 다음의 규칙을 따름
- i가 3의배수 and 5의배수면 "FizzBuzz"
- i가 3의배수 and !5의배수 "Fizz"
- i가 !3의배수 and 5의배수 "Buzz"
- i가 둘다아니면 i 그대로 출력

연속된 문자열 3개를 받았을때 이다음 문자열은 머가나올까

풀이
- 3개문자열줄 하나는 반드시 숫자일것
- 문자열 나오는 순간에 카운트를 센 후, 카운트를 더해보자
- 그거아니면 문제성립이 안됨
*/
#include <bits/stdc++.h>
using namespace std;
int g_num = -1, g_count = 1, g_three = 3, g_answer;
string g_input;

int main()
{
    while(g_three--)
    {
        cin >> g_input;
        if(g_input == "Fizz")
        {
            if(g_num != -1)
                g_count++;  
        }
        else if(g_input == "Buzz")
        {
            if(g_num != -1)
                g_count++;  
        }
        else if(g_input == "FizzBuzz")
        {
            if(g_num != -1)
                g_count++;  
        }
        else if(g_num != -1)
            g_count++;
        else
        {
            g_num = stoi(g_input);
        }
    }
    g_answer = g_num + g_count;
    if(g_answer % 3 == 0 && g_answer % 5 == 0)
        cout << "FizzBuzz";
    else if(g_answer % 3 == 0)
        cout << "Fizz";
    else if(g_answer % 5 == 0)
        cout << "Buzz";
    else
        cout << g_answer;
    return 0;
}