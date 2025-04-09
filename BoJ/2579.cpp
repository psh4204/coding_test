/* 계단오르기
https://www.acmicpc.net/problem/2579

계단을 오르면 점수를 얻을 수 있는데, 최대점수를 구하라

규칙
- 1,2칸 씩 올라갈 수 있다
- 3칸 이상 연속으로 못올라간다
- 마지막 계단을 꼭 밟아야한다

계단수 300 이하
점수 10,000 이하

풀이
- DP 문제
    - 각 계단별 최대점수를 삽입한다
    - 계단을 연속 몇번째 밟았는지 나눠서 최대점수를 관리한다
    - 계단을 오를때 최대점수보다 낮으면 계단을 오르지않는다. 


반례(1)
6
10
20
15
25
10
20
ans:75

반례(2)
3
1
100
10
ans:120

*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int g_N, g_NCopy;
ll g_maxScore;
vector<int> g_floors;
vector<pair<ll,ll>> g_maxScores;

bool SetMaxScore(int nextfloor, int nextContIdx, ll nextScore)
{
    switch(nextContIdx)
    {
        case(1):
        {
            if(g_maxScores[nextfloor].first > nextScore)
                return false;
            g_maxScores[nextfloor].first = nextScore;
        }
        break;

        case(2):
        {
            if(g_maxScores[nextfloor].second > nextScore)
                return false;
            g_maxScores[nextfloor].second = nextScore;
        }
        break;
    }
    return true;
}

void CheckFloorScore(int floor, int contIdx, ll score)
{
    if(floor+1 >= g_N)
        return;
    for(int stepIdx = 1; stepIdx < 3; stepIdx++)
    {
        switch(stepIdx)
        {
            case(1):
            {
                if(contIdx + 1 == 3)
                    continue;
                if(SetMaxScore(floor+1,contIdx+1,score+g_floors[floor+1]))
                    CheckFloorScore(floor+1,contIdx+1,score+g_floors[floor+1]);
                else
                    return;
            }
            break;

            case(2):
            {
                if(floor + 2 >= g_N)
                    return;
                if(SetMaxScore(floor+2, 1, score+g_floors[floor+2]))
                    CheckFloorScore(floor+2, 1,score+g_floors[floor+2]);
                else
                    return;
            }
            break;
        }
        
    }
}

int main()
{
    cin >> g_N;
    g_NCopy = g_N;
    while(g_NCopy--)
    {
        int input;
        cin >> input;
        g_floors.push_back(input);
        g_maxScores.push_back({0,0});
    }
    CheckFloorScore(-1, 0, 0);
    cout << max(g_maxScores[g_N -1].first, g_maxScores[g_N -1].second);
    return 0;
}