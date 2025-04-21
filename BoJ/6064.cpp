/* 카잉 달력
https://www.acmicpc.net/problem/6064

M, N 이하의 자연수 두개 x,y 로 <x:y> 표시
- 시초의 해 <1:1>
- 두번째 해 <2:2>
- x'(다음x) = x(현재x) < M ? x+1: 1
- y'(다음y) = y(현재y) < N ? y+1: 1 
- x y 가 M N 이 되면 마지막 해
- 유효하지 않은 x y면 -1 리턴
- 즉, 현재 x,y가 각 M,N 보다 커질때 1이 됨
    - 결론: 
    - 그 해와 각 M,N에서 더큰 쪽을 중심으로 모듈러
    - 각 0 나오면: 각 M, N 리턴
    - 다르면 나머지 값 리턴
- x, y를 받았을때 모듈러로 각 나머지값 이 나오는 해를 구하면 됨

M N x y 가 주어지면 x y 가 몇번째 해인지 구해보라

풀이
- M N으로 모듈러 했을 때 잉카달력식 모듈러를 했을때, x y가 나오는 해를 구해야함
- M과 N의 더블포인터인가
- 일단, 마지막 해를 찾은 후에 탐색을 해야할 것으로 보임
    - 최소 공배수가 마지막 해 (LCM)
- 0,0 ~ LCM 까지 탐색 해야함
- M, N 중에서 작은 것을 중심으로 x, y값에 비교하며 탐색 ㄱㄱ

TODO:최소공배수, 최대공약수 스터디 (API 만 써서 항상 까먹음)

1
40000 40000 40000 39999
-1

어렵다 슬슬..
*/
#include <bits/stdc++.h>
using namespace std;
int g_M, g_N, g_x, g_y, g_TC, g_lcm;

int gcd(int a,int b) // a > b
{
    int r;
    while(1)
    {
        int r = a%b;

        if(r==0)
            return b;
        a = b;
        b = r;
    }
}

long long lcm(int a,int b)
{
    return a*b/gcd(a,b);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> g_TC;
    while(g_TC--)
    {
        long long year = 0;
        cin >> g_M >> g_N >> g_x >> g_y;
        if(g_M > g_N)
        {
            int temp = g_M;
            g_M = g_N;
            g_N = temp;
            temp = g_x;
            g_x = g_y;
            g_y = temp;
        }
        g_lcm = lcm(g_N, g_M);
        year = g_x;
        while(year <= g_lcm)
        {
            long long subX = year, subY = year;
            if(g_M < year)
            {
                subX = year % g_M;
                subX = subX == 0? g_M:subX;
            }
            if(g_N < year)
            {
                subY = year % g_N;
                subY = subY == 0? g_N: subY;
            }
            
            if(subX == g_x && subY == g_y)
                break;
            else
                year += g_M;
        }
        if(year > g_lcm)
            cout << -1 << "\n";
        else
            cout << year << "\n";
    }
    return 0;
}