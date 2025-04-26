/* N과 M(4)
https://www.acmicpc.net/problem/15652

자연수 N M 이 주어지면 다음을 만족하는 길이가 M인 수열 구하기
- 1부터 N까지 자연수 중 M개를 고른 수열
- 같은 수를 여러번 골라도 된다
- 고른 수열은 비 내림차순(오름차순이며 숫자가 겹치는거)

입력
- N M (1~M<=N~8)
출력
- 수열들

풀이
- Combo문제인데 비내림차순으로 보여줘야하는 것이 관건
- 으음~ start 숫자가 겹치면 되는거네 그냥
*/
#include <bits/stdc++.h>
using namespace std;
int g_N, g_M;
vector<int> g_history;

void CheckCombo(int startNum)
{
    if(g_history.size() == g_M)
    {
        for(auto hist: g_history)
            cout << hist << " ";
        cout << "\n";
        return;
    }
    for(int nextNum = startNum; nextNum <= g_N; nextNum++)
    {
        g_history.push_back(nextNum);
        CheckCombo(nextNum);
        g_history.pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> g_N >> g_M;
    CheckCombo(1);
    return 0;
}