#include <bits/stdc++.h>
using namespace std;
int g_N, g_K, g_currIdx;
vector<int> g_nums;
vector<int> g_yosepus;

int main()
{
    cin >> g_N >> g_K;
    // Init values
    g_nums.resize(g_N,1);
    while(!(!g_yosepus.empty() && g_yosepus.size() == g_N)) // yosepus의 크기가 N이되면 종료
    {
        int kCnt = 0;
        while(kCnt != g_K)
        {
            // 현재 인덱스가 배열을 벗어나면 리셋
            if(g_currIdx == g_N)
                g_currIdx = 0;
            // 현재 숫자가 살아있으면 카운트
            if(g_nums[g_currIdx] == 1)
            {
                kCnt++;
                if(kCnt==g_K) break;
            }
            g_currIdx++;
        }
        // yosepus에 삽입 후 해당 숫자는 숫자배열에서 삭제
        g_yosepus.push_back(g_currIdx+1);
        // cout << (g_currIdx+1) << " "; // [TEST]
        g_nums[g_currIdx] = 0;
        g_currIdx++;
    }
    cout << "<";
    for(int ysIdx = 0; ysIdx < g_N; ysIdx++)
    {
        cout << g_yosepus[ysIdx];
        if(ysIdx < g_N-1)
            cout << ", ";
    }
    cout << ">";
    return 0;
}

// 이건 어케풀었는지 다시봐보자. ㅋㅋㅋㅋ 너무 야매로 풀었어..