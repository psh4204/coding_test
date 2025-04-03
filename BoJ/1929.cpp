/* 소수 구하기
https://www.acmicpc.net/problem/1929

M이상 N이하 소수 구하는 프로그램 작성 (1~1,000,000)

입력
- M N

출력
- 소수 \n

풀이
- 소수 미리 만들어서 출력: 시간초과
    - 각 소수값을 2부터 N까지 한번씩 계산 = 소수개수 * 1,000,000
- 에라토스테네스의 체 라는 알고리즘을 사용해야함
    - '특정 수의 배수를 모두 없애주며 구하는 알고리즘'
    - 이게 제일 빠르다고하네~ (빅오 nloglogn)
    - 정말 큰 소수까지 구할때 차이가 벌어짐 (해보니까 압도적으로 빠르네;;)
*/
#include <bits/stdc++.h>
using namespace std;
int g_M, g_N;
vector<int> g_sozus; //소주땡긴다

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> g_M >> g_N;
    g_sozus.resize(g_N+1, 1);
    g_sozus[0] = 0; g_sozus[1] = 0; 
    for(int num = 2; num <= g_N; num++)
    {
        if(g_sozus[num] == 0)    continue;
        for(int baesuNum = num+num; baesuNum <= g_N; baesuNum+=num)
            g_sozus[baesuNum] = 0;
    }
    
    for(int num = g_M; num <= g_N; num++)
    {
        if(g_sozus[num])
            cout << num << "\n";
    }
    
    return 0;
}