class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
       double sum=0;
       int n=nums.size();
       for(int i=0;i<k;i++){
        sum+=nums[i];
        }
        int i=0;
        int j=k;
        double maxsum=sum;
        while(j<n){
            int newsum=nums[j]-nums[i];
            sum+=newsum;
            maxsum= max(sum,maxsum);
            i++;
            j++;
        }
        return maxsum/k;
        
    }
};