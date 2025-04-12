/* 2*N 타일링
2xN 크기의 직사각형안에 1x2, 2x1 타일을 채우는 방법의 수를 구하시오
(1~N~1,000)

입력
- N
출력
- 방법의 수를 10,007 모듈러 값 출력

풀이
- 2x1, 1x2로 만드는 순열
- 세로 x 가로 안에 채울수 2x1, 1x2를 채울 수 있는 재귀를 만들어야함
- 채울때 실제 그림그리듯 pair문 배열을 활용하여 '이전값을 토대'로 '무슨블럭을 넣어야하는지 판단'해야함
    - 아! 1x2 블럭 카운트만 따로 만들면 되네

풀긴 했으나 시간초과 남
- 최적화 뭐로하지~
- inline 넣었음 (부적)
- ㅋㅋㅋ 생각해보니 가로블럭 두개 쌓는거 한번에 해도 되네
- 그럼 1과 2의 순열로 카운트 세는거네
- 시간초과 계속나는데 흠.. dp를 쓸만한게 있나 (쓸 수가 없음. 이미 if문으로 다 걸러짐)
- 보통 이런건 수학식으로 풀었던거 같은데
    - 1:1 2:2 3:3 4:5 5:8 6:13 7:21 8:34
    - 이런..
    - 2부터 n-1, n-2 의 합으로 구해지네
    - 이거 완전 유사 피보나치잖아 ;;
*/
#include <bits/stdc++.h>
using namespace std;
#define MODUL 10007
#define MAX_SERO 2
typedef long long ll;
ll g_cnt;
int g_N;
vector<ll> g_nums(1001);

int main()
{
    cin >> g_N;
    g_nums[1] = 1; g_nums[2] = 2;
    
    for(int nIdx = 3; nIdx <= g_N; nIdx++)
    {
        g_nums[nIdx] = g_nums[nIdx-1] + g_nums[nIdx-2];
        g_nums[nIdx] %= MODUL;
        // cout << nIdx << " " << g_nums[nIdx] << " << \n"; //TEST
    }
    cout << g_nums[g_N];
    return 0;
}