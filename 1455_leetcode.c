/***
 * 
 * Given a sentence that consists of some words separated by a single space, and a searchWord, check if searchWord is a prefix of any word in sentence.

Return the index of the word in sentence (1-indexed) where searchWord is a prefix of this word. If searchWord is a prefix of more than one word, return the index of the first word (minimum index). If there is no such word return -1.

A prefix of a string s is any leading contiguous substring of s.

 

Example 1:

Input: sentence = "i love eating burger", searchWord = "burg"
Output: 4
Explanation: "burg" is prefix of "burger" which is the 4th word in the sentence.
Example 2:

Input: sentence = "this problem is an easy problem", searchWord = "pro"
Output: 2
Explanation: "pro" is prefix of "problem" which is the 2nd and the 6th word in the sentence, but we return 2 as it's the minimal index.
Example 3:

Input: sentence = "i am tired", searchWord = "you"
Output: -1
Explanation: "you" is not a prefix of any word in the sentence.
 

Constraints:

1 <= sentence.length <= 100
1 <= searchWord.length <= 10
sentence consists of lowercase English letters and spaces.
searchWord consists of lowercase English letters.
 */

void computeLPS(int *LPS,int len,char *pattern){

    int i=0,j=1;
    LPS[i] = 0;
    while(j<len){

        if(pattern[i]==pattern[j]){
            LPS[j] = i+1;
            i++;
            j++;
            
        }else{

            if(i==0){
                LPS[j]=0;
                j++;
            }
            else{
                i = LPS[i-1];
            }
        }
       
    }
}



int KMPalgorithm(char *inputStr,char *pattern,int *LPS){

    int i=0,j=0;
    int len = strlen(inputStr);
    int patternLen = strlen(pattern);
    while(j< patternLen && i< len ){
        // if(j>=patternLen){
        //     // pattern found
        //     return i-j;
        // } 
        if(inputStr[i]==pattern[j]){
            i++;
            j++;
        }else{
            if(j>0){
                j = LPS[j-1];
            }else{
                j=0;
                i++;
            }
            
        }
    }
    if(j==patternLen){
        return i-patternLen;
    }
    return -1;
}

int isPrefixOfWord(char* sentence, char* searchWord) {
    
   
    int pattern_len = strlen(searchWord);
    int LPS[pattern_len];
    for(int i=0;i<pattern_len;i++){
        LPS[i] = 0;
    }
    computeLPS(&LPS[0],pattern_len,searchWord);
    char *token = strtok(sentence, " ");
    int count = 1;
    while (token != NULL) {
        printf("%s\n", token);
        if(KMPalgorithm(token,searchWord,&LPS[0]) == 0)   {
                return count;
        }
        token = strtok(NULL, " "); // Get the next token
        count++;
    }
    return -1;
}