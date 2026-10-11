class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i=0;
        int j= nums.size()-1;
        unordered_map<int,int> m;
        for(int i=0;i<=j;i++){
            int req=target - nums[i];
            if(m.find(req)!=m.end()){
               return {m[req],i};
            }
            else{
                m[nums[i]]=i;
            }
    
    }
       
    return {};   
    }
    
};