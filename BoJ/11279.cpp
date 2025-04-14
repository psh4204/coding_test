/* 최대힙
https://www.acmicpc.net/problem/11279

내림차순 힙배열 만들기
- x 넣기
- 0 삽입시 가장 큰값 출력 후 front 삭제. 없으면 0출력
*/
#include <bits/stdc++.h>
using namespace std;
int g_N, g_input;
map<int, int, greater<int>> g_heap; // {값, 카운트}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> g_N;
    while(g_N--)
    {
        cin >> g_input;
        // 0입력 받았을때 
        if(g_input == 0)
        {
            // 배열이 비어있으면 0출력
            if(g_heap.empty())
            {
                cout << 0 << "\n";
                continue;
            }
            // 아니라면 가장큰값 출력 후 삭제
            auto it = g_heap.begin();
            cout << it->first << "\n";
            if(it->second == 1)
                g_heap.erase(it);
            else
                it->second--;
        }
        // 다른 값이면 삽입
        else
        {
            auto it = g_heap.find(g_input);
            if(it == g_heap.end())
                g_heap.insert({g_input, 1});
            else
                it->second++;
        }
    }
    return 0;
}