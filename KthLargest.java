/***
 * 
 * Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?

 

Example 1:

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
Example 2:

Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4
 
 */


class Solution {
    public int findKthLargest(int[] nums, int k) {

        PriorityQueue<Integer> queue = new PriorityQueue<>();

        int sizeOfArr = nums.length;
        for(int i=0;i<sizeOfArr;i++){
            queue.add(nums[i]);
            if(queue.size() >k){
                queue.poll();
            }
        }

        return queue.peek();
        
    }
}