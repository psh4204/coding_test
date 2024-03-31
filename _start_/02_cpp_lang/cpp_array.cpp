#include <iostream>
#include <array>

using namespace std;

int main()
{
    array<int,5> scores = {50, 60, 70, 80, 90};
    int s = 0;

    for(int i = 0; i < scores.size(); i++)
    {
        s+=scores[i];
    }
    
    cout << "Mean score: " << s << endl;
}