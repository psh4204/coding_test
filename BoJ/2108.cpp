/* 통계학
https://www.acmicpc.net/problem/2108

N은 홀수
- 산술평균: N개의 수들의 합에서 N을 나눈 평균
- 중앙값:   N개의 수들을 오름차순 배치. 여기서 중앙값
- 최빈값:   N개의 수들 중에서 가장 자주 나오는 값
- 범위:     N개의 수들 중 최대 최소 값

입력
- N (1~500,000)
- 숫자들 (4000을 안넘김)

출력
- 문제에서 말한 값 출력

풀이
- 산술평균은 소수점 첫째자리에서 반올림 -> round
- 범위는 max - min
- 중앙값, 최빈값이 문제네
    - 중앙값은 흠..
    - 최빈값은 hash map
    - 최빈값을 구하면서, 중앙값을 구해보자
    - 최빈값을 찾으며 값 삭제, 그러면서 N의 절반의 카운트값의 이하인 value가 중앙값
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int g_N, g_cnt, g_min = 987654321, g_max = -987654321, g_input, g_mid;
ll g_sum;
map<int, int> g_nums;
pair<int, int> g_mostNum;

int main()
{
    cin >> g_N;
    g_mid = g_N/2;
    for(int inCnt = 0; inCnt < g_N; inCnt++)
    {
        cin >> g_input;
        if(g_nums.empty() || g_nums.find(g_input) == g_nums.end())
            g_nums.insert(g_input,1);
        else
        {
            g_nums[g_input]++;
        }
        g_min = min(g_min, g_input);
        g_max = max(g_max, g_input);
        g_sum += g_input;
    }
    for(auto num : g_nums)
    {
        if(g_mostNum.second < num.second)
            g_mostNum = num;
        
    }

    
    // 산술평균
    double avg = g_sum/g_N;
    cout << round(avg) << "\n";

    // 최빈값
    cout << (g_max - g_min) << "\n";

    

    return 0;
}