/***
 * 
 * 
 * You are given an integer mountain array arr of length n where the values increase to a peak element and then decrease.

Return the index of the peak element.

Your task is to solve it in O(log(n)) time complexity.

 

Example 1:

Input: arr = [0,1,0]

Output: 1

Example 2:

Input: arr = [0,2,1,0]

Output: 1

Example 3:

Input: arr = [0,10,5,2]

Output: 1

 

Constraints:

3 <= arr.length <= 105
0 <= arr[i] <= 106
arr is guaranteed to be a mountain array.
 */


int peakIndexInMountainArray(int* arr, int arrSize) {

    if(arrSize == 1) return arr[0];
    if(arrSize == 2) return arr[0] > arr[1] ? arr[0] : arr[1];
    int start = 1;
    int end = arrSize - 1;
    int ans = 0;
    while(start <=end){
        int mid = (start + end)/2;
        if(mid == arrSize - 1) return mid;
        if(arr[mid] > arr[mid -1 ] && arr[mid]>arr[mid+1]){
            return mid;
        }else if(arr[mid]<arr[mid-1]){
            end = mid-1;
        }else{
            start = mid + 1;
        }
    }
    return ans;
    
}