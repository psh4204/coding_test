/* https://www.acmicpc.net/problem/2828
사과담기 게임

N칸의 스크린. M칸의 바구니. 왼-오 이동가능. 시작은 0번째.
사과가 떨어지면 N칸의 상단 아무곳에서 떨어짐. 직선으로 떨어짐.
바구니를 사과의 위치에 두면 담을수 있음.
떨어지는 사과를 모두담으려할때 바구니의 최소이동거리를 구해라.

Input
- N M (1 <= M < N <= 10) (N 스크린개수, M 베스킷사이즈)
- J (사과의 개수)
- 사과가 떨어지는 위치(J만큼반복)

Output
- 사과를 담기위해 바구니가 이동해ㅑ야하는 거리의 최솟값 출력

Try1
- 배열,루프,카운트를 사용해서 구현해보자
- 입력받자마자 처리하자
*/
#include <bits/stdc++.h>
using namespace std;
int _screen, _basket_size, _apple_cnt, _move_cnt;
pair<int,int> _bsk_pos; // (왼,오)

void get_apple(int apple_pos)
{
    for(int mv_cnt = 0; mv_cnt < _screen; mv_cnt++)
    {
        if(apple_pos >= _bsk_pos.first && apple_pos <= _bsk_pos.second)
        {
            break;
        }
        _move_cnt++;
        if(apple_pos < _bsk_pos.first)
        {
            _bsk_pos.first--;
            _bsk_pos.second--;
        }
        else if(apple_pos > _bsk_pos.second)
        {
            _bsk_pos.first++;
            _bsk_pos.second++;
        }
    }
}

int main()
{
    cin >> _screen >> _basket_size >> _apple_cnt;
    _bsk_pos = {0, _basket_size-1};
    for(int a_cnt = 0; a_cnt < _apple_cnt; a_cnt++)
    {
        int apple = 0;
        cin >> apple;
        get_apple(apple -1);
    }
    cout << _move_cnt;
    return 0;
}