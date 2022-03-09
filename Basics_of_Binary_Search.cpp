#include <bits/stdc++.h>
using namespace std;

bool binary_searchC(int arr[], int n, int val)
{
    int st = 0, end = n - 1, mid;
    while (st <= end)
    {
        mid = (st + end) / 2;
        if (arr[mid] == val)
            return true;
        else if (arr[mid] > val)
            end = mid - 1;
        else
            st = mid + 1;
    }
    return false;
}

int lower_boundC(int arr[], int n, int val)
{
    int st = 0, end = n - 1, mid;
    if (val > arr[end])
        return n;
    while (st <= end)
    {
        mid = (st + end) / 2;
        if (arr[mid] == val)
        {
            if (mid == 0 || arr[mid - 1] != val)
                return mid;
            end = mid - 1;
        }
        else if (arr[mid] > val)
            end = mid - 1;
        else
            st = mid + 1;
    }
    if (arr[mid] < val)
        mid++;
    return mid;
}

int upper_boundC(int arr[], int n, int val)
{
    int st = 0, end = n - 1, mid;
    if (val > arr[end])
        return n;
    while (st <= end)
    {
        mid = (st + end) / 2;
        if (arr[mid] == val)
        {
            if (mid == n - 1 || arr[mid + 1] != val)
                return mid + 1;
            st = mid + 1;
        }
        else if (arr[mid] > val)
            end = mid - 1;
        else
            st = mid + 1;
    }
    if (arr[mid] < val)
        mid++;
    return mid;
}

int main()
{
    int n = 15;
    int arr[] = {1, 3, 3, 3, 8, 8, 8, 15, 15, 20, 20, 30, 50, 100, 100};

    // *Simple Binary Search
    // *STL Binary Search (Return Type Bool)
    bool res = binary_search(arr, arr + n, 6);
    cout << res << "\n";

    res = binary_search(arr, arr + n, 100);
    cout << res << "\n";

    // *Code Binary Search
    res = binary_searchC(arr, n, 6);
    cout << res << "\n";

    res = binary_searchC(arr, n, 100);
    cout << res << "\n";

    // *Advance Binary Search

    // *STL LowerBound Search (Return Type Iterator)
    // *If Element found then it returns the first occurance of element in array
    // *Else it return next greater element
    int ind = lower_bound(arr, arr + n, 8) - arr;
    cout << ind << "\n";

    ind = lower_bound(arr, arr + n, 10) - arr;
    cout << ind << "\n";

    ind = lower_bound(arr, arr + n, 200) - arr;
    cout << ind << "\n";

    // *LowerBound Code Binary Search
    ind = lower_boundC(arr, n, 8);
    cout << ind << "\n";

    ind = lower_boundC(arr, n, 99);
    cout << ind << "\n";

    ind = lower_boundC(arr, n, 200);
    cout << ind << "\n";

    // *STL UpperBound Search (Return Type Iterator)
    // *Always return itr to next greater element(of num)
    int ind = upper_bound(arr, arr + n, 8) - arr;
    cout << ind << "\n";

    ind = upper_bound(arr, arr + n, 10) - arr;
    cout << ind << "\n";

    ind = upper_bound(arr, arr + n, 200) - arr;
    cout << ind << "\n";

    // *LowerBound Code Binary Search
    ind = upper_boundC(arr, n, 8);
    cout << ind << "\n";

    ind = upper_boundC(arr, n, 10);
    cout << ind << "\n";

    ind = upper_boundC(arr, n, 200);
    cout << ind << "\n";
}
