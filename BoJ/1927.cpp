/* 최소 힙
https://www.acmicpc.net/problem/1927

0을 삽입하면 가장작은값을 뱉고 지우고,
다른 값을 넣으면 삽입되는 힙 배열을 만들라


*/
#include <bits/stdc++.h>
using namespace std;
int g_N, g_input;
map<int,int> g_heap; // num, cnt

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> g_N;
    while(g_N--)
    {
        cin >> g_input;
        if(g_input == 0)
        {
            if(g_heap.empty())
                cout << 0 << "\n";
            else
            {
                cout << g_heap.begin()->first << "\n";
                // TODO: Count 관리
                if(g_heap.begin()->second <= 1)
                    g_heap.erase(g_heap.begin());
                else
                    g_heap.begin()->second--;
            }
        }
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