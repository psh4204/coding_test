/* https://www.acmicpc.net/problem/1676
팩토리얼 0의 개수

N!에서 뒤에서부터 처음 0이아닌 숫자가 나올때까지 0의 개수를 구하는 프로그램 작성 
- N은 0 ~ 500 이다

예시)
10 -> 2
- 10 9 8 7 6 5 4 3 2 1
- 3628800
- -----00
- 2

풀이
- 매 곱셈마다 10으로 나눈 후, 나눠지면 0개수 카운트, 안나눠지면 카운트 X
    - 나눠지는지는 %연산으로 매번 비교한다
    - '42300 %10 -> 42300/10' -> '4230 % 10 -> 4230/ 10' -> 423 %10 ..
- 마지막 % 연산후 마지막 숫자만 남긴다 
    - 예시: 423 -> 3
- 위의 동작 반복
- 예외 상황
    - 25 * 4 = 100. 위에 저런식으로 막무가네로 값을 잘라쓰면 이런 값을 못찾아씀.
    - 그러므로 1000을 나누기 연산하고 나머지는 동일하게 하자 (나머지연산은 그저 계산값을 크게 키우게 하지 않는 용도니까)
    - '42300 %1000 -> 42300/10' -> '4230 % 1000 -> 4230/ 10' -> 423 %1000 ..
- (근데) 0! = 1 아닌가? 0으로 해야 맞네;; 뭐야?

*/
#include <bits/stdc++.h>
using namespace std;
int g_N, g_calcedNum, g_zeroCnt = 0;

int main()
{
    cin >> g_N;
    g_calcedNum = g_N;
    if(g_N == 0)
    {
        cout << 0;
        return 0;
    }
    while(--g_N)
    {
        // cout << "[1] " << g_calcedNum << " * " << g_N << "\n"; // TEST
        g_calcedNum *= g_N;
        while(g_calcedNum % 10 == 0)
        {
            // cout << "[2] " << g_calcedNum << "\n"; // TEST
            g_calcedNum /= 10;
            g_zeroCnt += 1;
        }
        g_calcedNum %= 1000;
        // cout << "[3] zeroCnt: " << g_zeroCnt << " --- \n" ; // TEST
    }
    cout << g_zeroCnt;
    return 0;
}