class Solution {
    void merge(vector<int>&nums,int l,int mid,int r){
        if (l>=r){
            return ;
        }
        int i=l;
        int j=mid+1;
        vector<int>s;
        while(i<=mid && j<=r){
            if (nums[i]>nums[j]){
                s.push_back(nums[j]);
                j+=1;
            } else{
                s.push_back(nums[i]);
                i+=1;
            }
        }
        while (i<=mid){
            s.push_back(nums[i]),i++;
        }
        while(j<=r){
            s.push_back(nums[j]),j++;
        }
       int k=0;
    for (int i=l;i<=r;i++){
        nums[i]=s[k];
        k++;
    }
    
    }
    void mergesort(vector<int>&nums,int l,int r){
        if (l<r){
            int mid=(l+r)/2;
            mergesort(nums,l,mid);
            mergesort(nums,mid+1,r);
            merge(nums,l,mid,r);
        }
    }
    
public:
    vector<int> sortArray(vector<int>& nums) {
        mergesort(nums,0,nums.size()-1);
        return nums;
    }
};
