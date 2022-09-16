
//same questtion can be asked where the priority of alphabets will be changed according to a string with all 26 alphabets ngaro mein pucha tha aisa.
// in that case we can use the map to stire the prioriy aur jaha par bhi comparison honge waha par m[priority[i]] se check kar lenge


void lexicographicallySmallestSubsequence(string &s, int k)
{
    // Storing the length of the string.
    int n = s.length();
 
    // Initialising a variable to store the lexicographically smallest substring.
    stack<char> ans;
 
    // Traversing the string.
    for (int i = 0; i < n; i++)
    {
        // In case the stack is empty.
        if (ans.empty())
        {
            ans.push(s[i]);
        }
        else
        {
            // Iterating till the current character is less than the character at the top of the stack and checking if at least K characters remain in the rest of the string.
            while ((!ans.empty()) && (s[i] < ans.top()) &&  n-(i+1) >= k-ans.size() )    //required ->k-ans.size()  //remaining -> n-(i+1) in arry jinse choose kar skte
            {
                ans.pop();
            }
 
            // If the size of the stack is less than k, the character is pushed into it.
            if (ans.empty() || ans.size() < k)
            {
                ans.push(s[i]);
            }
        }
    }
 
    // Declaring a variable to store the final result.
    string result;
 
    // Iterating till the stack becomes empty.
    while (!ans.empty())
    {
        result.push_back(ans.top());
        ans.pop();
    }
 
    // Reversing the string and printing it.
    reverse(result.begin(), result.end());
    cout << result;
}
