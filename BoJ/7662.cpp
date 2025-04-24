/* https://www.acmicpc.net/problem/7662
이중 우선순위 큐
- 데이터 삽입, 삭제 연산만 함
    - 삭제는 2가지 가장우선순위가 높은것, 낮은것 두개 삭제 가능

입력
- Tc (테케)
- N 명령
- I n (n을 삽입하라)
- D 1 (최대값 삭제)
- D -1 (최소값 삭제)

출력
- 최대 최소

풀이
- 기본적인 2개 PQ를 만들어서 풀면 됨 (map, set 쓰면 시간초과 나게했을듯)
- EMPTY 처리를 어떻게 해야할까?
- pq 두개로 하면 계속 틀림
- map 으로 ㄱㄱ. (중복된 정수 있으니)
*/
#include <bits/stdc++.h>
using namespace std;

struct Cmp{
    bool operator() (const int & left, const int & right) const
    {
        return left > right;
    }
};

int g_TC, g_N, g_inNum;
char g_inChar;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> g_TC;
    while(g_TC--)
    {
        map<int,int, Cmp> nums; // {num, 중복cnt} 
        cin >> g_N;

        while(g_N--)
        {
            cin >> g_inChar >> g_inNum;
            switch(g_inChar)
            {
                case('I'):
                {
                    auto it = nums.find(g_inNum);
                    if(it == nums.end())
                        nums.insert({g_inNum,1});
                    else
                        it->second++;
                }
                break;
                
                case('D'):
                {
                    if(nums.empty())
                        continue;
                    if(g_inNum == 1)
                    {
                        if(nums.begin()->second == 1)
                            nums.erase(nums.begin());
                        else
                            nums.begin()->second--;
                    }
                    else if(g_inNum == -1)
                    {
                        auto it = nums.end();
                        it--;
                        if(it->second == 1)
                            nums.erase(it);
                        else
                            it->second--;
                    }
                }
                break;
            }
        }
        // 비었는지 체크
        if(nums.empty())
        {
            cout << "EMPTY\n";
            continue;
        }

        // 최대힙 PQ 순서로 가장 앞, 뒤 출력
        auto front = nums.begin();
        auto back = nums.end();
        back--;
        cout << front->first << " " << back->first<<"\n";
    }
    return 0;
}