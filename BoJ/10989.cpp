/* https://www.acmicpc.net/problem/10989
수정렬하기
N개의 수가 주어졌을때 오름차순 정렬하기

제한시간    : 5초
메모리제한  : 1024*1024*8
최대숫자수  : 10,000,000 
최대값      : 10,000  (1Byte)

단순 sort로 하기엔 값이 너무 많음
- 0부터 10,000 까지 배열 만들어서 카운트하는식으로 만들자!
*/
#include <bits/stdc++.h>
using namespace std;
int g_N, g_input;
vector<int> g_nums(10001,0);

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> g_N;
    while(g_N--)
    {
        cin >> g_input;
        g_nums[g_input]++;
    }
    for(int num = 0; num <= 10000; num++)
    {
        for(int n_cnt = 0; n_cnt < g_nums[num]; n_cnt++)
            cout << num <<"\n";
    }
    return 0;
}