#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v1;
    vector<int> v2(10); // v2[0] ~ v2[9]
    vector<int> v3(10,1); // v3[0]부터 1,1,1,1,1...
    for(int i = 0; i < v3.size() ; i++)
    {
        cout << v3.at(i) << ", ";
    }
    cout << endl;
    vector<int> v4{10,20,30,40,50};
    // Data push
    // v1.push_back(10);
    // v1.push_back(20);
    // v1.push_back(30);
    // v1.push_back(40);
    
    vector<int> v5 = v4; // v5에 v4 깊은복사.(데이터 자체를 들고오는 복사)
    vector<int> v6(v5); // v6에 v5 깊은복사
    vector<int> v7(v4.begin(), v4.begin() + 3); // 기존 벡터의 일부원소만을 가져와 생성하고 싶을때. 
                                                // v4시작부터 v4시작에서 +3번째 전까지.
                                                // 10,20,30
    for(int i = 0; i < v7.size() ; i++)
    {
        cout << v7.at(i) << ", ";
    }
    cout << endl;

    vector<vector<int>> mat1(2, vector<int>(3)); // 2차원 vector. 2행 3열. 
    vector<vector<int>> mat2(2, vector<int>(3,1)); // 2차원 vector. 2행 3열. 1로 가득찬.
    vector<vector<int>> mat3{
        {1,2,3},
        {4,5,6}
    }; // 2차원 vector. 2행 3열. 1로 가득찬.
    
    /*
        1, 2, 3, 
        4, 5, 6,
    */
    for(int r = 0; r < mat3.size(); r++)
    {
        for(int c = 0; c < mat3[r].size() ; c++)
        {
            cout << mat3[r][c] << ", ";
        }
        cout << endl;
    }

    return 0;
}