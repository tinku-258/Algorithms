------------------------// INORDER MORRIS TRAVERSAL------------------------------------------

vector<int> InorMorris(TreeNode* root){
          vector<int> ans;
          TreeNode* curr=root;
          while(curr){
              if(curr->left==NULL){
                  ans.push_back(curr->val);
                  curr=curr->right;
              }
              else{
                 TreeNode* temp=curr->left;
                //  find inorder predecessor of curr
                 while(temp->right!=NULL&&temp->right!=curr){
                     temp=temp->right;
                 }

                 if(temp->right==NULL){
                     temp->right=curr; //create thread
                     curr=curr->left;
                 }
                 else if(temp->right==curr){ //inorder predecessor is already connected to curr
                     temp->right=NULL;  //so we must have traversed it previously(i.e left part is fully processed till now). so cut the thread
                     ans.push_back(curr->val);
                     curr=curr->right;
                 }
              }
          }
          return ans;
    }

------------------------// PREORDER MORRIS TRAVERSAL------------------------------------------
  
  vector<int> PreMorris(TreeNode* root){
          vector<int> ans;
          TreeNode* curr=root;
          while(curr){
              if(curr->left==NULL){
                  ans.push_back(curr->val);
                  curr=curr->right;
              }
              else{
                 TreeNode* temp=curr->left;
                //  find inorder predecessor of curr
                 while(temp->right!=NULL&&temp->right!=curr){
                     temp=temp->right;
                 }

                 if(temp->right==NULL){
                     temp->right=curr; //create thread
                     ans.push_back(curr->val);
                     curr=curr->left;
                 }
                 else if(temp->right==curr){ //inorder predecessor is already connected to curr
                     temp->right=NULL; //cut the thread
                     curr=curr->right;
                 }
              }
          }
          return ans;
    }
