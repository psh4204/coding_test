/* 사전 순 최대 공통 부분 수열
https://www.acmicpc.net/problem/30805

사전순: 진짜 그 사전순(string으로 관리해야할듯)

두 수열을 받으면 공통 부분수열을 뽑아내시오
- 그리고 공통부분수열들 중에서 사전순으로 가장 나중인 것을 구하라

입력
- A 수열 길이
- A 수열
- B 수열 길이
- B 수열

출력
- 공통부분수열에서 사전순으로 가장 마지막 수열의 길이
- 해당 수열 출력

풀이
- 2차원 배열로 LCS를 구하는 법은 알지만, 이를 History 화 하는건 안해봄
    - 공통부분나올때 마다 set에 저장하는 방식?
    - 그리고 1~100 까지 2차원배열 하나 저장해두고, 만약, .. 답이없음
- 다시다시: 힌트보고왔는데, 문제이름이 잘못됐네 (최대 공통 부분수열이 아니라, 그냥 사전순 공통부분수열이어야함)
- 첫번째 수열은 그냥 받아놓음
- 두번째 수열을 받으면서, 수열 인자와 idx를 PQ에 저장해둠 (더큰 인자, 더 가까운idx)
- 이제 PQ top에서 값을 받아와서 하나 하나 공통 부분 수열을 만들어 둠. 
    - 만약 현재 top 인덱스가 마지막 top 인덱스 보다 크면 공통부분수열 만들기 끝 <- 이게 정답


100
13 29 50 36 2 27 45 2 9 10 
4 29 37 17 34 34 84 90 92 83 
43 25 54 12 29 53 100 74 89 25 
87 84 75 45 1 12 10 51 11 7 
27 38 10 40 2 41 83 3 87 45 
35 44 35 20 73 44 73 22 64 18 
100 33 3 20 61 82 61 69 94 20 
20 2 3 33 25 30 51 46 18 47 
60 55 52 94 74 86 8 50 67 24 
36 41 67 23 16 19 62 37 68 10
100
57 96 52 17 39 62 25 49 12 14 
55 100 65 42 65 83 29 67 75 18 
60 25 40 67 22 25 95 36 69 51 
94 49 50 18 92 65 91 15 22 25 
77 23 55 53 30 54 12 45 26 15 
96 84 60 19 93 45 1 20 27 26 
42 37 20 89 16 57 64 68 72 17 
43 6 38 94 46 16 21 56 9 64 
45 47 4 81 50 51 60 92 14 84 
83 7 1 61 69 41 54 64 64 44

*/
#include <bits/stdc++.h>
using namespace std;
int g_a, g_b;
struct Num_t{
    int num;
    int idx;
};
struct MaxHeapB{
    bool operator() (const Num_t & left, const Num_t & right) const
    {
        if(left.num > right.num)
            return false;
        else if(left.num == right.num)
        {
            return !(left.idx < right.idx);
        }
        return true;
    }
};

vector<int> g_aNums(101);
priority_queue<Num_t, vector<Num_t>, MaxHeapB> g_pqB; // b 수열 숫자, idx를 MaxHeap으로 저장
int g_lastAIdx = 0, g_lastBIdx = 0;
vector<int> g_ans;

int main()
{
    cin >> g_a;
    for(int aIdx = 1; aIdx <= g_a; aIdx++)
    {
        cin >> g_aNums[aIdx];
    }
    cin >> g_b;
    for(int bIdx = 1; bIdx <= g_b; bIdx++)
    {
        int input;
        cin >> input;
        g_pqB.push({input, bIdx});
    }

    while(!g_pqB.empty())
    {
        int lastAIdx = g_lastAIdx;
        // 현재 탑의 idx가 lastTop idx보다 작으면 continue
        if(g_lastBIdx >= g_pqB.top().idx)
        {
            g_pqB.pop();
            continue;
        }
        for(int aIdx = g_lastAIdx+1; aIdx <= g_a; aIdx++)
        {
            if(g_pqB.top().num == g_aNums[aIdx])
            {
                g_ans.push_back(g_aNums[aIdx]);
                g_lastBIdx = g_pqB.top().idx;
                lastAIdx = aIdx;
                break;
            }
        }
        g_lastAIdx = lastAIdx;
        g_pqB.pop();
    }
    if(g_ans.empty())
        cout << 0;
    else
    {
        cout << g_ans.size() << "\n";
        for(auto num : g_ans)
            cout << num << " ";
    }
    return 0;
}