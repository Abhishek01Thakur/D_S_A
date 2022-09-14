We are given an array asteroids of integers representing asteroids in a row.
For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left).
Each asteroid moves at the same speed.
Find out the state of the asteroids after all collisions.
If two asteroids meet, the smaller one will explode. 
If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.

Example 1:
Input: asteroids = [5,10,-5]
Output: [5,10]
Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.

Example 2:
Input: asteroids = [8,-8]
Output: []
Explanation: The 8 and -8 collide exploding each other.

Example 3:
Input: asteroids = [10,2,-5]
Output: [10]
Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.
  
  
  
 

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        int i=0;
        vector<int> ans;
        while(i < asteroids.size() && asteroids[i]<0){
            ans.push_back(asteroids[i]);
            i++;
        }
        
        if(i==asteroids.size()){
            return ans;
        }
        
        stack<int> s;
        
        while(i < asteroids.size()){
            
            if(asteroids[i] > 0){
                s.push(asteroids[i]);
            }
            else{
                
                while(!s.empty() && abs(asteroids[i]) > s.top()){
                    s.pop();
                }
                
                if(s.empty()){  //negative wala jinda raha
                    ans.push_back(asteroids[i]);
                }
                else if(s.top() == abs(asteroids[i])){  //dono barabar hai size mein
                    s.pop();
                }  
            }
            
            i++;
        }
        
        if(s.empty()){
            return ans;
        }
        
        //vector<int> temp;
        int k=ans.size();
        
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }

        reverse(ans.begin()+k,ans.end());
        
        // for(auto x:temp){
        //     ans.push_back(x);
        // }
        
        return ans;
        
    }
};
