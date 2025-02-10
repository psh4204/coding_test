#include <bits/stdc++.h>
using namespace std;
vector<int> _alphabets(26,-1);
string _S;

int main()
{
    cin >> _S;
    for(int sCnt = 0; sCnt < _S.length(); sCnt++)
    {
        int alphaNum = _S[sCnt]-'a';
        if(_alphabets[alphaNum] == -1)
            _alphabets[alphaNum] = sCnt;
    }
    for(auto alpha: _alphabets)
        cout << alpha << " ";
    return 0;
}