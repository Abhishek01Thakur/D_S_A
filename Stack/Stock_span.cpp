
 int* span(int arr[],int n){
  
     int res[n];
     stack<int> s;

     res[0]=1;
     s.push(0);   //pushed indices in the stack
                  // APPROACH used of next greater element on left
     for(int i=1; i < n ; i++){

         while(!s.empty() && arr[i] > arr[st.top()]){
              s.pop();
         }

         if(s.empty()) res[i] = i+1;
         else{
            res[i] = i -  s.top();
         }

         s.push(i);
     }
      int *p=res;

      return p;
  
}
