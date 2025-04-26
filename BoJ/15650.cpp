/* N과 M(2)
https://www.acmicpc.net/problem/15650

N과 M이 주어지면, 다음의 조건을 채우는 길이가 M인 수열을 모두 구하자
- 1부터 N까지 자연수 중 중복없이 M개를 고른 수열
- 고른 수열은 오름차순

입력
- N M (1~ M <= N ~ 8)

출력
- 조건을 충족하는 수열 출력 (중복수열 X)

풀이
- 재귀로 조합
    - 시작 숫자는 1부터 N까지
    - 최대 숫사 개수는 'M'
- 그리고 조합을 가지고있어야함
*/
#include <bits/stdc++.h>
using namespace std;
int g_N, g_M;
vector<int> g_combo;

void CheckCombo(int nowNum, const int numCnt)
{
    if(numCnt == g_M)
    {
        for(auto output: g_combo)
            cout << output << " ";
        cout << "\n";
        return;
    }
    for(int nextNum = nowNum+1; nextNum <= g_N; nextNum++)
    {
        g_combo.push_back(nextNum);
        CheckCombo(nextNum, numCnt+1);
        g_combo.pop_back();
    }
}

int main()
{
    cin >> g_N >> g_M;
    CheckCombo(0,0);
    return 0;
}