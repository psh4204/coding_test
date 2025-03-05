/* https://www.acmicpc.net/problem/2775
부녀회장이 될테야.

a층 b호 인원 = a-1층 1호~b호 인원의 합.

k층 n호에는 몇명이 살고있는지 출력하기. (1~ (k,n) ~ 14)
참고: 0층부터 i호가 있으며, i호엔 i명이 삼.

입력:
- TC
- k c
- k c
- ... (TC 만큼)

출력:
각거주민수 출력 \n

풀이:

1층 3호실 = 6
- 1 3 6
- 1 2 3

2층 3호실 = 10
- 1 4 10
- 1 3 6
- 1 2 3

[풀이노트]
table (14*14 = 196)
- 1 4 10 20 35 56 ...
- 1 3 6  10 15 21 28 36 45 55 ...
- 1 2 3  4  5  6  7  8  9  10  11 12 13 14

... 14 * 14 DP 테이블 만들어 놓고, 인덱스로 뽑아쓰자.

*/
#include <bits/stdc++.h>
using namespace std;
int g_TC, g_k, g_n;
vector<vector<int>> g_APT(15, vector<int>(15,0));

void MakeAPT()
{
    // 0층 init 후
    for(int zeroRoom = 1; zeroRoom <= 14; zeroRoom++)
        g_APT[0][zeroRoom] = zeroRoom;

    for(int k = 1; k <= 14; k++)
    {
        for(int n = 1; n <= 14; n++)
            g_APT[k][n] = g_APT[k-1][n] + g_APT[k][n-1];
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> g_TC;
    MakeAPT();

    while(g_TC--)
    {
        cin >> g_k >> g_n;
        cout << g_APT[g_k][g_n] << "\n";
    }

    return 0;
}