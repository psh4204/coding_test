/* 달팽이쉐
https://www.acmicpc.net/problem/2869

달팽이가 하루에 
낮에는 A 씩 올라가고
밤에는 B 씩 미끄러짐
V에 도달했을땐 안미끄러짐.

V까지 도달하는데 걸리는 날짜를 계산하라 (제한시간 0.25초)

입력
- A B V (1~1,000,000,000)

풀이
- 하루에 A씩 올라가고 B씩 내려간다 = 보통의 경우 A-B씩 하루에 올라감 = climb 이라 하겠음
- 마지막 V까지 가 남은 날을 계산하면 될것으로 판단됨
    - 단, V/climb 했을때 나머지 값(남은 거리)이 나오면 하루를 더가야할것으로 판단됨.
*/

#include <bits/stdc++.h>
using namespace std;
int g_A, g_B, g_V, g_beforeEnd, g_climb, g_days;

int main()
{
    cin >> g_A >> g_B >> g_V;
    g_climb = g_A-g_B;
    g_beforeEnd = g_V - g_A;
    if(g_beforeEnd > 0)
    {
        int remain_road = g_beforeEnd % g_climb;
        g_days = g_beforeEnd / g_climb;
        if(remain_road > 0) g_days +=1;
    }
    g_days+=1;
    cout << g_days;
}