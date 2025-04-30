/* 숨바꼭질 3
https://www.acmicpc.net/problem/13549

동생을 찾아보자 (점 0 ~ 100,000)
현재위치는 N 동생위치는 K다

이동기
- N +-1 칸: 시간 1초
- K*2 칸: 시간 0초

최소시간으로 동생을 찾아본다

입력
- N K

풀이
- BFS 문제
- 길목 visted 배열생성 (100,000, -1)// -1은 아직 접근안함표시
- 이동시 위의 이동시간( +1 혹은 +0씩) 해줌
- 찾았을때 해당 최소 이동시간을 출력한다

[Note]
- 이문제는 *2, -1, +1순으로 탐색해야 답이나옴
*/
#include <bits/stdc++.h>
using namespace std;
#define MAX_ROAD 100000
int g_N, g_K, g_ans;
vector<int> g_visited(MAX_ROAD +1, -1);
struct Subin_t{
    int place;
    int time;
};

int main()
{
    cin >> g_N >> g_K;
    queue<Subin_t> subinQ;
    subinQ.push({g_N, 0});
    g_visited[g_N] = 0;
    if(g_N == g_K)
    {
        cout << 0;
        return 0;
    }
    while(!subinQ.empty())
    {
        Subin_t now = subinQ.front();
        cout << "now.place: " <<  now.place << " now.time: " << now.time << "\n"; // TEST
        Subin_t next;
        subinQ.pop();
        // *2칸 이동(0초소요)
        next.place = now.place*2;
        if(next.place <= MAX_ROAD 
            && (g_visited[next.place] == -1))
        {
            next.time = now.time;
            g_visited[next.place] = next.time;
            if(next.place == g_K)
            {
                g_ans = next.time;
                break;
            }
            subinQ.push(next);
        }

        // -1칸 이동(1초소요)
        next.place = now.place-1;
        if(next.place >= 0 
            && (g_visited[next.place] == -1))
        {
            next.time = now.time+1;
            g_visited[next.place] = next.time;
            if(next.place == g_K)
            {
                g_ans = next.time;
                break;
            }
            subinQ.push(next);
        }
        // +1칸 이동(1초소요)
        next.place = now.place+1;
        if(next.place <= MAX_ROAD 
            && (g_visited[next.place] == -1))
        {
            next.time = now.time+1;
            g_visited[next.place] = next.time;
            if(next.place == g_K)
            {
                g_ans = next.time;
                break;
            }
            subinQ.push(next);
        }
    }

    cout << g_ans;
    return 0;
}