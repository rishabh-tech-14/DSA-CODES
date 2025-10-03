#include <iostream>
using namespace std;
#include <vector>

void merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;
    int left = low;
    int right = mid + 1;

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }
    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

void mergesort(vector<int> &arr, int low, int high)
{
    if (low >= high)
        return;
    int mid = (low + high) / 2;
    mergesort(arr, low, mid);
    mergesort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

int main()
{
    int n = 5;

    vector<int> v = {5, 4, 3, 2, 1};

    cout << "Array before sorting : ";
    for (int i = 0; i < n; i++)
    {
        cout << v[i]<<" ";
    }
    cout<<endl;

    mergesort(v, 0, n - 1);

    cout << "Array after sorting : ";
    for (int i = 0; i < n; i++)
    {
        cout << v[i]<<" ";
    }

    return 0;
}