You are given a parentheses string s. In one move, you can insert a parenthesis at any position of the string.

For example, if s = "()))", you can insert an opening parenthesis to be "(()))" or a closing parenthesis to be "())))".
Return the minimum number of moves required to make s valid.

class Solution {
public:
    int minAddToMakeValid(string p) {
        stack<char> s;
        
        for(auto x :p){
            
            if(x == '('){
                s.push(x);
            }
            else if(s.size()==0){
                s.push(x);
            }
            else if(s.top() == ')'){
                s.push(x);
            }
            else{
                s.pop();
            }
        }
        
        return s.size();
    }
};
