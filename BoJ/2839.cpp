/* 설탕 배달
https://www.acmicpc.net/problem/2839

설탕을 정확히 N킬로그램 배달해야한다
봉지는 3키로, 5키로가 있고, 최대한 적은봉지로 가져가고싶음

N키로를 가져가야할때 봉지 몇개를 가져가면되는지 알아보기

정확하게 N 키로 못가져가면 -1 표시

풀이
- 단순계산 + 마지막 무게에서 담을수 있는지 못담는지 체크해야할듯
- 5로 쭉 나눈 후, 3으로 나눠지는지를 지속적 체크
    - 3으로 안나눠지면 5키로씩 주며 5키로카운트한거 --
    - 계속 3으로 나눠지는지 체크
    - 나워지면 3으로 카운트한거 뽑기
    - 안되면 -1
    - 살짝 투포인터하는느낌으로 ㄱㄱ
*/
#include <bits/stdc++.h>
using namespace std;
int g_fiveCnt, g_threeCnt, g_remain, g_N;

int main()
{
    cin >> g_N;

    // 1. 5키로 봉지로 얼마나 나눠지는지 확인
    g_remain = g_N%5;
    g_fiveCnt = g_N/5;

    // 2. 3키로 봉지가 몇이나 필요한지 확인
    while(g_remain != 0)
    {
        if(g_remain%3 != 0)
        {
            // 5와 3으로로 정확히 안나눠질때 탈출
            if(g_fiveCnt == 0)
                break;
            g_fiveCnt -=1;
            g_remain +=5;
        }
        else
        {
            // 3. 3으로 나눠지면 탈출
            g_threeCnt = g_remain/3;
            break;
        }
    }
    
    if(g_fiveCnt == 0 && g_threeCnt == 0)
        cout << -1;
    else
        cout << g_fiveCnt + g_threeCnt;

    return 0;
}