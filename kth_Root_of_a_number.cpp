#include <bits/stdc++.h>
using namespace std;

double findKthRoot(int num, int k)
{
    double val = num;
    double low = 1, high = num, mid;

    while ((high - low) > (1e-6))
    {
        mid = (low + high) / 2;

        double mid_val = 1;
        for (int i = 0; i < k; i++)
            mid_val = mid_val * mid;

        if (mid_val > val)
            high = mid;
        else
            low = mid;
    }
    return mid;
}

int main()
{
    int num, k;
    cin >> num >> k;
    cout << findKthRoot(num, k);
}