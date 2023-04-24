void preorder(TreeNode* root,vector<int>& ans){
      if(root){
          ans.push_back(root->val);
          preorder(root->left,ans);
          preorder(root->right,ans);
      }
}

-------ITERATIVE-----------------------------------------------
  
vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> ans;
        while(root||!st.empty()){
            if(root){
                ans.push_back(root->val);
                st.push(root->right);
                root=root->left;
            }
            else{
                root=st.top();
                st.pop();
            }
        }
        return ans;
}
