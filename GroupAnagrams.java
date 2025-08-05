public class GroupAnagrams {

    public List<List<String>> groupAnagrams(String[] strs) {
        HashMap<String,List<String>> map = new HashMap();
        List<List<String>> result = new ArrayList<>();
        for(String str: strs){
            char inputArray[] = str.toCharArray();
            Arrays.sort(inputArray);
            String newStr = new String(inputArray);
            map.computeIfAbsent(newStr, k -> new ArrayList<>()).add(str);
            // if(!map.containsKey(newStr)){
            //     List<String> list = new ArrayList<>();
            //     list.add(str);
            //     map.put(newStr, list);
            // }else{
            //    List<String> list =  map.get(newStr);
            //    if(list!=null){
            //     list.add(str);
            //    }
            // }
            
        }

        for(String key : map.keySet()){
              result.add(map.get(key));
        }

         return result;

    }

    
}
