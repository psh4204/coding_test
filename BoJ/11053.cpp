/* 가장 긴 증가하는 부분 수열
https://www.acmicpc.net/problem/11053

수열이 주어졌을때
수열내에서 가장길게 증가하는 부분수열의 길이를 구하라
10 20 10 30 20 50
-> '10' '20' 10 '30' 20 '50'

풀이
- 와 개어렵다
- 3 1 2 3 10 1 2 4 5 1 2 6 -> 1 2 3 4 5 6
- 쌩무식하게 ㄱㄱ해보자... 안됨

[NOTE]
- (LIS 결론!) 각 각 dp[현재-인덱스]는 딱 현재까지의 최대 증가수열의 길이를 가지는 성질로 풀어야함
- Value와 Count로 LIS를 풀수있음 [비교-과거인덱스] [현재-인덱스]
    - Value로는 단순히 현재값이 비교값보다 큰지 작은지 볼 수 있음 (단순히 값이 더큰가)
    - Count는 현재 최대 카운트가 비교카운트보다 큰지 작은지 볼 수 있음
        - 현재 최대 카운트가 비교카운트보다 작을때, 최대카운트는 비교카운트로 갱신
        - 최대카운트 + 1해서 현재 카운트 갱신
        - 즉, Count배열은 현재-인덱스를 포함하면서 가장 긴 수열의 길이를 가짐

12
3 1 2 3 10 1 2 4 5 1 2 6

*/
#include <bits/stdc++.h>
using namespace std;
int g_N, g_maxCnt;
vector<int> g_nums;
vector<int> g_lis;

int main()
{
    cin >> g_N;
    g_nums.resize(g_N);
    g_lis.resize(g_N);

    for(int numIdx = 0; numIdx < g_N; numIdx++)
    {
        cin >> g_nums[numIdx];
    }

    for(int target = 0; target < g_N; target++)
    {
        for(int prev = 0; prev <= target; prev++)
        {
            if(g_nums[prev] < g_nums[target] && g_lis[prev] > g_lis[target])
            {
                g_lis[target] = g_lis[prev];                
            }
        }
        g_lis[target] += 1;
        g_maxCnt = max(g_lis[target], g_maxCnt);
    }

    // //TEST
    // for(auto cnt: g_lis)
    //     cout << cnt << " ";
    // cout << "\n";
    cout << g_maxCnt;
    return 0;
}