/* N과 M (12)
https://www.acmicpc.net/problem/15666

다음 M개의 수열을 만들어라
- N개의 자연수 중 M개를 고른 수열
- 여러번 골라도 됨
- 비 내림차순(같거나 커야함)

입력
- N  M (1~8)
- 숫자들

풀이
- 아까 푼거에서 history 체크 안해주면 됨
*/
#include <bits/stdc++.h>
using namespace std;
int g_N, g_M;
vector<int> g_nums;
vector<int> g_history;
unordered_set<string> g_outputHistory;

void CheckCombo(int start)
{
    if(g_history.size() == g_M)
    {
        string output;
        for(auto outNum: g_history)
            output +=  to_string(outNum) + " ";
        output += "\n";
        if(g_outputHistory.find(output) == g_outputHistory.end())
        {
            cout << output;
            g_outputHistory.insert(output);
        }
        return;
    }
    for(int next = start; next < g_nums.size(); next++)
    {
        g_history.push_back(g_nums[next]);
        CheckCombo(next);
        g_history.pop_back();
    }
}

int main()
{
    cin >> g_N >> g_M;
    g_nums.resize(g_N);
    for(int inCnt = 0; inCnt < g_N; inCnt++)
    {
        cin >> g_nums[inCnt];
    }
    sort(g_nums.begin(), g_nums.end());
    CheckCombo(0);
    return 0;
}