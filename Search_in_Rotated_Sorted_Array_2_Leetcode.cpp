class Solution {
public:
    bool search(vector<int>& arr, int target) {
    int low=0,high=arr.size()-1,mid;
        int n=arr.size();
        while(low<=high)
        {
            mid=(low+high)/2;
            if(low>=0&&low<=n-1&&arr[low]==target)
                return true;
            if(high>=0&&high<=n-1&&arr[high]==target)
                return true;
          
            if(arr[mid]==target)
                return true;
            else if(arr[mid]>arr[low])
            {
                if(target>=arr[low]&&target<=arr[mid])
                    high=mid-1;
                else 
                    low=mid+1;
            }
            else if(arr[mid]<arr[high]){
                if(target>=arr[mid]&&target<=arr[high])
                    low=mid+1;
                else 
                    high=mid-1;
            }
            else low++,high--;
        }
            if(low>=0&&low<=n-1&&arr[low]==target)
                return true;
            if(high>=0&&high<=n-1&&arr[high]==target)
                return true;        
            return false;
    }
};
