 int maxDepth(TreeNode* root) {
        if(root){
            return 1+max(maxDepth(root->left),maxDepth(root->right));
        }
        return 0;
 }
