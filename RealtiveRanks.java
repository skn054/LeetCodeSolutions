/***
 * 
 * You are given an integer array score of size n, where score[i] is the score of the ith athlete in a competition. All the scores are guaranteed to be unique.

The athletes are placed based on their scores, where the 1st place athlete has the highest score, the 2nd place athlete has the 2nd highest score, and so on. The placement of each athlete determines their rank:

The 1st place athlete's rank is "Gold Medal".
The 2nd place athlete's rank is "Silver Medal".
The 3rd place athlete's rank is "Bronze Medal".
For the 4th place to the nth place athlete, their rank is their placement number (i.e., the xth place athlete's rank is "x").
Return an array answer of size n where answer[i] is the rank of the ith athlete.

 

Example 1:

Input: score = [5,4,3,2,1]
Output: ["Gold Medal","Silver Medal","Bronze Medal","4","5"]
Explanation: The placements are [1st, 2nd, 3rd, 4th, 5th].
Example 2:

Input: score = [10,3,8,9,4]
Output: ["Gold Medal","5","Bronze Medal","Silver Medal","4"]
Explanation: The placements are [1st, 5th, 3rd, 2nd, 4th].

 

Constraints:

n == score.length
1 <= n <= 104
0 <= score[i] <= 106
All the values in score are unique.
 */



class Solution {
    public String[] findRelativeRanks(int[] score) {
        
        PriorityQueue<Pair> queue = new PriorityQueue<>((a,b) -> b.getValue() - a.getValue());
        String results[] = new String[score.length];
        int resIndex = 0;
        for(int i=0;i<score.length;i++){
            queue.add(new Pair(i,score[i]));
        }

        while(!queue.isEmpty()){
            int index = queue.poll().getIndex();
            if(resIndex == 0){
                results[index] = "Gold Medal";
            }else if(resIndex == 1){
                results[index] = "Silver Medal";
            }else if(resIndex == 2){
                results[index] = "Bronze Medal";
            }else{
                results[index] = resIndex+1+ "";
            }
            resIndex++;
        }
        return results;
    }



    static class Pair{
        private int index;
        private int value;

        public Pair(int index,int value){
            this.index = index;
            this.value = value;
        }

        public int getIndex(){
            return index;
        }

        public int getValue(){
            return value;
        }

    }
}