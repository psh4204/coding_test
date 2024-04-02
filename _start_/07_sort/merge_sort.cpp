#include <iostream>
#include <algorithm>

using namespace std;

int _buff[256] = {0,};

void merge(int data[], int left, int mid, int right)
{
	int i = left;
	int j = mid +1;
	int k = left;
	// 이미 정렬된 두개의 배열을 합치는 함수
	while((i <= mid) && (j <= right))
	{
		// 왼쪽과 오른쪽 중 더 작거나 같은 수를 Buff 에 추가
		if(data[i] <= data[j])
		{
			_buff[k++] = data[i++];
		}
		else
		{
			_buff[k++] = data[j++];
		}
	}
	// 남은 왼쪽 배열 털기
	while(i <= mid)
	{
		_buff[k++] = data[i++];
	}
	// 남은 오른쪽 배열 털기
	while(j <= right)
	{
		_buff[k++] = data[j++];
	}
	for(int idx = left; idx <= right; idx++)
	{
		data[idx] = _buff[idx];
	}
}

void merge_sort(int data[], int left, int right)
{
	// data 배열이 1개로 쪼개질때 까지 분열
	// 그리고 순서에 맞게 병합
	if(left < right)
	{
		int mid = (left+right)/2;
		// 왼쪽 배열
		merge_sort(data, left, mid);
		// 오른쪽 배열
		merge_sort(data, mid+1, right);
		merge(data,left,mid,right);
	}
}

int main(void)
{
	int data[] = {2,4,1,6,3,8,7,5,};
	merge_sort(data, 0, 7);

	for(auto& a : data)
		cout<< a << ",";
	cout << endl;

    return 0;
}



