/* https://www.acmicpc.net/problem/11650
좌표 정렬하기

(x,y)좌표 점 N개가 주어진다.
x오름차순, x가같으면 y오름차순으로 정렬.

입력
- N (1~100k)
- x y (리스트. -100k ~ 100k)
출력
- 정렬된 값 리스트
*/
#include <bits/stdc++.h>
using namespace std;
struct point_t
{
    int x;
    int y;
};
int _N;
vector<point_t> _points;
bool compare(const point_t& first, const point_t& second)
{
    if(first.x < second.x)
        return true;
    else if(first.x > second.x)
        return false;
    else
    {
        if(first.y < second.y)
            return true;
        else
            return false;
    }
}

int main()
{
    cin >> _N;
    for(int n_idx = 0; n_idx < _N; n_idx++)
    {
        point_t point;
        cin >> point.x >> point.y;
        _points.push_back(point);
    }
    sort(_points.begin(), _points.end(), compare);
    for(auto p: _points)
        cout << p.x << " " << p.y << "\n";
    return 0;
}