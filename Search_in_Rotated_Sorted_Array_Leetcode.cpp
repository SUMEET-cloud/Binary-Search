class Solution {
public:
    int search(vector<int>& arr, int target) {
        int low=0,high=arr.size()-1,mid;
        
        while(low<=high)
        {
            mid=(low+high)/2;
            if(arr[mid]==target)
                return mid;
            else if(arr[mid]>=arr[low])
            {
                if(target>=arr[low]&&target<arr[mid])
                    high=mid-1;
                else 
                    low=mid+1;
            }
            else if(arr[mid]<=arr[high]){
                if(target>arr[mid]&&target<=arr[high])
                    low=mid+1;
                else 
                    high=mid-1;
            }
        }
        return -1;
    }
};
