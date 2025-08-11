class LongestSubStringWithoutRepeatingChar {
    public int lengthOfLongestSubstring(String s) {
        
        int len = s.length();
        int start = 0,end = 0;
        HashMap<Character,Integer> hmap = new HashMap<>();
        int max = 0;
        while(end<=len-1){
            Character c = s.charAt(end);
            
            if(hmap.containsKey(c)){
                
                //remove from current window until count(currCHar) <=0
                while(start<=end && hmap.get(c)>=1){
                    int count = hmap.get(s.charAt(start));
                    hmap.put(s.charAt(start),count-1);
                    start++;
                    
                }
                
            }
                
            hmap.put(c,1);
            max = end-start+1 > max ? end-start+1 : max;
            end++;
            
        }
        return max;

    }
}