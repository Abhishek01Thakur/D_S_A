/*
Given a sentence text (A sentence is a string of space-separated words) in the following format:

First letter is in upper case.
Each word in text are separated by a single space.
Your task is to rearrange the words in text such that all words are rearranged in an increasing order of their lengths. 
If two words have the same length, arrange them in their original order.

Return the new text following the format shown above.

 

Example 1:

Input: text = "Leetcode is cool"
Output: "Is cool leetcode"
Explanation: There are 3 words, "Leetcode" of length 8, "is" of length 2 and "cool" of length 4.
Output is ordered by length and the new first word starts with capital letter.

Example 2:
Input: text = "Keep calm and code on"
Output: "On and keep calm code"
Explanation: Output is ordered as follows:
"On" 2 letters.
"and" 3 letters.
"keep" 4 letters in case of tie order by position in original text.
"calm" 4 letters.
"code" 4 letters.

Example 3:
Input: text = "To be or not to be"
Output: "To be or to be not"

*/

class Solution {
public:
    string arrangeWords(string text) {
        
        
        struct cmp{
            
            bool operator()(pair<pair<int,int>,string> const &a,pair<pair<int,int>,string> const &b)
            {
                if(a.first.first == b.first.first){
                    
                    if(a.first.second < b.first.second)
                        return false;
                    else
                        return true;
                    
                }
                else if(a.first.first < b.first.first)
                    return false;
                else 
                    return true;
            }
            
        };
        
        priority_queue<pair<pair<int,int>,string> ,vector<pair<pair<int,int>,string>>,cmp> pq;
        int count=0,i;
        text[0]=text[0]-'A'+'a';
        for(i=0;i<text.size();i++){
            
            string s="";
            while(i<text.size() && text[i]!=' ')
            {
                s+=text[i];
                i++;
            }
            // if(s[0]>='a' && s[0]<='z')
            // s[0]=s[0]-'a'+'A';
            
            int n=s.size();
            
            pq.push({{n,count},s});
            
            count++;
        }
        
        string k="";
        bool f=true;
        while(!pq.empty()){
            string temp=pq.top().second;
            pq.pop();
            k+=temp+' ';
        }
        k[0]=k[0]-'a'+'A';
        k.pop_back();
        return k;
        
        
    }
};


