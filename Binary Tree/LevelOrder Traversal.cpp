
vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL) return {};

         vector<vector<int>> ans;
         queue<TreeNode*> q;
         q.push(root);

         while(!q.empty()){
             vector<int> level;
             int s=q.size();
             while(s--){
                 TreeNode* node=q.front();
                 q.pop();
                 level.push_back(node->val);

                 if(node->left){
                     q.push(node->left);
                 }

                 if(node->right){
                     q.push(node->right);
                 }
             }
             ans.push_back(level);
         }
         return ans;
 }

----------------RECUSRSIVE----------------------------------------------------------------------------------------
 
void levelOrder(TreeNode* root,vector<vector<int>>& ans,int level=0){
      if(root){
          if(ans.size()<=level){
             ans.push_back({root->val});
          }
          else{
            ans[level].push_back(root->val);
          }
        levelOrder(root->left,ans,level+1);
        levelOrder(root->right,ans,level+1);
      }
}
  
