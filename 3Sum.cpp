class Solution {
public:
    
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int>> result_nums;
        vector<int> result;
        sort(nums.begin(),nums.end());
        for(int i=0;i<len-2;i++){
            if( i > 0 && nums[i] == nums[i-1]) {continue;}
            int l = i+1;
            int r = len - 1;
            while(l < r){
                
                int sum = nums[i]+nums[l]+nums[r];
                if(sum ==0){
                result.clear();
                result.push_back(nums[i]);
                result.push_back(nums[l]);
                result.push_back(nums[r]);
                result_nums.push_back(result);
                

                while(l+1 < r && nums[l]== nums[l+1]){
                    l+=1;
                }
                while(r-1 > l && nums[r]==nums[r-1]){
                    r-=1;
                }

                l++;
                r--;


            }
            else if(sum < 0){
                    l++;
            }else{
                    r--;
                }
            }
            
            
        }
        return result_nums;

         

        
        
    }
};