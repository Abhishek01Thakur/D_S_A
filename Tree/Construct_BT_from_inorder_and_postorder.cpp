struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

//Function to return a tree created from postorder and inoreder traversals.
void mapping(int in[], map<int,int> &nIdx,int n)
{
    for(int i=0;i<n;i++)
        nIdx[in[i]]=i;
}
Node* solve(int in[],int post[],int &index,int inStart,int inEnd,int n,map<int,int> &nIdx)
{
    if(index<0 || inStart>inEnd)
        return NULL;
    
    int ele = post[index--];
    Node *root = new Node(ele);
    int pos = nIdx[ele];
    
    //Rigth will be called first because in postorder we start from the end and the next element lies on thr right side of the inorder path given
    root->right= solve(in,post,index,pos+1,inEnd,n,nIdx);
    root->left= solve(in,post,index,inStart,pos-1,n,nIdx);
    
    return root;
    
}
Node *buildTree(int in[], int post[], int n) {
    // Your code here
    map<int,int> nIdx;
    mapping(in,nIdx,n);
    int postidx=n-1;
    Node *ans=solve(in ,post, postidx, 0,n-1,n,nIdx);
    return ans;
}
