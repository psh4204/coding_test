#include <iostream>

using namespace std;

// https://www.acmicpc.net/problem/2309

// 100 이하 정수 9개
// 이중의 합이 100이 되는 7개의 수를 찾는 문제
// 1. 7개의 숫자 중에 2개의 숫자를 없애가며 도합 100인 숫자를 탐색
// 2. 찾는다면 200으로 표시
// 3. sort 후 프린트


void swap_c(int a[], int b[])
{
    int buff = *a;
    *a = *b;
    *b = buff;
}

int partition(int data[], int left, int right)
{
    int pivot = data[left];
    int i = left +1;
    int j = right;

    while(true)
    {
        while(data[i] <= pivot && i <= right)
            i++;
        while(data[j] > pivot && j > left)
            j--;
        if(i < j)
            swap_c(&data[i], &data[j]);
        else
            break;
    }
    swap_c(&data[j], &data[left]);
    return j;
}

void quick_sort(int data[], int left, int right)
{
    if(left < right)
    {
        int p = partition(data, left, right);
        quick_sort(data, left, p-1);
        quick_sort(data, p+1, right);
    }
}

void find_little_man(int data[])
{
    int sum =0;
    int fake_a = 0;
    int fake_b = 0;
    // 다 더해
    for(int i = 0; i < 9; i++)
    {
        sum += data[i];
    }
    // 100이랑 빼
    sum -= 100;
    
    // 탐색 후 뺄 index들 체크
    // 해당 인덱스 200 처리.
    while(fake_a < 9)
    {
        fake_b = fake_a;
        while(fake_b <8)
        {
            fake_b++;
            if((data[fake_a] + data[fake_b]) == sum)
            {
                data[fake_a] = 200;
                data[fake_b] = 200;
                return;
            }
        }
        fake_a++;
    }
}

int main(void)
{
    int data[9] = {20,7,23,19,10,15,25,8,13};

    for(int i = 0; i < 9; i++)
    {
        cin>>data[i];
    }
    cout<<endl;
    find_little_man(data);
    quick_sort(data, 0, sizeof(data)/sizeof(int)-1);
    for(int i = 0; i < 7; i++)
    {
        cout<<data[i]<<endl;
    }
    return 0;
}