class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        if(nums1.size()>nums2.size())return findMedianSortedArrays(nums2,nums1);
        
        if(nums1.size()==0)
            return nums2.size()%2==0?((double)nums2[nums2.size()/2]+(double)nums2[nums2.size()/2-1])/2:nums2[nums2.size()/2];
        if(nums2.size()==0)
            return nums1.size()%2==0?((double)nums1[nums1.size()/2]+(double)nums1[nums1.size()/2-1])/2:nums1[nums1.size()/2];

        int low=0,high=nums1.size(),mid,tot;
        bool ok;
        if((nums1.size()+nums2.size())%2==0)
            tot=(nums1.size()+nums2.size())/2,ok=1;
        else 
            tot=(nums1.size()+nums2.size()+1)/2,ok=0;
        
        int l1,l2,r1,r2;
        while(low<=high)
        {
            mid=(low+high)/2;

            l1=(mid-1>-1?nums1[mid-1]:-1e7);
            l2=(tot-mid-1>-1?nums2[tot-mid-1]:-1e7);
            r1=(mid<=nums1.size()-1?nums1[mid]:1e7);
            r2=(tot-mid<=nums2.size()-1?nums2[tot-mid]:1e7);
            
            if(l1<=r2&&l2<=r1)
                return ok?((double)max(l1,l2)+(double)min(r2,r1))/2:max(l1,l2);            
            else if(l1>r2)
                high=mid-1;
            else 
                low=mid+1;
        }
        return 0;
    }
};
