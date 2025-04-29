/* A -> B
https://www.acmicpc.net/problem/16953

A를 B로 다음의 연산으로 바꾸려한다
- *2
- 1을 가장 오른쪽에 추가

A를 B로 바꾸기위해 필요한 연산 최소 횟수 구하기

입력
- A B (1~1,000,000,000)
출력
- 최소횟수

풀이
- BFS 문제
- 값에 가장 빨리 도달하면 끝남
*/
#include <bits/stdc++.h>
#define MAX_NUM 1000000000
using namespace std;
typedef long long ll;
ll g_A, g_B, g_ans = -1;
vector<bool> g_visited(1000000001, false);

int main()
{
    cin >> g_A >> g_B;

    queue<pair<ll,ll>> calcQ; // {value, cnt}
    calcQ.push({g_A, 0});
    g_visited[g_A] = true;
    
    while(!calcQ.empty())
    {
        pair<ll,ll> now = calcQ.front();
        calcQ.pop();
        ll nextNum = now.first * 2;
        ll nextCnt = now.second +1;
        if(nextNum <= MAX_NUM && g_visited[nextNum] == false)
        {
            g_visited[nextNum] = true;
            if(nextNum == g_B)
            {
                g_ans = nextCnt;
                break;
            }
            calcQ.push({nextNum,nextCnt});
        }
        nextNum = now.first*10 + 1;
        if(nextNum <= MAX_NUM && g_visited[nextNum] == false)
        {
            g_visited[nextNum] = true;
            if(nextNum == g_B)
            {
                g_ans = nextCnt;
                break;
            }
            calcQ.push({nextNum,nextCnt});
        }
    }
    if(g_ans == -1)
        cout << -1;
    else if(g_A == g_B)
        cout << 0;
    else
        cout << g_ans+1;
    return 0;
}