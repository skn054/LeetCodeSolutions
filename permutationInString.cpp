/***
 * 
 Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

 

Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input: s1 = "ab", s2 = "eidboaoo"
Output: false
 

Constraints:

1 <= s1.length, s2.length <= 104
s1 and s2 consist of lowercase English letters.
 */


 class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len_s1 = s1.length();
        int len_s2 =s2.length();
        map<int,int> freq_s1;
        map<int,int> freq_s2;
        if(len_s1 > len_s2) return 0;

        for(int i=0;i<len_s1;i++){
            freq_s1[s1[i]]++;
        }

        for(int i=0;i<len_s1;i++){
            freq_s2[s2[i]]++;
        }
        if(freq_s1 == freq_s2) return true;

        for(int i=len_s1;i<len_s2;i++){
            char removedChar = s2[i-len_s1];
            char currChar = s2[i];
            freq_s2[removedChar]--;
            if(freq_s2[removedChar]==0){
                freq_s2.erase(removedChar);
            }

            freq_s2[currChar]++;

            if(freq_s1 == freq_s2) return true;
        }

        return false;
    }
};