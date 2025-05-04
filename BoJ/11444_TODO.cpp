/* 피보나치 수 6
https://www.acmicpc.net/problem/11444

피보나치수열, 현재값이 앞의 두수 합이 되는 수열
- 0 번째는 0, 1번째는 1이다

N번째 피보나치 수를 구하라 (0~1,000,000,000,000,000,000)

입력
- n

출력
- 1,000,000,007로 모듈러 한 N번째 피보나치 수를 구한다

풀이
- ㅋㅋㅋ 못풀겠다! 답안보고 한다 그냥.. 그냥 수학공식이잖아.. ㅠㅠ (문과는 Fail)

[Note]
- 다음의 행렬의 거듭제곱으로 피보나치 수를 풀 수 있음
->  M^1 =   ((1 1))
            ((1 0))
- 여기서 좌측하단의 값이 구하고자 하는 값


TODO: 그냥 나중에 풀자~ ㅋㅋㅋ 하아
*/

#include <bits/stdc++.h>
using namespace std;
#define MODL 1000000007
typedef long long ll;

ll g_N;
vector<vector<int,int>> g_nums = {{1,1},{1,0}};

ll fibo(int n)
{

}

int main()
{
    cin >> g_N;

    return 0;
}