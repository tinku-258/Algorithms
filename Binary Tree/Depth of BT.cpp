 int maxDepth(TreeNode* root) {
        if(root){
            int l=maxDepth(root->left);
            int r=maxDepth(root->right);
            return 1+max(l,r);
        }
        return 0;
 }


---------------ITERATIVE---------------------------------------------------------------------
 
int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
         queue<TreeNode*> q;
         q.push(root);
         int ans=0;
         while(!q.empty()){
             int s=q.size();
             while(s--){
                 TreeNode* node=q.front();
                 q.pop();

                 if(node->left){
                     q.push(node->left);
                 }
                 if(node->right){
                     q.push(node->right);
                 }
             }
             ans++;
         }
         return ans;
}
