#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// 배열을 분할하는 함수
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low; // pivot보다 작은 구역의 끝 인덱스

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[high]);
    return i;
}

// 무작위 피벗을 사용하는 분할 함수
int randomizedPartition(int arr[], int low, int high)
{
    int pivotIndex = low + rand() % (high - low + 1);
    swap(arr[pivotIndex], arr[high]); // pivotindex와 high의 값을 변경하는 이유는, 일반적으로 partition 함수가 마지막 원소를 피벗으로 가정하기 때문이다.
    return partition(arr, low, high);
}

// Quickselect 알고리즘
int quickSelect(int arr[], int low, int high, int k)
{
    if (low == high)
        return arr[low];

    int pivotIndex = randomizedPartition(arr, low, high);

    // 피벗의 위치가 우리가 찾는 k번째 원소일 때
    if (pivotIndex == k)
    {
        return arr[pivotIndex];
    }
    else if (pivotIndex > k)
    {
        return quickSelect(arr, low, pivotIndex - 1, k);
    }
    else
    {
        return quickSelect(arr, pivotIndex + 1, high, k);
    }
}

int main()
{
    srand(time(0));

    int arr[] = {7, 10, 4, 3, 20, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;

    int result = quickSelect(arr, 0, n - 1, k - 1); // 인덱스는 0부터 시작하므로 k-1
    cout << k << "번째로 작은 원소는 " << result << "입니다." << endl;
    return 0;
}