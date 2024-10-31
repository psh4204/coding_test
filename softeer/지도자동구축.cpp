/* 지도 자동 구축
지도 자동 구축에 필요한 알고리즘은 정사각형의 점들을 그림과같이 나열해서 만드는 방식.
N단계로 갔을때의 점 개수를 구하시오.
사각형 정 중앙에 점을 추가하는 방식으로 크기가 커짐.

입력
- 단계 (1~15)

출력
- 점의 개수

풀이
- 규칙. N단계의 한라인 점 개수  = N-1단계의 점 * 2 -1. 
*/

#include<bits/stdc++.h>
using namespace std;
int _N, _line = 2;
int main(int argc, char** argv)
{
    cin >> _N;
    for(int n_cnt = 0; n_cnt < _N; n_cnt++)
    {
        _line = _line * 2 -1;
    }
    cout <<  _line * _line;
    return 0;
}