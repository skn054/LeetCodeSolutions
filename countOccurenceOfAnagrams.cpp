// User function template for C++
/***
 * 
 * Count Occurences of Anagrams
Difficulty: MediumAccuracy: 48.09%Submissions: 92K+Points: 4
Given a word pat and a text txt. Return the count of the occurrences of anagrams of the word in the text.

Example 1:

Input: txt = "forxxorfxdofr", pat = "for"
Output: 3
Explanation: for, orf and ofr appears in the txt, hence answer is 3.
Example 2:

Input: txt = "aabaabaa", pat = "aaba"
Output: 4
Explanation: aaba is present 4 times in txt.
Constraints:
1 <= |pat| <= |txt| <= 105
Both strings contain lowercase English letters.
 */
#include <iostream>
#include <map>
#include <string>
class Solution {
  public:
    int search(string &pat, string &txt) {
        // code here
        map<int,int> freqCount;
        map<int,int> freqText;
        int patLen  = pat.length();
        int txtLen = txt.length();
        int count = 0;
        
        if(patLen > txtLen) return 0;
        
        for(int i=0;i<patLen;i++){
            freqCount[pat[i]]++;
        }
        for(int i=0;i<patLen;i++){
            freqText[txt[i]]++;
        }
        if(freqCount == freqText){
            count++;
        }
        
        for(int i=patLen;i<txtLen;i++){
            char removedChar = txt[i-patLen];
            char currChar = txt[i];
            freqText[removedChar]--;
            if(freqText[removedChar]==0){
                freqText.erase(removedChar);
            }
            
            freqText[currChar]++;
            
            if(freqCount == freqText){
                count++;
            }
        }
        
        return count;
    }
};
