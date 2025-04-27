/* N과 M(9)
https://www.acmicpc.net/problem/15663

다음 조건의 길이가 M인 수열 만들기
- N개의 ㅈ연수중 M개를 고른 수열

입력
- N M (1~8)
- 자연수들

출력
- 중복되지않는 오름차순 수열(사전순이면 string처리하라는말인가?)

풀이
- 수를 받으면 사전순으로 M개 채운 조합 만들어 출력하면됨
- 출력은 사전순으로 하라네?
- 중복되지 않는 출력이라는거 자체가, 출력물  중 중복되는거 없는거 말하는 것인듯 
    (1 2 -> 1 2 X, 1 1 -> 2 2 O)
- 
*/
#include <bits/stdc++.h>
using namespace std;
int g_N, g_M, g_input;
vector<int> g_nums;
vector<int> g_history;
unordered_set<string> g_coupled; // 출력물 중복 체크


void PrintCombo(int startIdx, int histBit)
{
    if(g_history.size() == g_M)
    {
        string output;
        for(auto outNum: g_history)
            output += to_string(outNum) + " ";
        output += "\n";
        if(g_coupled.find(output) == g_coupled.end())
        {
            cout << output;
            g_coupled.insert(output);
        }
        return;
    }
    for(int nextIdx = 0; nextIdx < g_nums.size(); nextIdx++)
    {
        if(histBit & 1<<nextIdx)
            continue;
        histBit |= 1<< nextIdx;
        g_history.push_back(g_nums[nextIdx]);
        PrintCombo(nextIdx, histBit);
        histBit &= ~(1<<nextIdx);
        g_history.pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> g_N >> g_M;
    for(int inCnt = 0; inCnt < g_N; inCnt++)
    {
        cin >> g_input;
        g_nums.push_back(g_input);
    }
    sort(g_nums.begin(), g_nums.end());
    PrintCombo(-1 , 0);

    return 0;
}