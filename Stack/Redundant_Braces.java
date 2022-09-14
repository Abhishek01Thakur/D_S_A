Given a string A denoting an expression. It contains the following operators '+', '-', '*', '/'.

Chech whether A has redundant braces or not.

NOTE: A will be always a valid expression.
  
  

public class Solution {
    public int braces(String s) {
        Stack<Character> st = new Stack<>();
      
        for(int i = 0; i < s.length(); i++){
            char ch = s.charAt(i);
            if("(+-*/".indexOf(ch) != -1){
                st.push(ch);
            } else if(ch == ')') {
               if(st.peek() == '('){
                   return 1;
               } else {
                   while(st.peek() != '('){  //as question says string is balanced
                       st.pop();
                   }
                   st.pop();
               }
            }
        }
        
        return 0;
    }
}
