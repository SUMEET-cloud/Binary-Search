class Solution {
public:
    
    int low(vector<int>&nums,int target)
    {
        int st=0,end=nums.size()-1,mid;
        while(st<=end)
        {
            mid=(st+end)/2;
            if(nums[mid]==target)
            {
                if(mid==0||nums[mid-1]!=target)
                    return mid;
                end=mid-1;
            }
            else if(nums[mid]>target)
                end=mid-1;
            else st=mid+1;
        }
        return -1;
    }
    int high(vector<int>&nums,int target)
    {
        int st=0,end=nums.size()-1,mid;
        while(st<=end)
        {
            mid=(st+end)/2;
            if(nums[mid]==target)
            {
                if(mid==nums.size()-1 || nums[mid+1]!=target)
                    return mid;
                st=mid+1;
            }
            else if(nums[mid]>target)
                end=mid-1;
            else st=mid+1;
        }
        return -1;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans;
        if(nums.size()==0)
        ans.push_back(-1),
        ans.push_back(-1);
        else
        ans.push_back(low(nums,target)),
        ans.push_back(high(nums,target));
        return ans;
    }
};
