/* https://www.acmicpc.net/problem/4153
직각삼각형인지 체크 후에 "right", "wrong"을 출력하라.
*/
#include <bits/stdc++.h>
using namespace std;
bool isRun = true;

int main()
{
    do{
        vector<long long> numList(3,0);
        cin >> numList[0] >> numList[1] >> numList[2];
        if(numList[0] == 0 && numList[1] == 0 && numList[2] == 0)
        {
            isRun = false;
            break;
        }

        sort(numList.begin(), numList.end());
        // cout << "TEST::: " << numList[0] <<" "<< numList[1] <<" " << numList[2] << "\n";
        if(pow(numList[2],2) == pow(numList[1],2) + pow(numList[0],2))
            cout << "right\n";
        else
            cout << "wrong\n";
    }while(isRun);
    return 0;
}