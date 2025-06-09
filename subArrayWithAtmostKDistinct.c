/**
 * You are given an array arr[] of positive integers and an integer k, find the number of subarrays in arr[] where the count of distinct integers is at most k.

Note: A subarray is a contiguous part of an array.

Examples:

Input: arr[] = [1, 2, 2, 3], k = 2
Output: 9
Explanation: Subarrays with at most 2 distinct elements are: [1], [2], [2], [3], [1, 2], [2, 2], [2, 3], [1, 2, 2] and [2, 2, 3].
Input: arr[] = [1, 1, 1], k = 1
Output: 6
Explanation: Subarrays with at most 1 distinct element are: [1], [1], [1], [1, 1], [1, 1] and [1, 1, 1].
Input: arr[] = [1, 2, 1, 1, 3, 3, 4, 2, 1], k = 2
Output: 24
Explanation: There are 24 subarrays with at most 2 distinct elements.
 */

class Solution {
  public:
    int atMostK(vector<int> &arr, int k) {
        // code here
        unordered_map<int, int> freq_count;
        int sw=0,ew=0;
        int count = 0;
        int len = arr.size();
       
        while(ew<len){
            freq_count[arr[ew]]+=1;
            
            if(freq_count[arr[ew]] == 1){
                k--;
            }
            
            while(k<0 && sw<=ew){
                int temp = arr[sw];
                int c =freq_count[temp];
                c--;
                if(c<=0){
                    k++;
                }
                freq_count[temp] = c;
                
                sw++;
            }
            
            count+= ew - sw + 1;
            ew++;
            
        }
        return count;
    }
};