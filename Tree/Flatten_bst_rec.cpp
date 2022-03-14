//try to visualize in mind 

void flatten(TreeNode *root, TreeNode *&prev)
    {
    if (root == NULL)
        return;
    flatten(root->right, prev);
    flatten(root->left, prev);
    root->right = prev;
    root->left = NULL;
    prev = root;
    }


    TreeNode *prev = NULL;
    flatten(root, prev);
