 //if this function return -1,means BT is unbalanced otherwise it is balanced

 int isBalanced(TreeNode* root) {
        if(root){
            int l=isBalanced(root->left);
            if(l==-1) return -1;
            int r=isBalanced(root->right);
            if(r==-1) return -1;

            if(abs(l-r)>1) return -1;

            return 1+max(l,r);
        }
        return 0;
}
