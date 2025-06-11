/**
 * Given an integer array nums and an integer k, return the number of good subarrays of nums.

A good array is an array where the number of different integers in that array is exactly k.

For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
A subarray is a contiguous part of an array.

 

Example 1:

Input: nums = [1,2,1,2,3], k = 2
Output: 7
Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]
Example 2:

Input: nums = [1,2,1,3,4], k = 3
Output: 3
Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].
 

Constraints:

1 <= nums.length <= 2 * 104
1 <= nums[i], k <= nums.length
 */


class Solution {

    private:
    int AtMostDistinct(vector<int> &nums,int k){
        int sw=0,ew=0,count=0;
        int len = nums.size();
        unordered_map<int,int> freq_count;

        while(ew<len){
            int element = nums[ew];
            freq_count[element]++;
            if(freq_count[element]==1){
                k--;
            }
            while(k<0 && sw<=ew){
                int temp = nums[sw];
                int f_count = freq_count[temp];
                f_count-=1;
                if(f_count == 0){
                    k+=1;
                    freq_count[temp]=0;
                }else{
                    freq_count[temp] = f_count;
                }
                sw++;
            }

            count+=ew-sw +1;
            
            ew++;
        }

        return count;
    }

    
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {


        return AtMostDistinct(nums,k) - AtMostDistinct(nums,k-1);
        
        
    }
};