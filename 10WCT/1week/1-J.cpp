/*
https://www.acmicpc.net/problem/9375

오늘살이 신해빈씨

그녀는 매일 옷의 조합을 매우 다채롭게입으신답니다.
- 렌즈, 바지 를 입었으면 렌즈,바지,양말 혹은 다른것을 꼭 입어야한답니다.

Input
- 테스트케이스 T(0~100)
    - 옷의수 N (0~30)
    - 옷의 종류 (옷이름 옷종류. 같은 종류의 옷은 하루에 하나만 입을 수 있음)(n번반복)
    - 이걸 T번 반복

Output
- 각테스트케이스 마다 해빈씨가 알몸이 아닌 의상을 입을 수 있는 경우의 수를 구하기

Hint
- 2번의 테스케이스와 3개의 옷이라면: (hat), (turban), (sunglasses), (hat,sunglasses), (turban,sunglasses)

Try1~3
- 조합문제다.
    - 단 동일한 종류의 옷인지를 체크해야함.
- 옷을 받았을 때 sort를 해야하는데, 옷의 종류로 오름차순 sort를 하자.(초반에 확 겹쳐야 빠르게 끝날것 같음)
==> 시간초과

Try4
- 굳이 배열써서 값 받아올때 부터 타입나누고 복잡하게 할필요없이, map으로 일단 타입, 옷수 를 정하자
- 종류 별 경우의 수로 값을 받아온다: https://m.blog.naver.com/hawarjung2/222906522193
    - 종류별 경우의수 : A * B * C ...
    - 동시에 안일어 났을 때 경우의 수: A + B + C
    - 순열: nPr = n!/(n-r)!
    - 조합: nCr = n!/(n-r)!r!
*/
#include <bits/stdc++.h>
using namespace std;
int _T, _N = 0;

int main()
{
    cin >> _T;
    for(int tc_cnt = 0; tc_cnt < _T; tc_cnt++)
    {
        cin >> _N;;
        std::map<string, int> clothes;
        for(int cloth_cnt = 0; cloth_cnt < _N; cloth_cnt++) // Get Clothes
        {
            string name, type;
            cin >> name >> type;
            clothes[type] += 1;
        }
        // Do test
        int combi_cnt = 1;
        for(auto c_type: clothes)
        {
            combi_cnt *= (c_type.second+1); // 옷 타입별 옷갯수. 근데 안입는 경우 + 1.
        }
        cout << (combi_cnt -1) << "\n"; // 아예 안입는 거 제외
    }
    return 0;
}
