#include <iostream>

using namespace std;

int main()
{
    int scores[5] ={50, 60, 70, 80, 90};
    int s = 0;
    // sizeof(): 해당 자료형 크기. 배열은 4Bytes. 배열전체크기 현재 20. 20/5로 배열갯수 확인함.
    int sz = sizeof(scores)/sizeof(scores[0]);
    float m = 0;

    for(int i = 0; i < sz; i++)
    {
        s += scores[i];
    }

    m = (float) s / sz;

    cout << "Mean score: " << m << endl;
}