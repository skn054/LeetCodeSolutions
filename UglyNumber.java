/***
 * An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.

Given an integer n, return the nth ugly number.

 

Example 1:

Input: n = 10
Output: 12
Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.
Example 2:

Input: n = 1
Output: 1
Explanation: 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.
 

Constraints:

1 <= n <= 1690
 */

class Solution {
    
   
    static int fCount =0;
    public int nthUglyNumber(int n) {

        PriorityQueue<Long> queue  = new PriorityQueue<>();
        HashSet<Long> set = new HashSet<>();
       if(n<=0) return 0;
       if(n == 1) return 1;
        queue.add(2L);
        queue.add(3L);
        queue.add(5L);

        set.add(2L);
        set.add(3L);
        set.add(5L);
        long ans = 1L;
        for(int i=2;i<=n;i++){

            ans = queue.poll();
            if(set.add(ans*2)){
                queue.add(ans*2);
            }
            if(set.add(ans*3)){
                queue.add(ans*3);
            }
            if(set.add(ans*5)){
                queue.add(ans*5);
            }
        }

        return (int) ans;
        
        
    }

    
        

    

  
}