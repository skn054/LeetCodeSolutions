class Solution {

    /** leet code solution */
    public int[] sortArray(int[] nums) {
        int n = nums.length;
        nums = mergeSort(nums,0,n-1);
        return nums;
    }

    public int[] mergeSort(int[] nums,int start, int end){
        int mid = (start + end) /2;
        if(start == end){
            int temp[] = new int[1];
            temp[0] = nums[start];
            return temp;
        }

        int a[] = mergeSort(nums,start,mid);
        int b[] = mergeSort(nums,mid+1,end);
        return mergeSortedArray(a,b);

    }

    public int[] mergeSortedArray(int a[],int b[]){
        int l_a = a.length;
        int l_b = b.length;
        int n = l_a + l_b;
        int temp[] = new int[n];
        int i=0,j=0,k=0;
        while(k<n && i < l_a && j < l_b){
            if(a[i] < b[j]){
                temp[k] = a[i];
                i++;
            }else{
                temp[k] = b[j];
                j++;
            }
            k++;

        }
        while(i < l_a){
            temp[k++] = a[i++];
        }
        while(j < l_b){
            temp[k++] = b[j++];
        }

        return temp;
    }
}