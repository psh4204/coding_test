/* Z

2^N 변이 정사각형이 있고,
각 포인트를 Z모양으로 탐색함
N, r, c가 주어지면 (r,c)가 몇번째 탐색이었는지 출력

풀이
- 0.5초안에 풀어야함
- 수학문제인거같은데 암만봐도
- 메모리 제한이 1024,000,000임
- N은 15까지인데, 32768
    - 32768 제곱은 1073,741,824
    - 메모리 후달림. 이거 그냥 수학문제다! (분할정복)


- 문제가 이해는 가는데, 규칙 정리가 안됨.. (힌트 봐버림)
    - 포인트는, 4개의 박스로 쪼갰을때, 두번째 박스의 순서부터 박스크기 만큼 + 된다는 것
    - 즉, r,c를 받으면 r,c가 나올때 까지 규칙에 맞게 박스를 쪼개야함
    - 요약: 4개짜리 이분탐색 느낌으로 가는 것
- 두가지 변수를 사용해야함
    - 사각형 넓이 총합
    - y,x

(진짜 너무 어렵다.. ㅠㅠ)
*/
#include <bits/stdc++.h>
using namespace std;
int g_Y, g_X, g_sum, g_N, g_tY, g_tX;

void ChaseTarget(int startY, int startX, int nowN, int nowSum)
{
    // cout << "startY: " << startY <<  " startX: " << startX << " nowN: " << nowN << " nowSum: " << nowSum << "\n";
    if(startY == g_tY && startX == g_tX)
    {
        g_sum = nowSum;
        return;
    }
    int side = pow(2,nowN);
    int smallSquare = side*side/4; // 4등분한 작은네모 넓이
    int halfSide = side/2;
    // Z 첫번째 영역 안에 들어가는가?
    if(startY <= g_tY && startX <=g_tX && 
        startY+halfSide > g_tY && startX+halfSide > g_tX)
    {
        ChaseTarget(startY, startX, nowN-1, nowSum);
    }
    // Z 두번째 영역 안에 들어가는가?
    else if(startY <= g_tY && startX <=g_tX+halfSide && 
        startY+halfSide > g_tY && startX+(halfSide*2) > g_tX)
    {
        ChaseTarget(startY, startX+halfSide, nowN-1, nowSum + smallSquare);
    }
    // Z 세번째 영역 안에 들어가는가?
    else if(startY <= g_tY+halfSide && startX <=g_tX && 
        startY+(halfSide*2) > g_tY && startX+halfSide > g_tX)
    {
        ChaseTarget(startY+halfSide, startX, nowN-1, nowSum + (smallSquare*2));
    }
    // Z 네번째 영역 안에 들어가는가?
    else if(startY <= g_tY+halfSide && startX <=g_tX+halfSide &&
        startY+(halfSide*2) > g_tY && startX+(halfSide*2) > g_tX)
    {
        ChaseTarget(startY+halfSide, startX+halfSide, nowN-1, nowSum + (smallSquare*3));
    }
}

int main()
{
    cin >> g_N >> g_tY >> g_tX;
    ChaseTarget(0, 0, g_N, 0);
    cout << g_sum;
    return 0;
}