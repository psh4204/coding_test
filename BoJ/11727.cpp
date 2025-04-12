/* 2xn 타일링2
https://www.acmicpc.net/problem/11727
2xN 크기의 직사각형안에 1x2, 2x1, 2x2 타일을 채우는 방법의 수를 구하시오
(1~N~1,000)

입력
- N
출력
- 방법의 수를 10,007 모듈러 값 출력

풀이
- 타일 문제 규칙
    - N이 1, 2인 경우를 제외하고, 결국 이전의 타일조합개수를 그대로 사용할 수 밖에 없는 구조임
- 이번 타일문제의 규칙은
    - 3번타일 부터 ~N까지 (i-1 조합 + (i-2조합 x2)) 임
*/
#include <bits/stdc++.h>
using namespace std;
#define MODUL 10007
int g_cnt;
int g_N;
vector<int> g_nums(1001);

int main()
{
    cin >> g_N;
    g_nums[1] = 1; g_nums[2] = 3;
    for(int nIdx = 3; nIdx <= g_N; nIdx++)
    {
        g_nums[nIdx] = g_nums[nIdx-1] + g_nums[nIdx-2] + g_nums[nIdx-2];
        g_nums[nIdx] %= MODUL;
    }
    cout << g_nums[g_N];
    return 0;
}