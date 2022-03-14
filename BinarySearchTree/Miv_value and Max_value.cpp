Node *minvalue(Node *root){
  
  Node *temp=root;
  while(temp->left!=NULL)
    temp=temp->left;
  
  return temp;
}

Node *maxvalue(Node *root){
  
  Node *temp=root;
  while(temp->right!=NULL)
    temp=temp->right;
  
  return temp;
}
