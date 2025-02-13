/*https://www.acmicpc.net/problem/1259
팰린드롬수

앞뒤가 똑같은 모든 문자 = 팰린드롬

1이상 99999 이 하 정수 중에 팰린드롬이면 yes, 아니면 no를 출력해보자.
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    while(true)
    {
        stack<char> stk;
        string input;
        int inputHalfSize;
        cin >> input;
        if(input[0] == '0')
            break;
        if(input.length() == 1)
        {
            cout << "yes\n";
            continue;
        }
        inputHalfSize = input.length()/2;
        
        // 스택에 앞 절반 쌓기
        for(int frontIdx = 0; frontIdx < inputHalfSize; frontIdx++)
            stk.push(input[frontIdx]);

        // 문자열 개수가 홀수면 뒤에사용할 인덱스시작값 +1
        if(input.length()%2 == 1)
            inputHalfSize++;

        // 스택 Pop.
        for(int behindIdx = inputHalfSize; behindIdx < input.length(); behindIdx++)
        {
            // cout << "<< "<< stk.top() << ": " << input[behindIdx] << "\n";  
            if(stk.top() == input[behindIdx])
                stk.pop();
            else
                break;
        }

        if(stk.empty() == true)
            cout << "yes\n";
        else
            cout << "no\n";
    }
    return 0;
}