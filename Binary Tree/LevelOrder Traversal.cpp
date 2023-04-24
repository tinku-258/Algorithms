
  vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL) return {};
         vector<vector<int>> ans;
         queue<TreeNode*> q;
         q.push(root);
          
         while(!q.empty()){
              int s=q.size(),index=0;
             vector<int> level(s);
             while(s--){
                 TreeNode* node=q.front();
                 q.pop();
                 level[index++]=node->val;

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
  
