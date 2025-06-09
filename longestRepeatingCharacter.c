
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/**
 * You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.

 

Example 1:

Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.
Example 2:

Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
There may exists other ways to achieve this answer too.
 

Constraints:

1 <= s.length <= 105
s consists of only uppercase English letters.
0 <= k <= s.length
 */

int stringOfLengthPossible(char *s,int k,int str_len){
    int len = strlen(s);
    for(int i=0;i<26;i++){
        char target = (char)('A' + i);
        int mismatch=0;
        for(int i=0;i<str_len;i++){
            if(s[i]!=target){
                mismatch++;
            }
        }
        if(mismatch<=k) return 1;

        for(int i=str_len;i<len;i++){
            if(s[i]!=target){
                mismatch++;
            }
            if(s[i-str_len]!=target){
                mismatch--;
            }

            if(mismatch<=k)return 1;
        }



    }
    return 0;
}
int characterReplacement(char* s, int k) {

    int len = strlen(s);
    int start=0,end = len-1;
    int ans = 0;

    while(start<=end){

        int mid = start + (end - start)/2;
        

        if(stringOfLengthPossible(s,k,mid)){
            ans = mid;
            start = mid + 1;
        }else{
            end = mid-1;
        }
    }

    return ans;
    
}