class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefix(n);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+nums[i];
        }
        vector<int> suffix(n);
        suffix[n-1]=nums[n-1];
        for(int j=n-2;j>=0;j--){
            suffix[j]=suffix[j+1]+nums[j];
        }
        for(int p=0;p<n;p++){
            if(suffix[p]==prefix[p]) return p;     
        }
        return -1;
    }
};