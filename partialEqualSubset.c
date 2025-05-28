
/***
 * 
 * Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.

 

Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.
 

Constraints:

1 <= nums.length <= 200
1 <= nums[i] <= 100
 */


class Solution {
    unordered_map<string, bool> memo;
public:
    
    bool isPartitionPossible(vector<int> &nums,int len,int target,int index){
        if(target == 0){
            
            return true;
        }
        
        

        if(index>=len || target < 0){
            return false;
        }

        string key = to_string(index) + "," + to_string(target);
        if(memo.count(key)){
            return memo[key];
        }

        bool result = isPartitionPossible(nums,len,target-nums[index],index+1) || isPartitionPossible(nums,len,target,index+1);

        // if(isPartitionPossible(nums,len,target-nums[index],index+1)){
        //     return true;
        // }
        // return isPartitionPossible(nums,len,target,index+1);

        memo[key] = result;

        return result;
        

    }
    bool canPartition(vector<int>& nums) {

        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum%2!=0){
            return false;
        }

        if(isPartitionPossible(nums,nums.size(),sum/2,0)){
            return true;
        }
        // return isPartitionPossible(nums,nums.size(),sum/2,1);
        return false;
        
    }
};