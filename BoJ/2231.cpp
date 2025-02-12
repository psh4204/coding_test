/* https://www.acmicpc.net/problem/2231
분해합

N의 분해합 = N + N의 각자리수의 합 = 분해합 M
생성자 = 분해합 M을 만들 수 있는 숫자.

자연수 N이 주어지면, 가장작은 생성자를 구해라.

[입력]
- N (1~1,000,000)

[출력]
- 가장작은 생성자

[풀이]
규칙을 찾아보자.
- 생성자는 해당 자연수보다 반드시 작다
- 음.. 생각해보니 루프가 (100만번 * 10)밖에 안되는데? 그냥 1부터 돌리자.


[정답!을 맞추긴했는데 많이 느리넹..]
- 음~ 사람들은 String으로 분해합 안만들고, /10 으로 만드는구나!
- 20ms 에서 4ms 로 줄음. 역시 클래스 안걸치고 수식으로 하는게 최고긴 하구나.
*/

#include <bits/stdc++.h>
using namespace std;
int _N, _maker;

int main()
{
    cin >> _N;
    for(int nCnt = 1; nCnt < _N; nCnt++)
    {
        int bunhehap = nCnt;
        int subNCnt = nCnt;
        while(subNCnt)
        {
            bunhehap += subNCnt%10;
            subNCnt/= 10;
        }
        if(_N == bunhehap)
        {
            _maker = nCnt;
            break;
        }
    }
    cout << _maker;
    return 0;
}