/* 과일 탕탕탕탕사후르
https://www.acmicpc.net/problem/30804

1~9 번까지 과일종류로 N까지 꼬치에 꽂아뒀다
여기서 단 두가지의 과일 종류만 남기고 꼬치를 만들어야한다
양 사이드로 과일을 빼서 위의 요구사항에 맞추려하는데
이렇게 했을때 남은 과일의 최대 수를 구하라

입력
- N (1~200,000)
- 과일 리스트

출력
- 최대 과일수

풀이
- 단순하게 풀자면
    - 각 배열마다 하나하나 순서대로 방문
    - 어떤 과일종류를 들고있었는지 체크 (비트필드로)
    - 순회하면서 비트필드로 visited 체크, 그리고 최종 카운트도 체크
*/
#include <bits/stdc++.h>
using namespace std;
vector<int> g_fruits;
int g_N, g_input, g_maxLen = 0;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> g_N;
    for(int inCnt = 0; inCnt < g_N; inCnt++)
    {
        cin >> g_input;
        g_fruits.push_back(g_input);
    }
    for(int startIdx = 0; startIdx < g_N; startIdx++)
    {
        int fruitColabo = 1<<g_fruits[startIdx];
        int colaboCnt = 1, len = 0, nextIdx = startIdx, searchIdx = startIdx;
        for(; searchIdx < g_N; searchIdx++)
        {
            if(g_fruits[startIdx] == g_fruits[searchIdx])
            {
                len++;
                if(colaboCnt == 2)
                    nextIdx = searchIdx-1;
            }
            // 다른 과일이 나왔을 때
            else if(colaboCnt == 2)
            {
                if((fruitColabo & 1<<g_fruits[searchIdx]))
                    len++;
                else
                    break;
            }
            else if(colaboCnt == 1) // 단순히 과일만 안맞는데 colabo가 아직 1일때
            {
                colaboCnt++;
                len++;
                fruitColabo |= 1<<g_fruits[searchIdx];
                nextIdx = searchIdx-1;
            }
        }
        g_maxLen = max(len, g_maxLen);
        startIdx = nextIdx;
        // cout << g_fruits[startIdx] << ": " << len << " <<< \n"; // TEST
        if(fruitColabo == 1<<g_fruits[startIdx]) // 다 동일한 과일만 나왔다면
            break;
    }
    cout << g_maxLen;
    return 0;
}