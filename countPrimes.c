
#include <stdbool.h> 
#include <string.h> 
#define MAX_N 5000001
static bool is_prime[MAX_N];
static int prime_counts[MAX_N];
static bool sieve_has_run = false;
void seive(){
    memset(is_prime, true, sizeof(is_prime));
    is_prime[0] = is_prime[1] = false;

    for(int i=2;i*i<MAX_N;i++){
        if(is_prime[i]){
            for(long long j=i*i ;j<MAX_N;j=j+i){
                is_prime[j] = false;
            }
        }
    }

     prime_counts[0] = 0;
    for(int i=1;i<MAX_N;i++){
        prime_counts[i] = prime_counts[i-1] + (is_prime[i]? 1: 0);
    }
}

int countPrimes(int n) {
    if(!sieve_has_run){
        seive();
        sieve_has_run = true;
    }
    if(n<=1){
        return 0;
    }
    return prime_counts[n-1];
    
}