/*https://www.acmicpc.net/problem/10709
기상캐스터

세로H, 가로W인 직사각형 모양의 도시 JOI.(km단위)
(y_cnt,x_cnt)좌표사용
1분에 1칸씩 동쪽으로 이동하는 구름을 가짐.
각 구역에 지금부터 몇분뒤 구름이 오는지 예측하는 프로그램 작성하기.

Input
- H W (갯수그대로)
- .과 C로된 array

Output
- 각 array에 언제 구름이뜨는지 보여준다. 안뜨면 -1
*/
#include <bits/stdc++.h>
using namespace std;
int _H, _W;
vector<vector<int>> _JOI;

int main()
{
    cin >> _H >> _W;
    for(int h_cnt = 0; h_cnt < _H; h_cnt++)
    {
        _JOI.push_back({});
        char pre_ch = 0;
        int pre_num = -1;
        for(int w_cnt = 0; w_cnt < _W; w_cnt++)
        {
            char in_ch;
            int num = -1;
            cin >> in_ch;
            if(in_ch == 'c')
            {
                num = 0;
            }
            else if(in_ch == '.' && pre_num >= 0)
            {
                num = pre_num + 1;
            }
            _JOI[h_cnt].push_back(num);
            pre_ch = in_ch;
            pre_num = num;
        }
    }

    for(auto h : _JOI)
    {
        for(auto w: h)
            cout << w << ' ';
        cout << '\n';
    }
    return 0;
}