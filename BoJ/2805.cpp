/* 나무 자르기
https://www.acmicpc.net/problem/2805

날아다니는 전기톱으로 나무를 밀렵할거다
전기톱의 나는 높이 H를 설정하면 H높이만큼 자른다
- 예: H: 15. 나무 17 15 10 20 -> 자르면 -> 15 15 10 15 -> 자른 나무길이 2 와 5 = 7만큼가져감

나무를 최소 M만큼 자를 수 있을 H 최대값을 구해보자

입력
- 나무개수N(1~1,000,000), 필요나무길이M(1~2,000,000,000)
- 나무길이들

출력
- 최대 H

풀이
- M을 가져가기 위한 최대 H값을 구해야함
- 이분탐색 문제로 보임
    - 0에서 가장 높은 나무높이로 mid 값 설정
    - 나무 자른 후 너무 나무가 많으면 L값 Up
    - 나무가 너무 적으면 R값 Up 
- 최대 H값을 구하라는 것을 보아하니, M값이 안나오는 경우가 있나봄
    - (중요)M값이 최소일때, H 중에서 가장 큰 H값을 구하면 될 듯
*/
#include <bits/stdc++.h>
using namespace std;
int g_N, g_H, g_lH, g_rH, g_midH;
long long g_M, g_cutSum = LONG_LONG_MAX;
vector<int> g_trees;

int main()
{
    cin >> g_N >> g_M;
    for(int inIdx = 0; inIdx < g_N; inIdx++)
    {
        int treeLen;
        cin >> treeLen;
        g_trees.push_back(treeLen);
    }
    sort(g_trees.begin(), g_trees.end(), greater<int>());
    g_rH = g_trees[0];
    do
    {
        long long cutSum = 0;
        g_midH = (g_lH + g_rH)/2;
        // cout << "g_midH: " << g_midH << "\n"; // TEST
        for(auto treeLen: g_trees)
        {
            if(treeLen <= g_midH)
                break;
            cutSum += treeLen - g_midH;
        }
        // 자른 나무길이가 M을 넘기면서, 최소값을 가질때, H값의 최대값을 받아낸다. 
        if(cutSum >= g_M)
        {        
            // 동시에 왼쪽커서 이동시켜 H값 증가
            g_lH = g_midH +1;
            if(g_cutSum < cutSum)
                continue;
            g_cutSum = cutSum;
            g_H = max(g_midH, g_H);
        }
        else
        {
            g_rH = g_midH -1; // 자른 나무를 덜 베게, 
        }
    } while (g_lH <= g_rH);
    cout << g_H;
    return 0;
}
