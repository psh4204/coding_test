/* 1,2,3 더하기
https://www.acmicpc.net/problem/9095

정수 N을 만들 수 있는 '1,2,3'의 합 경우의 수를 구하라 (n은 11보다 작다.)
예시)
4
- 1+1+1+1/ 1+1+2/ 1+2+1/2+1+1/2+2/1+3/3+1

입력
- TC
- N ...

출력
- 가지수 들

풀이
- 1 부터 11까지 합의 경우의 수를 구해야함
- 1,2,3 으로 재귀만들어서 sum이 N일때까지 구하고 카운트하면 됨
- 같은조합을 사용되는것을 막아야할텐데 ... (같은조합 안나옴. 순열이라 다양히 나옴)
*/
#include <bits/stdc++.h>
using namespace std;
int g_TC, g_N;
vector<int> g_answers(12);

int GetCount(const int & target, int sum)
{
    int count = 0;
    if(sum == target)
    {
        // cout << "= " << sum << "\n"; // "TEST"
        return 1;
    }
    
    for(int plusIdx = 1; plusIdx <=3; plusIdx++)
    {
        if(sum + plusIdx > target)
            continue;
        // cout << "+ " << plusIdx; // "TEST"
        count += GetCount(target, sum + plusIdx);
    }
    return count;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> g_TC;
    while(g_TC--)
    {
        cin >> g_N;
        if(g_answers[g_N] != 0)
            cout << g_answers[g_N] <<"\n";
        else
        {
            g_answers[g_N] = GetCount(g_N, 0);
            cout << g_answers[g_N] << "\n";
        }
    }
    return 0;
}