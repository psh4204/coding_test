/*https://www.acmicpc.net/problem/2609
최대공약수와 최소공배수
두 자연수를 받아 최대공약수와 최소공배수를 구하는 프로그램을 출력하시오.

(공식)
유클리드 호제법을 통한 최대공약수 구하기.
= a와 b를 번갈아가며 %연산 -> 마지막 0이랑 나누는 수가 최대공약수.

최소공배수 
= 두자연수의 곱/ 최대공약수.

*/
#include <bits/stdc++.h>
using namespace std;
int g_A, g_B, g_gcd;

int GetGCD(int a, int b)
{
    if(a == 0)
        return b;
    else if(b == 0)
        return a;

    if(a > b)
        return GetGCD(a%b, b);
    else
        return GetGCD(b%a, a);
}

int GetLCM(int a, int b, int gcd)
{
    return a*b/gcd;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> g_A >> g_B;
    g_gcd = GetGCD(g_A, g_B);
    cout << g_gcd << "\n" << GetLCM(g_A, g_B, g_gcd);
    return 0;
}
