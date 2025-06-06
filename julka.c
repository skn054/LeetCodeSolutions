#include<stdio.h>
#include<string.h>
#define MAXLENGTH 102

void reverseInput(char *N,int *rev_N,int *slen){
    *slen = 0;
    int len = strlen(N);
    
    for(int i=len-1;i>=0;i--){
         
        rev_N[*slen] = N[i] - '0';
        *slen = *slen + 1;
        
    }
    
}

void calculatediff(int *rev_N,int * rev_K,int *res_diff,int *len_res_diff,int rev_len_N,int rev_len_K){

    int borrow = 0;
    int k = 0;
    // printf("%d",rev_len_N);
    for(int i=0;i<rev_len_N;i++){
        int digit_b = (i < rev_len_K) ? rev_K[i] : 0;
        int diff = rev_N[i] - digit_b - borrow;
        if(diff < 0){
            diff+=10;
            borrow = 1;
        }else{
            borrow = 0;
        }
        res_diff[k] = diff;
        k+=1;
    }
    
    

    /** remove leading zeroes */
    while(k > 1 && res_diff[k-1]==0){
        k--;
        
    }
    *len_res_diff = k ;

        
}
void main(){

    int ch;
    char N[MAXLENGTH];
    char K[MAXLENGTH];
    /** read inpput into array *. A total of 1 test cases**/
    for(int i=0;i<1;i++){
        scanf("%s",N);
        scanf("%s",K);

        int len_N = strlen(N);
        int len_K = strlen(K);
        /** reverse each string */
        int rev_N[MAXLENGTH],rev_len_N;
        int rev_K[MAXLENGTH],rev_len_K;
        int res_diff[MAXLENGTH],len_res_diff;
        reverseInput(N,rev_N,&rev_len_N);
        reverseInput(K,rev_K,&rev_len_K);


        /** Natalia has (sum - k)/2 apples *.compute sum-k**/
         
         calculatediff(rev_N,rev_K,res_diff,&len_res_diff,rev_len_N,rev_len_K);
         for(int i=0;i<len_res_diff;i++){
            printf("%d",res_diff[i]);
         }
        /** kalude has sum - natalia apples */

    }

    


    /** calculate Num-K */


    

    


}