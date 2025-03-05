/* https://www.acmicpc.net/problem/1546
평균

점수/최고점M *100 을 구하라.

[입력]
N (0~1000)
점수들

[출력]
평균점수. 상대오차가 -2이하이면 정답 (?)

[풀이]
상대오차 10^-2..라는말이 흠..
일단 풀어보자.
- 부동소수점연산은 어딜가든 부정확함.(컴퓨터한계)
- 나눗셈 연산을 최소화 하는 방향으로 가자.
- print는 굳이 저런식으로 안해도 되는건가? (꼭 소수 둘째점 자리까지 안가도 된다했으니까.)

*/
#include <bits/stdc++.h>
using namespace std;
vector<double> g_scores;
int g_N, g_max;
double g_sum;

int main()
{
    cin >> g_N;
    g_scores.resize(g_N,0);
    for(int inCnt = 0; inCnt < g_N; inCnt++)
    {
        cin >> g_scores[inCnt];
        g_max = max(g_max, (int)g_scores[inCnt]);
    }
    for(int inCnt = 0; inCnt < g_N; inCnt++)
    {
        g_sum += g_scores[inCnt];
    }
    
    cout << g_sum/(g_N*g_max)*100;
    
    return 0;
}