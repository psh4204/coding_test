/* 절대값 힙
https://www.acmicpc.net/problem/11286

절대값 힙
- 0이 아닌 정수를 넣는다
- 절대값이 가장 작은값을 출력 후 배열에서 제거
- 절대값이 가장작은 값이 여러개일때, 가장 작은 수를 출력 후, 배열에서 삭제

0을 입력받으면 절대값중 가장 작은 값 출력
- 비어있는경우 0출력

입력
- N (개수. 1~100,000)
- 정수들 (int)
*/
#include <bits/stdc++.h>
using namespace std;

struct CustomCmp{
    bool operator() (const int & first, const int & second)const{
        if(abs(first) < abs(second))
            return true;
        else if(abs(first) == abs(second))
        {
            return first < second;
        }
        return false;
    }
};

int g_N, g_input;
map<int,int, CustomCmp> g_heap;


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
                if(g_heap.begin()->second == 1)
                    g_heap.erase(g_heap.begin());
                else
                    g_heap.begin()->second-=1;
            }
        }
        else
        {
            auto it = g_heap.find(g_input);
            if(it == g_heap.end())
                g_heap.insert({g_input,1});
            else
                it->second++;
        }
    }
    return 0;
}
