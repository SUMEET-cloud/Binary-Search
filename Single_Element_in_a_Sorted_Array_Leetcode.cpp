class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
       
        int n=arr.size();
        if(n==1||arr[0]!=arr[1])
            return arr[0];
        
        if(arr[n-1]!=arr[n-2])
            return arr[n-1];
        
        int low=0,high=n-1,mid;
        
        while(low<=high)
        {
            mid=(low+high)/2;

            if(arr[mid]!=arr[mid+1]&&arr[mid]!=arr[mid-1])
                return arr[mid];
            else if(mid>0 && arr[mid]==arr[mid-1])
            {
                if((high-mid)&1)
                    low=mid+1;
                else high=mid-2;
            }
            else if(mid<n-1 &&arr[mid]==arr[mid+1])
            {
                if((mid-low)&1)
                    high=mid-1;
                else low = mid+2;
            }
        }
        return -1;
    }
};
