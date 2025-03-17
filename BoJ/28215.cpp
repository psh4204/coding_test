/*https://www.acmicpc.net/problem/28215
대피소

2차원 평면에 N개의 집들이 있고, K개의 대피소를 집들 중에서 고르려고 함.
K개의 대피소를 설치했을때, '대피소에서 가장 멀리떨어진 집의 거리'가 최소가 되는 경우를 찾아서
그 거리를 출력한다.

입력
- N, K가 공백을 사이에 두고 주어진다. (1~K~3, K~N~50)
- N개만큼 집의 위치가 주어진다. (0~X,Y~100,000)

출력
- 답을 출력한다.

풀이
- N개의 집의 K개씩 뽑는 조합 문제
- (0.좌표의 총합으로 오름차순 sort)(추후 생각해보자. 일단 구현우선)
- 1.대피소를 조합으로 뽑는다
- 2.각집마다 대피소 최소거리를구한다
- 3.최소거리중 가장 긴곳을 최종Output으로 둔다.
- 4.각 조합마다 최종 Output이 가장 짧은값이 정답이다.

5 2
1 5
3 0
3 3
6 12
8 9

*/
#include <bits/stdc++.h>
using namespace std;
int g_N, g_K, g_answer = 987654321;
struct House_t{
    int x;
    int y;
};
vector<House_t> g_houses;
vector<int> g_combiList;

// sort
bool Comp(House_t & first, House_t & second)
{
    int firstAll = first.x + first.y;
    int secondAll = second.x +second.y;
    if(firstAll <= secondAll)
        return true;
    else
        return false;
}


// TODO: 최적화
void GetAnswer()
{
    int maxShelterRoad = 0;
    // 해당 집기준에서 가장 가까운 Shelter 거기를 다 구한 후, 그들중 가장 max값을 먼저구한다.(answer).
    // answer 중에서 가장 작은 값이 진짜 answer다.

    // cout << "||COMBI|| \n"; //TEST
    // for(auto v: g_combiList)
    //     cout << v << "," ;
    // cout <<"----\n";
    // 집마다 자신의 셸터가 어딘지 확인.
    for(int hIdx = 0; hIdx < g_houses.size(); hIdx++)
    {
        // 우리집이 Shelter면 PASS;
        bool isMyHouseShelter = false;
        for(auto sht : g_combiList)
        {
            if(sht == hIdx)
            {
                isMyHouseShelter = true;
                break;
            }
        }
        if(isMyHouseShelter)
            continue;
        // 집에서 가장 가까운 Shelter를 구한다.
        int myMinRoad = 987654321;
        for(int shtIdx = 0; shtIdx < g_K; shtIdx++)
        {
            int road = abs(g_houses[g_combiList[shtIdx]].x - g_houses[hIdx].x) + abs(g_houses[g_combiList[shtIdx]].y - g_houses[hIdx].y);
            // cout << road << ", "; // TEST
            myMinRoad = min(road,myMinRoad);
        }
        // cout << "["<< myMinRoad << "]"<<"\n"; // TEST
        // 그리고 myMinRoad 중 가장 큰값을 구한다.
        maxShelterRoad = max(myMinRoad, maxShelterRoad);,.
    }
    // 마지막으로 정답과 비교하여 더 작은값을 구한다.
    g_answer = min(g_answer, maxShelterRoad);
}

// 조합
void Combi(int currIdx)
{
    if(g_combiList.size() == g_K)
    {
        GetAnswer();
        return;
    }
    for(int nextIdx = currIdx + 1; nextIdx < g_houses.size(); nextIdx++)
    {
        g_combiList.push_back(nextIdx);
        Combi(nextIdx);
        g_combiList.pop_back();
    }
}


int main(void)
{
    cin >> g_N >> g_K;
    while(g_N--)
    {
        House_t houseInput;
        cin >> houseInput.x >> houseInput.y;
        g_houses.push_back(houseInput);
    }
    Combi(-1);

    cout << g_answer;
    return 0;
}