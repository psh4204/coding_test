/* 암기왕
https://www.acmicpc.net/problem/2776

연종이가 모든 숫자를 기억하는 능력이 있다
누군가 어떠한 숫자가 있는지 물어봤을때 연종이는 이에 대답해야한다

입력
- T (테스트케이스 개수)
- N (외울 숫자개수 1~1,000,000)
- 숫자들
- M (문제낼 숫자개수 1~1,000,000)
- 숫자들
- ... 

출력
- 있으면 1\n, 없으면 0\n

풀이
- 해시로 풀수있지만 이분탐색을 사용해본다.

*/
#include <bits/stdc++.h>
using namespace std;
int g_T, g_N, g_M;

int BinarySearch(int target, vector<int> & nums)
{
    int l = 0, r = nums.size()-1;
    int mid;
    while(l <= r)
    {
        mid = (l+r)/2;
        if(target > nums[mid])
            l = mid +1;
        else if(target < nums[mid])
            r = mid -1;
        else
            return mid; // 찾으면 인덱스를 리턴.
    }

    return -1; // 못찾으면 -1
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> g_T;

    while(g_T--)
    {
        int rNum, quiz;
        vector<int> remembers;
        cin >> g_N;
        while(g_N--)
        {
            cin >> rNum;
            remembers.push_back(rNum);
        }
        sort(remembers.begin(), remembers.end());
        cin >> g_M;
        while(g_M--)
        {
            cin >> quiz;
            if(BinarySearch(quiz, remembers) == -1)
                cout << 0 << "\n";
            else
                cout << 1 << "\n";
        }
    }
    return 0;
}