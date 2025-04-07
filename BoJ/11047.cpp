/* 동전 0
https://www.acmicpc.net/problem/11047

N종류 동전의 합을 K로 만들려하는데,
이때 필요한 동전 최소개수는?

입력
- N K (1~N~10, 1~K~100,000,000)
- N개의 동전가치(오름차순으로 나옴)

풀이
- 동전 종류를 조합하여 최소한의 동전개수로 K를 만들어라
- 동전종류를 뒤집은 후에 조합을 찾아야할것으로 보임
- 큰동전부터 하나씩 카운트하며 조합찾기
- 아. 값이 오름차순이고 첫값 1, 그후 다른값은 배수라는게 모듈러 쓰라는 뜻이었구나
*/
#include <bits/stdc++.h>
using namespace std;
int g_N, g_K;
long long g_minCnt = 0;
vector<int> g_nums;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> g_N >> g_K;
    for(int inCnt = 0; inCnt < g_N; inCnt++)
    {
        int input = 0;
        cin >> input;
        if(input <= g_K)
            g_nums.push_back(input);
    }
    sort(g_nums.begin(), g_nums.end(), greater<int>());
    for(int nIdx = 0; nIdx < g_nums.size(); nIdx++)
    {
        // cout << "g_minCnt: " << g_minCnt << ", g_nums[nIdx]" << g_nums[nIdx] << ", g_K: " << g_K << "\n"; 
        if(g_K == 0)
            break;
        g_minCnt += g_K/ g_nums[nIdx];
        g_K %= g_nums[nIdx];
    }
    cout << g_minCnt;
    return 0;
}
