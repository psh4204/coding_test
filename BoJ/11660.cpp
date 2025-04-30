/* 구간합 구하기 5
https://www.acmicpc.net/problem/11660

숫자가 채워진 NxN 배열이 있다
(x1,y1) ~ (x2,y2)까지의 합을 구하는 프로그램 작성하기

입력
- N(배열한면크기 1~1024) M(1~100,000)
- 배열
- x1 y1 x2, y2
- ...

출력
- M개의 x1y1~x1~y2 의 합

풀이
- 단순무식하게 풀면 금방할수 있을듯
- 근데 M을 100,000을 구해야하는데, 
    배열최대 너비는 1,000,000 일테고
    그럼 최대 걸리는 시간은 100,000,000,000
- 옵티마이징 어케하지 .. 
- 아~ 값 input 받을때 값을 점점 더해가며 받고
    그 값을 구할때 마지막지점에서 해당지점을 빼면 합이 나올거같은데
    > 1  2  3  4  5
    > 1  3  6  10 15
    > (1~1): 1
    > (3~3): 6-3 = 3
    > (2~5): 15-1 = 14
    > (3~4): 10-3 = 7
- 즉, 구하려는 칸에 있는 총합 빼기 시작칸 전칸을 빼면 쉽게 sum을 구함
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int g_N, g_M;
vector<vector<ll>> g_nums(1025, vector<ll>(1025));

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> g_N >> g_M;
    for(int inX = 1; inX <= g_N; inX++)
    {
        for(int inY = 1; inY <= g_N; inY++)
        {
            cin >> g_nums[inX][inY];
            g_nums[inX][inY] += g_nums[inX][inY-1];
        }
    }
    for(int pIdx = 0; pIdx < g_M; pIdx++)
    {
        int x1, y1, x2, y2;
        ll sum = 0;
        cin >> x1 >> y1 >> x2 >> y2;
        for(int xIdx = x1; xIdx <=x2; xIdx++)
        {
            sum += g_nums[xIdx][y2] - g_nums[xIdx][y1-1];
        }
        cout << sum << "\n";
    }

    return 0;
}