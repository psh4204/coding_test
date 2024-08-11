/* https://www.acmicpc.net/problem/1992
쿼드트리

영상을 위(왼,오), 아래(왼,오) 로 4분할 하여 압축하는 방식.
위의 순서대로 0,1로 된 영상을 쿼드프리하여 나타내시오.

Input
- N: 영상 가로세로 픽셀 수 (1~64)
- 영상 arr

Output
- (왼위,오위,왼아래, 오아래) 이런식 // (0(0011)(0(0111)01)1)

Hints.
- 이전에 내가풀던방식: for내에서 4가지로 쪼개어 재귀로하는 방법
    - 상위문제를 하위문제로 쪼개어 재귀로 접근하는방식을 분할정복이라 부르더라.
- 깔끔하게 string과 배열, 그리고 인덱스만으로 코드풀이 가능

- (왼위/오위/왼아래/오아래)로 분할되어 재귀하며 움직인다.
*/
#include <bits/stdc++.h>
using namespace std;
int _N = 0;
vector<string> str_arr;

string z_check(int curr_y, int curr_x, int line_size)
{
    string ret;
    char first_char = str_arr[curr_y][curr_x];
    if(line_size == 1)
        return string(1, first_char); // string 생성자를 통한 char to string
    for(int y = curr_y; y < (curr_y + line_size); y++)
    {
        for(int x = curr_x; x < (curr_x + line_size); x++)
        {
            // 같은 글자가 연속 반복되는가? 
            // ==> 하나라도 안되면 해당 파트에서 분할정복 시작
            if(first_char != str_arr[y][x])
            {
                ret += "(";
                ret += z_check(curr_y, curr_x, line_size/2);
                ret += z_check(curr_y, curr_x + line_size/2, line_size/2);
                ret += z_check(curr_y + line_size/2, curr_x, line_size/2);
                ret += z_check(curr_y + line_size/2, curr_x + line_size/2, line_size/2);
                ret += ")";
                return ret; // <== 분할정복하려고 분할정복 1회 후 끝냄
            }
        }
    }
    return string(1, first_char);
}

int main()
{
    cin >> _N;
    for(int input_cnt = 0; input_cnt < _N; input_cnt++)
    {
        string usr_string;
        cin >> usr_string;
        str_arr.push_back(usr_string);
    }
    cout << z_check(0,0,_N) << '\n';
    return 0;
}