/* https://www.acmicpc.net/problem/9251
LCS

최장 공통 부분 수열
- 두 수열이 주어지면, 두수열 모두 부분수열이 되는 수열중 가장 긴 것을 찾는 문제

ACAYKP
CACPAK
-> ACAK

입력
- 수열 두개 (알파벳 대문자. 최대 1000자)

출력
- LCS

풀이
- LIS 푼지 얼마됐다고 ㅠㅠ
- 근데 시간이 0.1초 ㄷㄷ (1000만번루프?)
- 첫번째 string에서 각 인덱스 번호 부여 -> 알파벳배열에 해당인덱스 삽입
- 두번째 string받은 후, 각 알파벳에 미리만든 알파벳 배열로 최적의 lis 값 추출
    - 근데 lis값을 만든 후, 어느인덱스에 카운트가 몇인지도 함께 넣어야함
    - 반복 
    <- **절대아님**

[Note]
- 2차원 DP의 대표문제 LCS
- 문자열 하나씩 읽어가며, 현재 최적해를 2차원 DP에 녹여내야하는게 이문제 핵심
- LIS와 같다면 '현재의 최적해'를 배열에 담는 것
- LCS는 현재 최적해인 연속된 '배열의 최대 수'를 계속 담아오는 것
- LCS(DP)배열은 2차원으로 만들되, 현재 배열보다 더 크게 만들어야함
- DP대각선위: 이전 최대LCS 값 + 1 (현재값을 포함시키기 위함)
- DP왼쪽or위: 이전 최대LSC 값 (현재값을 포함시키지 않으며 제일 큰LCS를 구하기위함)
- 이해안가면 손으로 직접 써보면서 ㄱㄱ
*/
#include <bits/stdc++.h>
using namespace std;
string g_A, g_B;
vector<vector<int>> g_lcs;

int main()
{
    cin >> g_A >> g_B;
    g_lcs.resize(g_A.size()+1, vector<int>(g_B.size()+1));
    
    for(int aIdx = 1; aIdx <= g_A.size(); aIdx++)
    {
        for(int bIdx = 1; bIdx <= g_B.size(); bIdx++)
        {
            if(g_A[aIdx-1] == g_B[bIdx-1])
                g_lcs[aIdx][bIdx] = g_lcs[aIdx-1][bIdx-1]+1;
            else
                g_lcs[aIdx][bIdx] = max(g_lcs[aIdx-1][bIdx], g_lcs[aIdx][bIdx-1]); 
        }
    }
    cout << g_lcs[g_A.size()][g_B.size()];
    return 0;
}