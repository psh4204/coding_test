/* https://www.acmicpc.net/problem/11050
이항계수 1

자연수 N과 K가 주어졌을때 (NK)를 구하는 프로그램 작성하기
- 이항계수가 뭐지?
- n개 중에서 k개를 고르는 조합의 수
- n! / k! (n-k)!
- 생각났다 ㅎㅎ
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll g_N, g_K, g_answer;

ll Factorial(ll num)
{
    if(num == 0)
        return 1;
    return num * Factorial(num-1);
}

int main()
{
    cin >> g_N >> g_K;
    g_answer = Factorial(g_N) / (Factorial(g_K) * Factorial(g_N-g_K));
    cout << g_answer; 
    return 0;
}