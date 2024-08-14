/* https://www.acmicpc.net/problem/3474
프로페서 현우

아주 똑똑하신 현우님께서 코린이들의 머리속을보고 경약을 금치못했다.
자연수 N이 주어지면 N!의 오른쪽 끝의 0의 개수를 알려주기로 한다.

Input
- 테스트 케이스 수 T
- 정수 N들.. (N!)

Output
- 각 줄 N!의 오른쪽 끝의 0의 개수 출력

Try1.
- 음.. 이런게돼?
- 재귀를 써서 보여주기엔.. 값이 너무 커질거같은데
- 재귀를 써버리면 N의 범위가 1~ 1,000,000,000... 1M이고 1초안에 다 못보여줄거같음.
- 이럴땐 보통 logN이 나오는 걸 찾아서 풀었는데 어케할까
- 첫째자리 수랑 해당 값이랑 곱해서 첫째자리수가 0이 몇번나온지 카운트하고, 0을 없애가면 될거같음.

Try2. with hint
- 팩토리얼 값 내에 10의 갯수를 찾는 문제.
- 이 아이디어로 갔을 때 팩토리얼 내에 각 2와 5의 개수를 구한 후, min 값을 구하면 된다.
    - ... 외우자.
    - 이런 식으로 문제가 나오면 그냥 던져야겠다 진짜 ㅋㅋㅋ
- 그냥 완전 수학식인데

Try3.
- 그렇다면.. ㅋㅋㅋ 5의 배수 개수만 구해도 되지않음? 어차피 2보다 5의배수가 훨씬 양이 적은데.. ㅇㅇ 지금 TC도 그렇다고 뜨네
- 단 10보다는 큰 경우에만 해당하겠지?

Try4.
- ... 틀렸다네

Try5.
- 시간초과
- 아니.. 왜 계속 시간초과나냐 진짜 개짜증나네

아니 이게 먼데 시간초과랑 관련있음?
ios_base::sync_with_stdio(false);
cin.tie(NULL); 
cout.tie(NULL);

*/
#include <bits/stdc++.h>
using namespace std;
int _T = 0;
int _usr_int = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);
    
    cin >> _T;
    for(int in_cnt = 0; in_cnt < _T; in_cnt++)
    {
        int two_cnt = 0;
        int five_cnt = 0;
        cin >> _usr_int;
        for(int t = 2; t <= _usr_int; t*=2)
            two_cnt += _usr_int/t;
        for(int f = 5; f <= _usr_int; f*=5)
            five_cnt += _usr_int/f;
        
        cout << min(two_cnt,five_cnt) << "\n";
    }

    return 0;
}