class Solution {
    public List<String> stringMatching(String[] words) {

        int numOfStrings = words.length;
        Set<String> results = new HashSet<>();
        for(int i=0;i<numOfStrings;i++){
            for(int j=i+1;j<numOfStrings;j++){
                String a = words[i];
                String b = words[j];
                if(a.length() < b.length()){
                    int index = b.indexOf(a);
                    if(index!=-1){
                        results.add(a);
                    }
                }else{
                    int index = a.indexOf(b);
                    if(index!=-1){
                        results.add(b);
                    }

                }
            }
        }

        return new ArrayList(results);
        
    }
}