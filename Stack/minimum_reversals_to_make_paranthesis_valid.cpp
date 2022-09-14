Input:  exp = "}{"
Output: 2
We need to change '}' to '{' and '{' to
'}' so that the expression becomes balanced, 
the balanced expression is '{}'

Input:  exp = "{{{"
Output: Can't be made balanced using reversals

Input:  exp = "{{{{"
Output: 2 

Input:  exp = "{{{{}}"
Output: 1 

Input:  exp = "}{{}}{{{"
Output: 3


int countRev (string s)
{
    // your code here
    if(s.size() & 1) return -1;
    
    
    stack<int> st;
    
    for(auto ch : s){
        
        if(ch == '{'){
            st.push(ch);
        }
        else if(st.size() == 0 || st.top() == '}'){
            st.push(ch);
        }
        else
            st.pop();
    }
    
    int open =0 ,close =0;
    while(!st.empty()){
        if(st.top() == '{')
        open++;
        else
        close++;
        
        st.pop();
    }
    
    return (open+1)/ 2 + (close+1)/2; 
    
}
