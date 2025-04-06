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
    - 최빈값은 hash map . 근데 동일한 최빈값이 있다면 두번째로 작은거로 출력
    - 최빈값을 구하면서, 중앙값을 구해보자
    - 최빈값을 찾으며, N의 절반의 카운트값의 이하인 value가 중앙값
*/
#include <bits/stdc++.h>
#define MAX 987654321
#define MIN -987654321
using namespace std;
typedef long long ll;
int g_N, g_cnt, g_input,        \
    g_min = MAX, g_max = MIN,   \
    g_midCnt, g_midNum,         \
    g_mostCnt; // 최빈값 중 두번째로 작은 값 체크용 카운트
bool g_isIniteMid = false;
ll g_sum;
map<int, int> g_nums;
pair<int, int> g_mostNum;

int main()
{
    cin >> g_N;
    g_midCnt = g_N/2 + 1; // N이 홀수이기때문에 중앙값은 항상 이렇게 해야한다
    for(int inCnt = 0; inCnt < g_N; inCnt++)
    {
        cin >> g_input;
        if(g_nums.empty() || g_nums.find(g_input) == g_nums.end())
            g_nums.insert({g_input,1});
        else
        g_nums[g_input]++;
        g_min = min(g_min, g_input);
        g_max = max(g_max, g_input);
        
        g_sum += g_input;
        // cout << "g_sum" << g_sum << endl; // <<TEST>>
    }
    for(auto num : g_nums)
    {
        if(g_mostNum.second < num.second)
        {
            g_mostNum = num;
            g_mostCnt = 1;
        }
        else if(g_mostNum.second == num.second && g_mostCnt < 2)
        {
            g_mostNum = num;
            g_mostCnt++;
        }
        if(g_isIniteMid == false && g_midCnt - num.second <= 0)
        {
            g_isIniteMid = true;
            g_midNum = num.first;
        }
        g_midCnt -= num.second;
    }

    // 산술평균 <- 오답
    long double avg = (long double)g_sum/g_N;
    avg = round(avg);
    // cout << g_sum << "/" << g_N << "= " << avg << endl; // <<TEST>>
    cout << (int)avg << "\n";

    // 중앙값 
    cout << g_midNum << "\n";

    // 최빈값 <-오답
    cout << g_mostNum.first << "\n";

    // 범위
    cout << (g_max - g_min) << "\n";
    
    return 0;
} 