
TreeNode* lca(TreeNode* root ,int val1 ,int val2 ){
        if(root==NULL||root->val==val1||root->val==val2) return root;

        TreeNode* l=lca(root->left,val1,val2);
        TreeNode* r=lca(root->right,val1,val2);

        if(l&&r) return root;
        return l?l:r;
 }
