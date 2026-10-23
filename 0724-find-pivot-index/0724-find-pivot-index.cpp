class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
           sum+=nums[i];
        }
        int leftsum=0;
        for(int p=0;p<n;p++){
            if(leftsum == sum - leftsum - nums[p]){
                return p;
               }
            leftsum+=nums[p];
        }
        return -1;
    }
};