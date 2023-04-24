
void postorder(TreeNode* root,vector<int>& ans){
      if(root){
          postorder(root->left,ans);
          postorder(root->right,ans);
          ans.push_back(root->val);
      }
}

-----------ITERATIVE-----------------------------------------------------
  
 vector<int> postorder(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode *last=NULL;
  
        while(root||!st.empty()){
            if(root){
                st.push(root);
                root=root->left;
            }
            else{
                root=st.top();
                if(root->right==NULL||root->right==last)
                {
                    ans.push_back(root->val);
                    last=root;
                    st.pop();
                    root=NULL;
                }
                else
                {
                    root=root->right;
                }
            }
        }
        return ans;
}
