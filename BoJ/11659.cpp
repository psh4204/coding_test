/* 구간 합 구하기 4
https://www.acmicpc.net/problem/11659

수 N개가 주어졌을 때, 
i번째 수부터 j번째 수까지 합을 구하는 프로그램을 작성하시오.

입력
- N M (수의 개수, TC. 1~100,000)
- i j
- ... 

출력
- 각 구간 합

풀이
- 값을 받을 때 다 더하며 dp 만든 후
- i j 값 받았을 때, j의 총합 - (i-1)의 총합 하면 값 나옴
- i ~j의 합은 1~j의 합 - i~i-1의 합 과 같을 수 밖에 없다

*/
#include <bits/stdc++.h>
#define NUM_MAX 100001
using namespace std;
typedef long long ll;
int g_N, g_M, g_i, g_j;
vector<int> g_nums(NUM_MAX);
vector<ll> g_sums(NUM_MAX);

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> g_N >> g_M;
    // get input, set g_nums, g_sums
    for(int nIdx = 1; nIdx <= g_N; nIdx++)
    {
        cin >> g_nums[nIdx];
        g_sums[nIdx] = g_sums[nIdx-1] + g_nums[nIdx];
    }
    
    // get i ~ j sums
    while(g_M--)
    {
        cin >> g_i >> g_j;
        cout << (g_sums[g_j] - g_sums[g_i-1]) << "\n";
    }
    
    return 0;
}