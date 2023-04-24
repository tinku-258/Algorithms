 void inorder(TreeNode* root,vector<int>& ans){
        if(root){
            inorder(root->left,ans);
            ans.push_back(root->val);
            inorder(root->right,ans);
        }
   }

---------ITERATIVE-------------------------------------------------------------------------------------
  
vector<int> inorder(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> ans;
        
        while(root|| !st.empty()){
           if(root){
               st.push(root);
               root=root->left;
           }
            else{
                root=st.top();
                st.pop();
                ans.push_back(root->val);
                root=root->right;
            }  
        }
         return ans;     
    }
