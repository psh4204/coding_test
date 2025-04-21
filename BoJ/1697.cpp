/* 숨바꼭질
https://www.acmicpc.net/problem/1697

N과 M은 숨바꼭질 중 (0 ~ 100,000)
N은 다음과 같이 이동가능
- 현재위치X +1, -1, X*2(순간이동)
M을 찾는 가장빠른 시간을 출력하자

풀이
- BFS로 해야할거같은데
- visited엔 카운트 넣고 ㅌㅌ.
*/
#include <bits/stdc++.h>
using namespace std;
#define MAX_GRD 100001
int g_N, g_M, g_answer;
vector<int> g_ground(MAX_GRD, INT_MAX);

int main()
{
    cin >> g_N >> g_M;
    queue<int> moveQ;
    moveQ.push(g_N);
    g_ground[g_N] = 0;
    do{
        int now = moveQ.front();
        moveQ.pop();
        if(now*2 <= MAX_GRD && g_ground[now*2]>(g_ground[now]+1))
        {
            moveQ.push(now*2);
            g_ground[now*2] = g_ground[now]+1;
            // cout << g_ground[now*2] << "<< \n";
            if(now*2 == g_M)
                break;
        }
        if(now+1 <= MAX_GRD && g_ground[now+1]>(g_ground[now]+1))
        {
            moveQ.push(now+1);
            g_ground[now+1] = g_ground[now]+1;
            // cout << g_ground[now+1] << "<< \n";
            if(now+1 == g_M)
                break;
        }
        if(now-1 >= 0 && g_ground[now-1]>(g_ground[now]+1))
        {
            moveQ.push(now-1);
            g_ground[now-1] = g_ground[now]+1;
            // cout << g_ground[now-1] << "<< \n";
            if(now-1 == g_M)
                break;
        }
    }while(!moveQ.empty());
    cout << g_ground[g_M];
    return 0;
}