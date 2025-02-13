/*https://www.acmicpc.net/problem/15829
Hashing

문자열 해시변환 함수 만들기.
시그마로 된 식이 나옴.

[입력]
문자열길이 L (1~5, 1~50)
문자열 (영어소문자)

[출력]
해시값

[풀이]
서로소: 최대공약수가 abs(1)뿐인 수.
mod M: 모듈러연산(큰소수를 통한 연산)
-> r과 M은 서로서여야 맞음. 하지만 그 부분을 직접 지정해줌
--> r = 31, M = 1234567891

문자열의 수를 각각 특정숫자로 거듭제곱한 후 더한다.
-> a*31^0 + b*31^1 ... x*31^N-1
그리고 이에 모듈러 연산을 한다. (오 ~이과~)
-> (거듭제곱합) mod 1234567891
-> mod = %
-> (거듭제곱합) % 1234567891

[부분정답]
- 오? Small (1~5) 는 다 맞춤
- 크기가 큰 녀석들은 모듈러 연산(mod)가 힘든가??
- 아! 모듈러연산은 시그마할때 걍 계속 해줘도 됐었음. 해보자..!!
- 아!! +,* 연산시 모듈러 온간데 다 넣어도 전부 같은 결과임. --> 100 점
    - 사칙연산 중 +,- * 만 이 규칙을 따름. 
*/
#include <bits/stdc++.h>
using namespace std;
#define MM 1234567891
#define rr 31
string g_input;
long long g_hash, g_L;

int main()
{
    cin >> g_L >> g_input;
    for(int loopCnt = 0; loopCnt < g_L; loopCnt++)
    {
        long long sumValue = g_input[loopCnt]-'a'+1;
        for(int subCnt = 0; subCnt < loopCnt; subCnt++)
        {
            sumValue *= rr;
            sumValue %= MM;
        }
        g_hash += sumValue;
        g_hash %= MM;
    }
    
    cout << g_hash;
    return 0;
}