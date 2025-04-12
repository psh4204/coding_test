/* Four Squares
https://www.acmicpc.net/problem/17626

자연수 넷 혹은 그 이하의 제곱수로 N을 표현하는데 드는 최소 수를 구하라.
- 예: 26 = 5 1, 4 3 1

입력
- N (1~50,000)
출력
- 가지수

풀이
- 1부터 쭉 조합으로 4개의 숫자까지 만들어서 N을 만들수 있는지 확인해야함
    - (순열아니고 조합임)
    - 순열 = n!/(n-r)!
    - 조합 = n!/r!(n-r)!
    - 조합코드 짜면 답 나올거같은데?
- 이것도 근데 50000까지 조합찾으려면 한세월이라 규칙이 있을것으로 예상됨
    - 규칙 눈에 안보임. 그냥 하나 만들어서 체크하자 다시 체크하자
- 현재 Idx 보다 낮은 숫자는 기입안하는 조합재귀식을 만들자
교훈: 일단 풀어라. 그리고 ㅋㅋ 문제 잘읽어라.. ㅠㅠ
*/
#include <bits/stdc++.h>
using namespace std;
#define MAX_NUM_CNT 4
int g_N, g_minCnt= INT_MAX;

void CheckSum(int nIdx, int nCnt, long long sum)
{
    if(sum == g_N)
    {
        // cout << "nCnt: " << nCnt << ", sum:" << sum <<"\n"; // TEST
        g_minCnt = min(nCnt,g_minCnt);
        return;
    }
    if(nCnt == 4)
        return;
    long long squareN = nIdx*nIdx;
    while(g_minCnt >= nCnt && squareN + sum <=g_N)
    {
        CheckSum(nIdx, nCnt+1, squareN + sum);
        nIdx++;
        squareN = nIdx*nIdx;
    }
}

int main()
{
    cin >> g_N;
    CheckSum(1,0,0);
    cout << g_minCnt;
    return 0;
}