#include <bits/stdc++.h>
using namespace std;
int _tc;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> _tc;
    while(_tc--)
    {
        string answers;
        int score = 0, contScore = 0;
        cin >> answers;
        for(auto ans: answers)
        {
            if(ans == 'X')
            {
                contScore = 0;
            }
            else if(ans == 'O')
            {
                contScore++;
                score += contScore;
            }
        }
        cout << score << "\n";
    }
    return 0;
}