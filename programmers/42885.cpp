/* https://school.programmers.co.kr/learn/courses/30/lessons/42885
구명보트에 최대 2명밖에 탈수있고, 무게제한 있음.
구명보트를 최대한 적게 사용해서 모두 탈출시켜보자.
- people : 1~50,000
- weight : 40~240
- limit : 40~240

풀이
- 오름차순으로 sort
- 투포인터로 가장 100키로에 가깝게 사람 구한 후 visited 처리
-- (시간초과)

최적화
- backIdx가 frontIdx앞까지 동작하게 해서 Loop 최소화
- backIdx를 g_lastBackIdx로 재활용했음.
*/


#include <bits/stdc++.h>
using namespace std;
vector<bool> g_visited;
int g_answer = 0;
int g_lastBackIdx = -1;

int solution(vector<int> people, int limit) {
    g_visited.resize(people.size(), false);
    sort(people.begin(), people.end());
    
    for(int frontIdx = 0; frontIdx < people.size(); frontIdx++)
    {
        if(g_visited[frontIdx]) continue;
        
        if(g_lastBackIdx == -1)
            g_lastBackIdx = people.size()-1;
            
        for(; g_lastBackIdx > frontIdx; g_lastBackIdx--)
        {
            if(g_visited[g_lastBackIdx]) continue;
            
            if(people[frontIdx] + people[g_lastBackIdx] <= limit)
            {
                g_answer++;
                g_visited[frontIdx] = true;
                g_visited[g_lastBackIdx] = true;
                break;
            }
        }
    }
    for(auto isVisited: g_visited)
    {
        if(!isVisited)
            g_answer++;
    }
    return g_answer;
}