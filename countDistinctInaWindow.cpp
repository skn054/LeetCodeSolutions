/***
 * 
 * Count distinct elements in every window
Difficulty: MediumAccuracy: 41.83%Submissions: 158K+Points: 4Average Time: 20m
Given an integer array arr[] and a number k. Find the count of distinct elements in every window of size k in the array.

Examples:

Input: arr[] = [1, 2, 1, 3, 4, 2, 3], k = 4
Output:  [3, 4, 4, 3]
Explanation: Window 1 of size k = 4 is 1 2 1 3. Number of distinct elements in this window are 3. 
Window 2 of size k = 4 is 2 1 3 4. Number of distinct elements in this window are 4.
Window 3 of size k = 4 is 1 3 4 2. Number of distinct elements in this window are 4.
Window 4 of size k = 4 is 3 4 2 3. Number of distinct elements in this window are 3.
Input: arr[] = [4, 1, 1], k = 2
Output: [2, 1]
Explanation: Window 1 of size k = 2 is 4 1. Number of distinct elements in this window are 2. 
Window 2 of size k = 2 is 1 1. Number of distinct elements in this window is 1. 
Input: arr[] = [1, 1, 1, 1, 1], k = 3
Output: [1, 1, 1]
Constraints:
1 <= k <= arr.size() <= 105
1 <= arr[i] <= 105


 */
class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        // code here.
        int freq[100002] = {0};
        int distinctElement = 0;
        vector<int> result;
        for(int i=0;i<k ;i++){
            
            if(freq[arr[i]]==0){ // new distinct element
                distinctElement++;
            }
            freq[arr[i]]++;
        }
        
        result.push_back(distinctElement);
        for(int i=k;i<arr.size();i++){
            // delete element
            // freq[arr[i-k]] = freq[arr[i-k]] - 1;
            int removedElement = arr[i-k];
            freq[removedElement]--;
            if(freq[removedElement] <=0){
                // deleted distinct element
                distinctElement--;
            }
            
            // add element
            int currElement = arr[i];
            if(freq[currElement]==0){
                distinctElement++;
            }
            freq[currElement]++;
            
            result.push_back(distinctElement);
            
        }
        return result;
    }
};