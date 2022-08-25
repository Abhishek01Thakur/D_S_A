//search pattern GFG

class Solution
{
    
    ArrayList<Integer> search(String pat, String txt)
    {
        ArrayList<Integer> res = new ArrayList<>();
        
        int[] lps = getLPS(pat);
        
        int i = 0;
        int j = 0;
        while(i < txt.length()){
            if(txt.charAt(i) == pat.charAt(j)){
                i++;
                j++;
                
                if(j == pat.length()){
                    res.add(i - j + 1);
                    j = lps[j - 1];
                }
            } else if (j == 0){
                i++;
            } else {
                j = lps[j - 1];
            }
        }
        
        
        return res;
    }
    
    int[] getLPS(String pat){
        int[] lps = new int[pat.length()];
        
        int len = 0;
        int i = 1;
        while(i < pat.length()){
            if(pat.charAt(i) == pat.charAt(len)){
                lps[i] = len + 1;
                len++;
                i++;
            } else if(len == 0){
                lps[i] = 0;
                len = 0;
                i++;
            } else {
                len = lps[len - 1];
            }
        }
        
        return lps;
    }
}
