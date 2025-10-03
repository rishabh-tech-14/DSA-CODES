#include <iostream>
#include <vector>
using namespace std;

void combination(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds)
{
    if (ind == arr.size())
    {
        if (target == 0)
        {
            ans.push_back(ds);
        }

        return;
    }

    if (arr[ind] <= target)
    {
        ds.push_back(arr[ind]);
        combination(ind, target - arr[ind], arr, ans, ds);
        ds.pop_back();
    }

    combination(ind + 1, target, arr, ans, ds);
}

int main()
{
    vector<int> arr = {2, 3, 6, 7};

    int target = 7;

    vector<vector<int>> ans;

    vector<int> ds;

    combination(0, target, arr, ans, ds);

    for (auto i : ans)
    {
        for (auto it : i)
        {
            cout << it << " ";
        }
        cout << endl;
    }

    return 0;
}