#include <iostream>

using namespace std;

void swap_c(int a[], int b[])
{
	int buff = *a;
	*a = *b;
	*b = buff;
}

int partition(int data[], int left, int right)
{
	int pivot = data[left]; // pivot은 첫째값
	int i = left +1;		// i는 첫째 다음 인덱스
	int j = right;			// j는 right 값
	
	while(true)
	{
		// i값은 pivot보다 같거나 큰가, 그리고 right보다 같거나 큰가
		while(data[i] <= pivot && i <=right)
			i++;
		// j값은 pivot값 보다 작은가, 그리고 left보다는 큰가
		while(data[j] > pivot && j > left)
			j--;
		// 그리고 i가 j보다 작을때 = i값이 pivot보다 크고, j값이 pivot보다 작을때 
		if(i<j)
			swap_c(&data[i], &data[j]); // i와 j값을 swap.
		// i가 j를 역전했을때. break.
		else
			break;
	}
	// 기존 pivot을 j(중앙)에 둔다.
	swap_c(&data[left], &data[j]);
	// 새로운 중앙 값 리턴
	return j;
}

// (data, 0, count-1)
void quick_sort(int data[], int left, int right)
{
	if(left < right)
	{
		int p = partition(data, left, right);
		quick_sort(data, left, p-1);
		quick_sort(data, p+1, right);
	}
}

int main(void)
{
	int array[] = {3,2,1,5,4,9};

	quick_sort(array, 0, (sizeof(array)/sizeof(int))-1);

	for(auto a: array)
		cout << a << ",";
	cout<<endl;

    return 0;
}



