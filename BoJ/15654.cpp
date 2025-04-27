/* N과 M (5)
https://www.acmicpc.net/problem/15654

N과 M이 주어지면 다음의 조건을 만족하는 길이 M의 수열을 구하라
- 자연수 N개중 M개를 고른 수열

입력
- N M
- N개의 수 (10,000 이하)
출력
- 중복되지 않게 조합해서 출력

풀이
- N개의 수 받으면 sort
- 그리고 조합

[NOTE]
- 허세 금지
- 풀이법 생각나면 그거로 풀기
*/
#include <bits/stdc++.h>
using namespace std;
int g_N, g_M, g_input;
vector<int> g_nums;
vector<int> g_history;

void CheckCombo(int historyBit)
{
    if(g_history.size() == g_M)
    {
        for(auto num: g_history)
            cout << num << " ";
        cout << "\n";
        return;
    }
    for(int nextIdx = 0; nextIdx < g_nums.size(); nextIdx++)
    {
        if(historyBit & 1 << nextIdx)
            continue;
        g_history.push_back(g_nums[nextIdx]);
        CheckCombo(historyBit | (1<<nextIdx));
        g_history.pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> g_N >> g_M;
    while(g_N--)
    {
        cin >> g_input;
        g_nums.push_back(g_input);
    }
    sort(g_nums.begin(), g_nums.end());
    CheckCombo(0);
    return 0;
}