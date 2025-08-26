class Solution {
    public boolean hasMatch(String s, String p) {

        int slen = s.length();
        int plen = p.length();
        int index = 0,indexF=0;
        boolean f1=false;
        boolean f2 = false;
        
        for(int i=0;i<plen;i++){
            if(p.charAt(i)=='*'){
                index = i;
                break;
            }
        }
        String prefix = p.substring(0,index);
        String suffix = p.substring(index+1);
        // for(int i=0;i<slen-s1.length();i++){
        //     int second = 0;
        //     while(second< s1.length()){
        //         if(s.charAt(second+i)!=s1.charAt(second)){
        //             break;
        //         }
        //         second++;
        //     }
        //     if(second == s1.length()){
        //         f1 = true;
        //         indexF = i+s.length();
                
        //     }

            
        // }
        // if(!f1){
        //     return false;
        // }

        // System.out.println("value of f1"+f1);

        //  for(int i=indexF;i<slen-s2.length();i++){
        //     int second = 0;
        //     while(second< s2.length()){
        //         if(s.charAt(second+i)!=s2.charAt(second)){
        //             break;
        //         }
        //         second++;
        //     }
        //     if(second == s2.length()){
        //         f2 = true;
        //     }

            
        // }
        // System.out.println("value of f2"+f2);

        int prefixMatchIndex = s.indexOf(prefix);
        if(prefixMatchIndex == -1){
            return false;
        }

        int suffixSearchStartIndex = prefixMatchIndex + prefix.length();
        int suffixMatchIndex= s.substring(suffixSearchStartIndex).indexOf(suffix);
        if(suffixMatchIndex == -1){
            return false;
        }

        return true;

        

        
        
    }
}