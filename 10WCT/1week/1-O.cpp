/*
https://www.acmicpc.net/problem/4375

2와 5로 나누어 떨어지지 않는 정수 n이 주어졌을때, 각 자리수가 모두 1로만 이루어진 n의 배수를 찾는 프로그램 작성

input
- 여러개의 테스트 케이스로 이루어져있음.

output
- 각 자리수가 모두 1로만 이루어진 n의 배수중 가장 작은 자리수를 출력

Try1
- 1, 11, 111, 1111 ... 중에서 나누어 떨어지는 최소값을 ret한다.
==> 시간초과

Try2
- 매ㅐㅐㅐ우 큰수는 longlong을 벗어나기 마련.
- 모듈러 공식
    - (a+b)%n = a%n + b%n
    - (a*b)%n = (a%n * b%n) %n
    - 리턴값을 모듈후 값으로 받을거면 그냥 온간데 모듈러박아서 값을 최적화하는데 써야함. 
- scanf()로 EOF 체크할 수 있음 (계속 되는 테스트)
    - scanf로 값을 받을 때 특별한 값을 받으면 -1(EOF), 이상한값을 받으면 0, 정상값을 받으면 1. 이렇게 나옴. 
*/
#include <bits/stdc++.h>
using namespace std;

int calc_ret(int n)
{
    int num_cnts =0;
    long long ll_ones = 0;
    while (1)
    {
        ll_ones = ll_ones * 10 + 1;
        ll_ones %= n; 
        num_cnts++;
        if((ll_ones % n == 0))
        {
            long long divide_val = ll_ones / n;
            if(ll_ones == divide_val*n);
                break;
        }
    }
    return num_cnts;
}

int main()
{
    int n = 0;
    while(scanf("%d", &n) != -1)
    {
        int ret = 0;
        ret = calc_ret(n);
        cout << ret << "\n";
    }
    return 0;
}