class Solution {
    public String longestCommonPrefix(String[] strs) {
        if(strs.length==0) {return "";}
        
        String pres = strs[0];
        
        for(int i = 1; i < strs.length; ++i) {
            while(strs[i].indexOf(pres)!=0) {
                pres = pres.substring(0,pres.length()-1);
            }
            if(pres=="") {return "";}
        }
        
        return pres;
    }
}