class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        int low=0,high=min(k,n),mid;
        long long l1,l2,r1,r2;
        while(low<=high)
        {
            mid=(low+high)/2;
            if(k-mid>m){            
                low=mid+1;
                continue;
            }
          
            l1=mid>0?arr1[mid-1]:-1;
            l2=k-mid>0?arr2[k-mid-1]:-1;
            r1=mid<n?arr1[mid]:1e10;
            r2=k-mid<m?arr2[k-mid]:1e10;
            
            if(l1<=r2&&l2<=r1)
                return max(l1,l2);
            else if(l1>r2)
                high=mid-1;
            else if(l2>r1)
                low=mid+1;
        }
        return 0;
    }
};
