class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int ans=0;

        while(!nonDecreasing(nums)){
            int minSum=INT_MAX;
            int idx=0;

            for(int i=0;i+1<nums.size();i++){
                int sum=nums[i]+nums[i+1];

                if(sum<minSum){
                    minSum=sum;
                    idx=i;
                }
            }
            nums[idx]+=nums[idx+1];
            nums.erase(nums.begin()+1+idx);
            ans++;
        }
        return ans;
    }
    bool nonDecreasing(vector<int> &nums){
        for(int i=0;i+1<nums.size();i++){
            if(nums[i]>nums[i+1]) return false;
        }
        return true;
    }
};
