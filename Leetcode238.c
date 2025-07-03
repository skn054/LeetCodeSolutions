/**
 * Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

 

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
 

Constraints:

2 <= nums.length <= 105
-30 <= nums[i] <= 30
The input is generated such that answer[i] is guaranteed to fit in a 32-bit integer.
 */


 /**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* arr, int numsSize, int* returnSize) {

    int *arrResult = (int *)calloc(numsSize,sizeof(int));
    int *prefix = (int *)calloc(numsSize,sizeof(int));
    int *suffix = (int *)calloc(numsSize,sizeof(int));
    *returnSize = numsSize;

     // Check for allocation failure
    if (arrResult == NULL || prefix == NULL || suffix == NULL) {
        
        free(arrResult);
        free(prefix);
        free(suffix);
        *returnSize = 0; // Inform caller that nothing is returned
        return NULL;
    }

    for(int i=0;i<numsSize;i++){
        if(i==0) prefix[i] = arr[i];
        else prefix[i] = prefix[i-1] * arr[i];
    }

    for(int i=numsSize-1;i>=0;i--){
        if(i==numsSize - 1) suffix[i] = arr[i];
        else suffix[i] = suffix[i+1] * arr[i];
    }

    for(int i=0;i<numsSize;i++){
        if(i==0) arrResult[i] = suffix[i+1];
        else if(i==numsSize-1) arrResult[i] = prefix[i-1];
        else{
            arrResult[i] = prefix[i-1] * suffix[i+1];
        }

    }

    // for(int i=0;i<numsSize;i++){
    //     printf("%d ",arrResult[i]);
    // }
    free(prefix);
    free(suffix);
    return arrResult;
    
    
}